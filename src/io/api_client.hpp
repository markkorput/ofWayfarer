#pragma once

#include "ofMain.h"
#include <singleton_macros.h>

namespace wayfarer { namespace io {

    struct ApiGeoData {
        float latitude, longitude;
    };

    struct ApiPage {
        string url;
        ApiGeoData geoData;
        vector<string> hrefs;
    };
    
    struct ApiSession {
        string url;
        vector<ApiPage> pages;
    };
    

    class ApiClient {

        SINGLETON_INLINE_HEADER_CODE(ApiClient);

    public:

        ApiClient() : rootUrl(""){}
        ~ApiClient(){ destroy(); }
        void setup(string rootUrl);
        void destroy();
        void update();

    public: // operation methods

        void fetchSession();

    public: // events

        ofEvent<ApiSession> sessionFetchedEvent;
        
    private: // attributes
        
        string rootUrl;
        
    };

}}
