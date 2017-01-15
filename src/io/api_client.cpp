#include "api_client.hpp"

using namespace wayfarer::io;

SINGLETON_INLINE_IMPLEMENTATION_CODE(ApiClient);

bool ApiGeoData::parseJson(ofxJSONElement json){
    if(!json["latitude"].isNull())
        this->latitude = json["latitude"].asFloat();

    if(!json["longitude"].isNull())
        this->longitude = json["longitude"].asFloat();
    
    return true;
}

bool ApiPage::parseJson(ofxJSONElement json){
    if(!json["url"].isNull())
        this->url = json["url"].asString();

    if(!json["hrefs"].isNull()){
        if(!json["hrefs"].isArray()){
            ofLogWarning() << "got non array values for hrefs";
            return false;
        }
        
        for(int i=0; i<json["hrefs"].size(); i++){
            this->hrefs.push_back(json["hrefs"][i].asString());
        }
    }

    if(!json["geo_data"].isNull()){
        return this->geoData.parseJson(json["geo_data"]);
    }

    return true;
}

bool ApiSession::parseJson(ofxJSONElement json){
    if(!json["url"].isNull())
        this->url = json["url"].asString();

    
    if(json["pages"].isNull()){
        return true;
    }

    if(!json["pages"].isArray()){
        ofLogWarning() << "got non array value for pages";
        return false;
    }
    
    for(int i = 0; i < json["pages"].size(); i++) {
        ApiPage page;
        if(!page.parseJson(json["pages"][i])){
            return false;
        }
        
        this->pages.push_back(page);
    }
    
    return true;
}

bool ApiSession::parseJson(string jsonText){
    ofxJSONElement json;

    if(!json.parse(jsonText)){
        ofLogWarning() << "ApiSession::parseJson failed to parse JSON: " << jsonText;
        return false;
    }
    
    return parseJson(json);
}


ApiClient::ApiClient(){
    parameters.setName("ApiClient");
    parameters.add(rootUrlParam.set("rootUrl", "http://localhost:8080"));
}

void ApiClient::setup(string rootUrl){
    routes.setup(rootUrl == "" ? rootUrlParam.get() : rootUrl);
    ofLog() << "routes configured with rootUrl: " << routes.getRootUrl();

    // callbacks
    ofAddListener(httpUtils.newResponseEvent, this, &ApiClient::onNewResponse);

    httpUtils.start();
}

void ApiClient::destroy(){
    // callbacks
    ofRemoveListener(httpUtils.newResponseEvent, this, &ApiClient::onNewResponse);
}

void ApiClient::update(){

}

void ApiClient::fetchSession(){
    ofLog() << "fetchSession: " << routes.randomSession();
    httpUtils.addUrl(routes.randomSession());
}

void ApiClient::onNewResponse(ofxHttpResponse & response){
    ofLog() << "onNewResponse: " << response.status;

    if(response.url == routes.randomSession()){
        if(response.status != 200){
            ofLogWarning() << "Got non " << response.status << " response for fetching random session: " << response.responseBody;
        }

        auto session = std::make_shared<ApiSession>();
        if(session->parseJson(response.responseBody)){
            ofNotifyEvent(sessionFetchedEvent, session);
        }
    }
    
}
