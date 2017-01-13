//
//  main.cpp
//  ofWayfarer
//
//  Created by Mark van de Korput on 17-01-13.
//
//

#include <stdio.h>

#include "ofMain.h"
#include "ofxUnitTests.h"

// ofAppNoWindow.h --> ofAppNoWindow
class ofTestApp : public ofxUnitTestsApp{
    void run();
};

void ofTestApp::run(){
    test_eq(2,3, "2 is 3?!");
}


//========================================================================
// main.cpp
//int main( ){
//    ofSetupOpenGL(1024,768, OF_WINDOW);
//    ofRunApp( new ofApp());
//}


