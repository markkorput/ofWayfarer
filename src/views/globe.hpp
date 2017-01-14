#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

namespace wayfarer { namespace views {

    class Globe {

    public: // common interface methods

        Globe() : renderMode(OF_MESH_WIREFRAME), modelFileName("globe.obj"){}
        void setup();
        void update(float dt);
        void draw();

    public: // getters/setters

        ofPolyRenderMode getRenderMode(){ return renderMode; }
        void setRenderMode(ofPolyRenderMode newRenderMode){ renderMode = newRenderMode; }

        string getModelFileName(){ return modelFileName; }
        void setModelFileName(string newModelFileName, bool reload=true){ modelFileName = newModelFileName; setup(); }

    private: // attributes

        ofxAssimpModelLoader model;
        ofPolyRenderMode renderMode;
        string modelFileName;
    };

} }
