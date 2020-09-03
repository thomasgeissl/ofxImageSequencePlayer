#pragma once
#include "ofMain.h"

class ofxImageSequencePlayer{ //: public ofBaseVideoPlayer{
public:
    ofxImageSequencePlayer();
	void setup();
	void update();
	void draw(int x, int y, int width, int height);
	bool load(std::string path);
    
    void play();
    void stop();
    void setPaused(bool value);
    void setLoopState(ofLoopType loopState);
    ofLoopType getLoopState();

    int getTotalNumFrames();
    int getCurrentFrame();
    float getPosition();
    
    void firstFrame();
    void setFrame(int frame);
    void previousFrame();
    void nextFrame();
    
	//std::vector<ofImage> _frames;
	std::vector<ofPixels> _frames;

    int _currentFrame;
	ofTexture _currentTexture;
    
    ofParameterGroup _parameters;
    ofParameter<int> _fps;
    
private:
    ofLoopType _loopState;
};
