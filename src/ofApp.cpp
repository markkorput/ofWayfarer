#include "ofApp.h"

#include "demos/globe_demo.hpp"
#include "io/api_client.hpp"
#include "ofxGui.h"

using namespace wayfarer;

//--------------------------------------------------------------
void ofApp::setup(){
    ofLog() << "Redirect logging to log.txt";
    ofLogToFile("log.txt", true);

    {   // setup params
        params.setName("ofWayfarer");
        params.add(demos::GlobeDemo::singleton()->parameters);
        params.add(io::ApiClient::singleton()->parameters);
    }

    {   // load params
        ofxPanel gui;
        gui.setup(params);
        gui.loadFromFile("settings.xml");
        demos::GlobeDemo::singleton()->setup();
    }

    ofSetFrameRate(60);
    dt = 1.0f / ofGetFrameRate();
}

//--------------------------------------------------------------
void ofApp::update(){
    demos::GlobeDemo::singleton()->update(dt);
}

//--------------------------------------------------------------
void ofApp::draw(){
    demos::GlobeDemo::singleton()->draw();
}

//--------------------------------------------------------------
void ofApp::exit(ofEventArgs &args){

    {   // save params
        ofxPanel gui;
        gui.setup(params);
        gui.saveToFile("settings.xml");
    }

    demos::GlobeDemo::delete_singleton();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
