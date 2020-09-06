#pragma once

#include "ofMain.h"
#include "ofxImageSequencePlayer.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyPressed(int key);
	
	ofxImageSequencePlayer _player;
};
