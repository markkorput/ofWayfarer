#ifdef DEBUG

#include "ofTestApp.h"

void ofTestApp::testApiClient(){
    client.setup("http://127.0.0.1:8081/wayfarer/api/v1");
    ofAddListener(client.sessionFetchedEvent, this, &ofTestApp::onSessionFetched);
    client.fetchSession();
    // test_eq(client.isActive(), true, "client tells if its active"));
    // waitForAsync();
}

void ofTestApp::onSessionFetched(shared_ptr<wayfarer::io::ApiSession> &session){
    test_eq(session->url, "http://...", "");
    test_eq(session->pages.size(), 5, "");
    
    wayfarer::io::ApiPage page = session->pages[0];
    test_eq(page.url, "http://...", "");
    test_eq(page.geoData.latitude, 29.8f, "");
    test_eq(page.geoData.longitude, -15.6f, "");
    test_eq(page.hrefs.size(), 10, "");
    test_eq(page.hrefs[0], "http://...", "");
    test_eq(page.hrefs[1], "http://...", "");
    // asyncDone();
}

void ofTestApp::run(){
    testApiClient();
}

#endif // DEBUG
