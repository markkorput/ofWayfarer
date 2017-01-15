#pragma once

#include "ofxAnimatableOfPoint.h"
#include <singleton_macros.h>
#include <views/globe.hpp>
#include <io/api_client.hpp>

namespace wayfarer { namespace controllers {
   
    class GlobeController {

        SINGLETON_INLINE_HEADER_CODE(GlobeController);

    public: // commong interface methods
        
        GlobeController() : globe(NULL){}
        GlobeController(views::Globe *_globe) : globe(_globe){}
        ~GlobeController(){ destroy(); }

        void setup();
        void destroy();
        void update(float dt);
        
        void rotateToLatitudeLongitude(const ofVec2f latLong);
        void playSession(shared_ptr<io::ApiSession> session);
        void startSessionPage(int idx);

    public: // getters / setters
        
        views::Globe* getGlobe(){ return globe; }
        void setGlobe(views::Globe* _globe){ globe = _globe; }

    private: // attributes
        
        views::Globe *globe;
        views::Globe defaultGlobe;

        ofxAnimatableOfPoint latlonAnim,
                            pageAnim;
        shared_ptr<io::ApiSession> currentSession;
        int currentSessionPageIndex;
    };

} }

