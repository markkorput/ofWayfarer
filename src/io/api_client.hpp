#pragma once

#include "ofMain.h"
#include <singleton_macros.h>
#include "ofxHttpUtils.h"
#include "ofxJSON.h"

namespace wayfarer { namespace io {

    class ApiGeoData {
    public:
        float latitude, longitude;
        bool parseJson(ofxJSONElement json);
    };

    class ApiPage {
    public:
        string url;
        ApiGeoData geoData;
        vector<string> hrefs;
        bool parseJson(ofxJSONElement json);
    };
    
    class ApiSession {
    public:
        string url;
        vector<ApiPage> pages;
        bool parseJson(string jsonText);
        bool parseJson(ofxJSONElement json);
    };


    class ApiRoutes {
    public:
        ApiRoutes() : rootUrl(""){}
        void setup(string _rootUrl){ rootUrl = _rootUrl; }
        string getRootUrl(){ return rootUrl; }
        string url(string sub){
            return rootUrl + sub;
        }

        string randomSession(){
            return url("/session/random");
        }

    private:
        string rootUrl;
        
    };

    class ApiClient {

        SINGLETON_INLINE_HEADER_CODE(ApiClient);

    public:

         ApiClient();
        ~ApiClient(){ destroy(); }
        void setup(string rootUrl="");
        void destroy();
        void update();

    public: // operation methods

        void fetchSession();

    private: // callbacks
        
        void onNewResponse(ofxHttpResponse & response);

    public: // events

        ofEvent<shared_ptr<ApiSession>> sessionFetchedEvent;

    public: // params

        ofParameterGroup parameters;
        ofParameter<string> rootUrlParam;

    private: // attributes

        ApiRoutes routes;
        ofxHttpUtils httpUtils;
    };

}}
