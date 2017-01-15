#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

namespace wayfarer { namespace views {

    class Globe {

    public: // common interface methods

        Globe() : renderMode(OF_MESH_WIREFRAME),
                modelFileName("sphere.fbx"),
                continentsModelFileName("continents.fbx"),
                color(ofColor::white){}
        void setup();
        void update();
        void draw();
    
    public: // operations methods
        
        void playAnims(){ continents.playAllAnimations(); }

    public: // getters/setters

        ofPolyRenderMode getRenderMode(){ return renderMode; }
        void setRenderMode(ofPolyRenderMode newRenderMode){ renderMode = newRenderMode; }

        string getModelFileName(){ return modelFileName; }
        void setModelFileName(string newModelFileName, bool reload=true){ modelFileName = newModelFileName; setup(); }

        ofColor getColor(){ return color; }
        void setColor(const ofColor &clr){ color = clr; }

    private: // attributes

        ofxAssimpModelLoader sphere, continents;
        ofPolyRenderMode renderMode;
        string modelFileName, continentsModelFileName;
        ofColor color;
    };

} }
