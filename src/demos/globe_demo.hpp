#pragma once

#include "ofxDatGui.h"
#include <singleton_macros.h>
#include <views/globe.hpp>


namespace wayfarer { namespace demos {
   
    class GlobeDemo {
        SINGLETON_INLINE_HEADER_CODE(GlobeDemo)

    public:
        GlobeDemo() : gui(NULL){}
        ~GlobeDemo(){ destroy(); }
        void setup();
        void destroy();
        void update();
        void draw();
        
    private: // callbacks

        void onGuiToggle(ofxDatGuiToggleEvent event);
        void onGuiText(ofxDatGuiTextInputEvent event);
        void onGuiDropdown(ofxDatGuiDropdownEvent event);
        void onGuiColorPicker(ofxDatGuiColorPickerEvent event);
        
        void onRenderModeToggleChange(bool &wireframe);
        void onModelFileNameChange(string &fileName);
        void onColorChange(ofColor &color);

    private: // attributes

        views::Globe globe;
        
    private: // params

        ofParameterGroup parameters;
        // ofParameter<ofPolyRenderMode> renderMode;
        ofParameter<bool> renderModeToggleParam;
        ofParameter<string> modelFileNameParam;
        ofParameter<ofColor> colorParam;

    private: // gui
        
        ofxDatGui *gui;
        ofEasyCam cam;
        std::map<void*,ofAbstractParameter*> guiParamMap;
    };
    
} }
