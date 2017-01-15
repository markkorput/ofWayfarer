#pragma once

#include "ofMain.h"
#include "ofxUnitTests.h"
#include <io/api_client.hpp>

class ofTestApp : public ofxUnitTestsApp{
public:
    void run();

private:
    wayfarer::io::ApiClient client;
    void testApiClient();
    void onSessionFetched(wayfarer::io::ApiSession &session);
};
