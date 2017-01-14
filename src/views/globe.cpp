#include "globe.hpp"

using namespace wayfarer::views;

void Globe::setup(){
    ofLog() << "Globe::setup loading model form file: " << modelFileName;
    ofLog() << (model.loadModel(modelFileName) ? "done." : "failed.");
}

void Globe::update(float dt){
}

void Globe::draw(){
    ofSetColor(color);

    glPushMatrix();    
        // model.drawFaces();
        model.draw(renderMode);
    glPopMatrix();
}
