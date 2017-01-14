#include "globe.hpp"

using namespace wayfarer::views;

void Globe::setup(){
    ofLog() << "loading model file: " << modelFileName;
    if(sphere.loadModel(modelFileName)){
        ofLog() << "done; " << sphere.getMeshCount() << " mesh(es) loaded";
    } else {
        ofLogWarning() << "loading failed.";
    }

    ofLog() << "loading model file: " << continentsModelFileName;
    if(continents.loadModel(continentsModelFileName)){
        ofLog() << "done; " << continents.getMeshCount() << " mesh(es) loaded";
    } else {
        ofLogWarning() << "loading failed.";
    }
    
    continents.playAllAnimations();
}

void Globe::update(){
    continents.update();
}

void Globe::draw(){
    ofSetColor(color);

    ofPushMatrix();
    continents.draw(renderMode);
    ofPopMatrix();
}
