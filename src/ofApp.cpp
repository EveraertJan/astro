#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i < 20; i++) {
        Astronaut a;
        a.setup("astro_test.png");
        astros.push_back(a);
    }
    
    ofSetFrameRate(12);
    
    overlay.load("astro_overlay.png");

    f.allocate(ofGetWidth(), ofGetHeight());
    
    int camWidth = 320;  // try to grab at this size.
    int camHeight = 240;
    
    //get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    trackVideo = &vidGrabber;
    
    stars.setup();
    
    gui.setup();
    ofVec2f tpos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    ofVec2f tsize = ofVec2f(200, 200);
    ofVec2f stpos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    ofVec2f stsize = ofVec2f(200, 200);
    ofVec2f vtpos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    ofVec2f vtsize = ofVec2f(200, 200);
    gui.add(pos.setup("pos", tpos, ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(size.setup("size", tsize, ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(spos.setup("spos", stpos, ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(ssize.setup("ssize", stsize, ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(vpos.setup("vpos", vtpos, ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(vsize.setup("vsize", vtsize, ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(v2pos.setup("v2pos", vtpos, ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(v2size.setup("v2size", vtsize, ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(rot.setup("rotation", 0, 0, 360) );
    
    gui.add(saveBtn.setup("save"));
    saveBtn.addListener(this, &ofApp::saveButtonPressed);
    
    
    gui.loadFromFile("settings.xml");
}

void ofApp::saveButtonPressed() {
    gui.saveToFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    trackVideo->update();
    for(int i = 0; i < astros.size(); i++) {
        astros.at(i).update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    stars.draw();
    ofSetColor(255, 255, 255);
    ofImage back;
    back.load("logoBack.png");
    back.draw((ofGetWindowWidth() / 2) - 400, (ofGetWindowHeight() / 2) - 200, 800, 400);

    for(int i = 0; i < astros.size(); i++) {
        astros.at(i).draw();
    }
    ofImage front;
    front.load("logoFront.png");
    front.draw((ofGetWindowWidth() / 2) - 400, (ofGetWindowHeight() / 2) - 200, 800, 400);

    f.begin();
    ofClear(0);
    trackVideo->draw(0, 0, ofGetWidth(), ofGetHeight());
    f.end();
    if(showCam) {
        trackVideo->draw(0, 0, ofGetWidth(), ofGetHeight());
        ofPushStyle();
        ofSetColor(255, 255, 255, 255);
        ofNoFill();
        ofDrawRectangle(pos->x, pos->y, size->x, size->y);
        ofPopStyle();
        overlay.draw(pos->x, pos->y, size->x, size->y);

        
    }
    
    if(showUI) {
        gui.draw();
        f.draw(20, ofGetHeight() - 100, 100, 100);
        
    }
    ofPushStyle();
    ofSetColor(0, 0, 0);
    ofFill();
    ofDrawRectangle(spos->x, spos->y, ssize->x, ssize->y);
    ofDrawRectangle(vpos->x, vpos->y, vsize->x, vsize->y);
    ofDrawRectangle(v2pos->x, v2pos->y, v2size->x, v2size->y);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' ') {
        Astronaut a;
        ofPixels t;
        f.readToPixels(t);
        
        ofImage img;
        img.setFromPixels(t);
        img.crop(pos->x, pos->y, size->x, size->y);
        img.resize(a.width, a.height);
        string fileName = ofToDataPath("in/temp-"+ofGetTimestampString()+".png", true);

//        string fileName = "in/temp-" + ofToString(count) + ".png";
        img.save(fileName);
        
        count+=1;
        
        
        a.setup(fileName);
        astros.push_back(a);
    }
    else if(key == 'c') {
        showCam = !showCam;
    }
    else if(key == 'u') {
        showUI = !showUI;
    }
    else {

        Astronaut a;
        a.setup("astro_test.png");
        astros.push_back(a);
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
