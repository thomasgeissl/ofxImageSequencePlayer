#include "ofApp.h"

void ofApp::setup() {
    ofLogNotice() << "loaded sequence successfully " << _player.load(ofToDataPath("sequence"));
}

void ofApp::update() {
    _player.update();
}

void ofApp::draw() {
    _player.draw(0,0);
}

void ofApp::keyPressed(int key) {
    switch (key) {
        case 'n': {
            _player.nextFrame(); break;
        }
        case 'p': {
            _player.previousFrame(); break;
        }
    }
    ofLogNotice() << "current frame: " << _player.getCurrentFrame();
}