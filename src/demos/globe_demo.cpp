#include "globe_demo.hpp"

using namespace wayfarer::demos;

SINGLETON_INLINE_IMPLEMENTATION_CODE(GlobeDemo);

#define GUI_PARAM(g,p,method) guiParamMap[g->method(p.getName(), p.get())]=&p

void GlobeDemo::setup(){
    globe.setup();

    // params
    parameters.setName("GlobeDemo");
    // parameters.add(renderMode.set("renderMode", globe.getRenderMode()));
    parameters.add(renderModeToggleParam.set("wireframe", globe.getRenderMode() == OF_MESH_WIREFRAME));
    parameters.add(modelFileNameParam.set("model file", globe.getModelFileName()));
    parameters.add(colorParam.set("color", globe.getColor()));

    // gui
    gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
    GUI_PARAM(gui,renderModeToggleParam,addToggle);
    vector<string> opts = {"globe.obj", "globeGreenAlpha.obj"};
    guiParamMap[gui->addDropdown(modelFileNameParam.getName(), opts)]=&modelFileNameParam;
    GUI_PARAM(gui,colorParam,addColorPicker);
    animsButton = gui->addButton("play animations");
    gui->expand();

    gui->onButtonEvent(this, &GlobeDemo::onGuiButton);
    gui->onToggleEvent(this, &GlobeDemo::onGuiToggle);
    gui->onTextInputEvent(this, &GlobeDemo::onGuiText);
    gui->onDropdownEvent(this, &GlobeDemo::onGuiDropdown);
    gui->onColorPickerEvent(this, &GlobeDemo::onGuiColorPicker);

    // event listeners
    renderModeToggleParam.addListener(this, &GlobeDemo::onRenderModeToggleChange);
    modelFileNameParam.addListener(this, &GlobeDemo::onModelFileNameChange);
    colorParam.addListener(this, &GlobeDemo::onColorChange);

    // apply all param values
    
    bool bTmp = renderModeToggleParam.get();
    ofLog() << "loaded render mode value: " << (bTmp ? "wireframe" : "faces");
    onRenderModeToggleChange(bTmp);
    ofColor clrTmp = colorParam.get();
    onColorChange(clrTmp);
}

void GlobeDemo::destroy(){
    renderModeToggleParam.removeListener(this, &GlobeDemo::onRenderModeToggleChange);
    modelFileNameParam.removeListener(this, &GlobeDemo::onModelFileNameChange);
    colorParam.removeListener(this, &GlobeDemo::onColorChange);

    if(gui){
        delete gui;
        gui = NULL;
    }
}

void GlobeDemo::update(){
    globe.update();
    gui->update();
}

void GlobeDemo::draw(){
    ofClear(0);

    cam.begin();
    globe.draw();
    cam.end();

    gui->draw();
}


void GlobeDemo::onRenderModeToggleChange(bool &wireframe){
    globe.setRenderMode(wireframe ? OF_MESH_WIREFRAME : OF_MESH_FILL); // support OF_MESH_POINTS?
}

void GlobeDemo::onModelFileNameChange(string &fileName){
    globe.setModelFileName(fileName);
}

void GlobeDemo::onColorChange(ofColor &color){
    globe.setColor(color);
}

void GlobeDemo::onGuiToggle(ofxDatGuiToggleEvent event){
    std::map<void*,ofAbstractParameter*>::iterator it = guiParamMap.find(event.target);
    if(it != guiParamMap.end()){
        ((ofParameter<bool>*)it->second)->set(event.target->getChecked());
    }
}

void GlobeDemo::onGuiText(ofxDatGuiTextInputEvent event){
    std::map<void*,ofAbstractParameter*>::iterator it = guiParamMap.find(event.target);
    if(it != guiParamMap.end()){
        ((ofParameter<string>*)it->second)->set(event.target->getText());
    }
}

void GlobeDemo::onGuiDropdown(ofxDatGuiDropdownEvent event){
    std::map<void*,ofAbstractParameter*>::iterator it = guiParamMap.find(event.target);
    if(it != guiParamMap.end()){
        ((ofParameter<string>*)it->second)->set(event.target->getLabel());
    }
}

void GlobeDemo::onGuiColorPicker(ofxDatGuiColorPickerEvent event){
    std::map<void*,ofAbstractParameter*>::iterator it = guiParamMap.find(event.target);
    if(it != guiParamMap.end()){
        ((ofParameter<ofColor>*)it->second)->set(event.target->getColor());
    }
}

void GlobeDemo::onGuiButton(ofxDatGuiButtonEvent event){
    if(event.target == animsButton){
        globe.playAnims();
    }
}
