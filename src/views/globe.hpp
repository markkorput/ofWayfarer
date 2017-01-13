#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

namespace wayfarer { namespace views {

    class Globe {

    public:
        void setup();
        void update(float dt);
        void draw();

    private: // attributes
        ofxAssimpModelLoader model;

    };

} }
