#pragma once

#include "ofxGui.h"
#include <singleton_macros.h>
#include <views/globe.hpp>


namespace wayfarer { namespace demos {
   
    class GlobeDemo {
        SINGLETON_INLINE_HEADER_CODE(GlobeDemo)

    public:
        ~GlobeDemo(){ destroy(); }
        void setup();
        void destroy();

        void draw();
        
    private: // callbacks

        void onRenderModeToggleChange(bool &wireframe);
        void onModelFileNameChange(string &fileName);

    private: // attributes

        views::Globe globe;
        
    private: // params

        ofParameterGroup parameters;
        // ofParameter<ofPolyRenderMode> renderMode;
        ofParameter<bool> renderModeToggleParam;
        ofParameter<string> modelFileNameParam;

    private: // gui
        
        ofxPanel gui;
        ofEasyCam cam;
    };
    
} }
