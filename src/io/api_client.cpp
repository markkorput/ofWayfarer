#include "api_client.hpp"

using namespace wayfarer::io;

SINGLETON_INLINE_IMPLEMENTATION_CODE(ApiClient);

void ApiClient::setup(string _rootUrl){
    rootUrl = _rootUrl;
}

void ApiClient::destroy(){
    
}

void ApiClient::update(){

}

void ApiClient::fetchSession(){
    
}
