#include "api_client.hpp"

using namespace wayfarer::io;

SINGLETON_INLINE_IMPLEMENTATION_CODE(ApiClient);

bool ApiSession::parseJson(string jsonText){

    return false;
}

void ApiClient::setup(string rootUrl){
    routes.setup(rootUrl);
    
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
    httpUtils.addUrl(routes.randomSession());
}

void ApiClient::onNewResponse(ofxHttpResponse & response){
    if(response.url == routes.randomSession()){
        if(response.status != 200){
            ofLogWarning() << "Got non 200 response for fetching random session: " << response.responseBody;
        }
        ApiSession apiSession;
        if(apiSession.parseJson(response.responseBody)){
            ofNotifyEvent(sessionFetchedEvent, apiSession);
            return;
        }
        
        ofLogWarning() << "failed to parse session json";
    }
    
}
