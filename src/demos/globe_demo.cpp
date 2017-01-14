#include "globe_demo.hpp"

using namespace wayfarer::demos;

SINGLETON_INLINE_IMPLEMENTATION_CODE(GlobeDemo);

void GlobeDemo::setup(){
    globe.setup();

    // params
    parameters.setName("GlobeDemo");
    // parameters.add(renderMode.set("renderMode", globe.getRenderMode()));
    parameters.add(renderModeToggleParam.set("wireframe", globe.getRenderMode() == OF_MESH_WIREFRAME));
    parameters.add(modelFileNameParam.set("model file", globe.getModelFileName()));
    gui.setup(parameters);
    
    // event listeners
    renderModeToggleParam.addListener(this, &GlobeDemo::onRenderModeToggleChange);
    modelFileNameParam.addListener(this, &GlobeDemo::onModelFileNameChange);
}

void GlobeDemo::destroy(){
    renderModeToggleParam.removeListener(this, &GlobeDemo::onRenderModeToggleChange);
    modelFileNameParam.removeListener(this, &GlobeDemo::onModelFileNameChange);
}

void GlobeDemo::draw(){
    cam.begin();
    globe.draw();
    cam.end();

    gui.draw();
}


void GlobeDemo::onRenderModeToggleChange(bool &wireframe){
    globe.setRenderMode(wireframe ? OF_MESH_WIREFRAME : OF_MESH_FILL); // support OF_MESH_POINTS?
}

void GlobeDemo::onModelFileNameChange(string &fileName){
    globe.setModelFileName(fileName);
}
