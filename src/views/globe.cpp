#include "globe.hpp"

using namespace wayfarer::views;

void Globe::setup(){
    model.loadModel(modelFileName);
}

void Globe::update(float dt){
}

void Globe::draw(){
    glPushMatrix();
        ofSetColor(255, 255, 255, 255);
        // model.drawFaces();
        model.draw(renderMode);
    glPopMatrix();
}
