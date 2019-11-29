//
//  Astronaut.cpp
//  astro_forever_whatever
//
//  Created by Jan Everaert on 01/11/2019.
//

#include "Astronaut.hpp"


void Astronaut::setup(string file) {
    posX = ofRandom(0, ofGetWindowWidth());
    posY = ofRandom(0, ofGetWindowHeight());
    rot = ofRandom(0, 360);
    fX = ofRandom(-2, 2);
    fY = ofRandom(-2, 2);
    
    fR = ofRandom(-2, 2);
    
    timeToLive = ofRandom(24 * 60 * 2, 24 * 60 * 10);
    
    astroboy.allocate(width, height);
    ofImage im;
    im.load(file);
    im.resize(width, height);
    in = im.getTexture();
    mask.load("astro_mask.png");
    overlay.load("astro_overlay.png");

    
}

void Astronaut::update() {
    posX = posX + fX;
    posY = posY + fY;
    rot = rot + fR;
    
    if(timeToLive >= 0) {
        timeToLive--;
    }
    if(posX > ofGetWindowWidth() + width) {
        posX = 0;
    }
    if(posY > ofGetWindowHeight() + height) {
        posX = 0;
    }
    if(posX < -width) {
        posX = ofGetWindowWidth();
    }
    if(posY < -height) {
        posY = ofGetWindowHeight();
    }
    
    
}

void Astronaut::draw() {
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(posX, posY);
    ofRotateDeg(rot);
    if(timeToLive < 0) {
        ofSetColor(150, 150, 150, 20);
    }
    else {
        ofSetColor(200, 200, 200, 255);
    }
    ofFill();
    ofTranslate(-width / 2, -height / 2);
    mask.resize(width, height);
    in.setAlphaMask(mask.getTexture());
    in.draw(0, 0, width, height);
    overlay.draw(0, 0, width, height);
    
    ofPopStyle();
    ofPopMatrix();
}
