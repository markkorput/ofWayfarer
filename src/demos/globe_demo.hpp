#pragma once

#include "ofxDatGui.h"
#include <singleton_macros.h>
#include <views/globe.hpp>
#include <controllers/globe_controller.hpp>
#include <io/api_client.hpp>

namespace wayfarer { namespace demos {
   
    class GlobeDemo {
        SINGLETON_INLINE_HEADER_CODE(GlobeDemo)

    public:
        GlobeDemo();
        ~GlobeDemo(){ destroy(); }
        void setup();
        void destroy();
        void update(float dt);
        void draw();
        
    private: // callbacks

        void onGuiButton(ofxDatGuiButtonEvent event);
        void onGuiToggle(ofxDatGuiToggleEvent event);
        void onGuiText(ofxDatGuiTextInputEvent event);
        void onGuiDropdown(ofxDatGuiDropdownEvent event);
        void onGuiColorPicker(ofxDatGuiColorPickerEvent event);
        
        void onRenderModeToggleChange(bool &wireframe);
        void onModelFileNameChange(string &fileName);
        void onColorChange(ofColor &color);
        
        void onSessionFetched(shared_ptr<io::ApiSession> &session);

    private: // attributes

        views::Globe globe;
        controllers::GlobeController controller;
        
    public: // params

        ofParameterGroup parameters;
        // ofParameter<ofPolyRenderMode> renderMode;
        ofParameter<bool> renderModeToggleParam;
        ofParameter<string> modelFileNameParam;
        ofParameter<ofColor> colorParam;

    private: // gui
        
        ofxDatGui *gui;
        ofxDatGuiButton *animsButton,
                        *randomLatLonButton,
                        *fetchSessionButton;
        ofEasyCam cam;
        std::map<void*,ofAbstractParameter*> guiParamMap;
    };
    
} }
