#pragma once

#include "ofMain.h"
#include "Astronaut.hpp"
#include "StarSky.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void saveButtonPressed();

    
    int upperEdge = 0;
    int lowerEdge = 768;
    
    int count = 0;
    
    
    vector<Astronaut> astros;
    ofFbo f;

    StarSky stars;
    
    ofVideoGrabber grabber;
    ofVideoGrabber vidGrabber;
    ofBaseVideoDraws * trackVideo;

    ofxPanel gui;
    ofxVec2Slider pos;
    ofxVec2Slider size;
    ofxFloatSlider rot;
    ofxButton saveBtn;
    
    ofxVec2Slider spos;
    ofxVec2Slider ssize;
    ofxVec2Slider vpos;
    ofxVec2Slider vsize;
    ofxVec2Slider v2pos;
    ofxVec2Slider v2size;

    bool showUI = false;
    bool showCam = false;
    
    ofImage overlay;

};
