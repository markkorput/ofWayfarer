#include "globe_controller.hpp"

using namespace wayfarer::controllers;

SINGLETON_INLINE_IMPLEMENTATION_CODE(GlobeController);

void GlobeController::setup(){
    if(!globe){
        globe = &defaultGlobe;
    }
}

void GlobeController::destroy(){
    globe = NULL;
}

void GlobeController::update(float dt){
    if(latlonAnim.isAnimating()){
        latlonAnim.update(dt);
        globe->setLatitudeLongitude(latlonAnim.getCurrentPosition());
    }

    globe->update();
}

void GlobeController::rotateToLatitudeLongitude(const ofVec2f latLong){
    latlonAnim.animateTo(ofPoint(latLong));
}

void GlobeController::playSession(shared_ptr<io::ApiSession> session){
    currentSession = session;
}
