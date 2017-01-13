#include "ofMain.h"
#include "ofApp.h"

#ifdef DEBUG
    #include "ofTestApp.h"
#endif

//========================================================================
int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

#ifdef DEBUG
    if(std::getenv("TEST")){
        ofSetupOpenGL(1024,768, OF_WINDOW);
        return ofRunApp(new ofTestApp());
    }
#endif

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
