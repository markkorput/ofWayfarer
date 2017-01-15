#pragma once

#include "ofMain.h"
#include <singleton_macros.h>
#include "ofxHttpUtils.h"

namespace wayfarer { namespace io {

    struct ApiGeoData {
        float latitude, longitude;
    };

    struct ApiPage {
        string url;
        ApiGeoData geoData;
        vector<string> hrefs;
    };
    
    class ApiSession {
    public:
        string url;
        vector<ApiPage> pages;
        bool parseJson(string jsonText);
    };
    
    class ApiRoutes {
    public:
        ApiRoutes() : rootUrl(""){}
        void setup(string _rootUrl){ rootUrl = _rootUrl; }

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

        // ApiClient();
        ~ApiClient(){ destroy(); }
        void setup(string rootUrl);
        void destroy();
        void update();

    public: // operation methods

        void fetchSession();

    private: // callbacks
        
        void onNewResponse(ofxHttpResponse & response);

    public: // events

        ofEvent<ApiSession> sessionFetchedEvent;
        
    private: // attributes
        
        ApiRoutes routes;
        ofxHttpUtils httpUtils;
        
    };

}}
