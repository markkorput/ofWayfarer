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
    
    if(pageAnim.isAnimating()){
        pageAnim.update(dt);
        globe->setLatitudeLongitude(pageAnim.getCurrentPosition());

        if(pageAnim.hasFinishedAnimating()){
            currentSessionPageIndex++;
            startSessionPage(currentSessionPageIndex);
        }
    }

    globe->update();
}

void GlobeController::rotateToLatitudeLongitude(const ofVec2f latLong){
    latlonAnim.animateTo(ofPoint(latLong));
}

void GlobeController::playSession(shared_ptr<io::ApiSession> session){
    currentSession = session;
    currentSessionPageIndex=0;
    ofLog() << "playing session with " << session->pages.size() << " pages";
    startSessionPage(currentSessionPageIndex);
}

void GlobeController::startSessionPage(int idx){
    if(currentSession->pages.size() <= idx){
        ofLog() << "session finished";
        return;
    }
    
    // get page
    io::ApiPage *page = &currentSession->pages[idx];
    ofLog() << "starting page: " << page->url;
    // start animation
    pageAnim.animateTo(ofPoint(page->geoData.latitude, page->geoData.longitude));
}
