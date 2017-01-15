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

void Globe::setLatitudeLongitude(const ofVec2f &latlon){
    this->latlon2f = latlon;
    // setRotation(int which, float angle, float rot_x, float rot_y, float rot_z)
    continents.setRotation(0, latlon.x, 1.0f, 0.0f, 0.0f); // latitude; rotation around x-axis
    continents.setRotation(1, latlon.y, 0.0f, 1.0f, 0.0f); // longitude; rotation around y-axis
    
}
