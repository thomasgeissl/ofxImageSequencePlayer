#pragma once
#include "ofMain.h"

class ofxImageSequencePlayer : public ofBaseVideoPlayer{
public:
    ofxImageSequencePlayer();
	void setup();
	void update();
	void draw(float x, float y);
	void draw(int x, int y, int width, int height);
	bool load(std::string path);
	void loadAsync(std::string path);
	void close();

    
	void play();
	void stop();

	bool isFrameNew() const;
	bool isVideoDone() const;
	ofPixels& getPixels();
	const ofPixels& getPixels() const;


    void setPaused(bool value);
    void setLoopState(ofLoopType loopState);
    ofLoopType getLoopState();

	float getWidth() const;
	float getHeight() const;

	bool isPaused() const;
	bool isLoaded() const;
	bool isPlaying() const;

    int getTotalNumFrames();
    int getCurrentFrame();
    float getPosition();
    
    void firstFrame();
    void setFrame(int frame);
    void previousFrame();
    void nextFrame();

	float getVolume() const;
	void setVolume(float volume);

	void setSpeed(float speed);
	float getSpeed() const;

	bool setPixelFormat(ofPixelFormat pixelFormat) { 
		ofLogWarning("ofxImageSequencePlayer::setPixelFormat") << "has no effect";
		return false; 
	};
	ofPixelFormat getPixelFormat() const;

    
	//std::vector<ofImage> _frames;
	std::vector<ofPixels> _frames;

    int _currentFrame;
	ofTexture _currentTexture;
    
    ofParameterGroup _parameters;
    ofParameter<int> _fps;
    
private:
	inline bool isFrameValid(const int frame) {
		return frame >= 0 && frame < _frames.size();
	}
    ofLoopType _loopState;
};
