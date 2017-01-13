#pragma once

#define FCOL_SINGLETON_INLINE_HEADER_CODE(x) \
    private:\
        static x* singleton; \
    public: \
        inline static x* singleton(){\
            if(!singleton){\
                ofLogVerbose() << "Creating singleton of class " << #x;\
                singleton = new x();\
            }\
            return singleton;\
        }\
        inline static void delete_singleton(){ \
            if(singleton){\
                ofLogVerbose() << "Deleting singleton of class " << #x;\
                delete singleton;\
                singleton = NULL;\
            }\
        }

#define FCOL_SINGLETON_INLINE_IMPLEMENTATION_CODE(x) \
    x* x::singleton = NULL;
