#pragma once

#define SINGLETON_INLINE_HEADER_CODE(x) \
    private:\
        static x* _singleton_instance; \
    public: \
        inline static x* singleton(){\
            if(!_singleton_instance){\
                ofLogVerbose() << "Creating singleton of class " << #x;\
                _singleton_instance = new x();\
            }\
            return _singleton_instance;\
        }\
        inline static void delete_singleton(){ \
            if(_singleton_instance){\
                ofLogVerbose() << "Deleting singleton of class " << #x;\
                delete _singleton_instance;\
                _singleton_instance = NULL;\
            }\
        }

#define SINGLETON_INLINE_IMPLEMENTATION_CODE(x) \
    x* x::_singleton_instance = NULL;
