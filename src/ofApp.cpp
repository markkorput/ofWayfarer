#include "ofApp.h"

#include "demos/globe_demo.hpp"


using namespace wayfarer;

//--------------------------------------------------------------
void ofApp::setup(){
    ofLog() << "Redirect logging to log.txt";
    ofLogToFile("log.txt", true);

    gui.setup(demos::GlobeDemo::singleton()->parameters);
    gui.loadFromFile("settings.xml");
    demos::GlobeDemo::singleton()->setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    demos::GlobeDemo::singleton()->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    demos::GlobeDemo::singleton()->draw();
}

//--------------------------------------------------------------
void ofApp::exit(ofEventArgs &args){
    {
        gui.setup(demos::GlobeDemo::singleton()->parameters);
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
