//
//  Star.cpp
//  astro_forever_whatever
//
//  Created by Jan Everaert on 01/11/2019.
//

#include "Star.hpp"

void Star::setup() {
    posX = ofRandom(0, ofGetWindowWidth());
    posY = ofRandom(0, ofGetWindowHeight());
    size = ofRandom(0.1, 1.5);
}
void Star::draw() {
    
    
    
    ofPushMatrix();
    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofFill();
    ofDrawCircle(posX, posY, size);
    ofPopStyle();
    ofPopMatrix();
}
