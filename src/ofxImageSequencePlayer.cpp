#include "ofxImageSequencePlayer.h"
ofxImageSequencePlayer::ofxImageSequencePlayer(): _currentFrame(-1), _loopState(OF_LOOP_NORMAL){}
void ofxImageSequencePlayer::setup(){}
void ofxImageSequencePlayer::update(){
	if (_currentFrame >= 0 && _currentFrame < _frames.size()) {
		_currentTexture.loadData(_frames[_currentFrame]);
	}
}
void ofxImageSequencePlayer::draw(float x, float y) {
	if (_currentTexture.isAllocated()) {
		_currentTexture.draw(x, y);
	}
}
void ofxImageSequencePlayer::draw(int x, int y, int width, int height){
    if(_currentTexture.isAllocated()){
        _currentTexture.draw(x, y, width, height);
    }
}
bool ofxImageSequencePlayer::load(std::string path) {
	ofLogVerbose("ofxImageSequencePlayer") << "loading sequence: " << path;
    if(ofDirectory::doesDirectoryExist(path)){
		_frames.clear();
        ofDirectory dir(path);
        dir.listDir();
        dir = dir.getSorted();
        auto frames = dir.getFiles();
        for(auto & frame : dir.getFiles()){
            //ofLogNotice() << frame.getFileName();
            //ofImage img(frame.getAbsolutePath());
			//_frames.push_back(img);

			ofPixels pix;
			ofLoadImage(pix, frame.getAbsolutePath());
			_frames.push_back(pix);

        }
        _currentFrame = 0;
        return true;
    }else{
        return false;
    }
//    ofLogNotice() << "loaded frames: " << _frames.size();
}
void ofxImageSequencePlayer::loadAsync(std::string path) {
	ofLogWarning("ofxImageSequencePlayer::loadAsync") << "not yet implemented";
}
void ofxImageSequencePlayer::close() {

}
void ofxImageSequencePlayer::play(){}
void ofxImageSequencePlayer::stop(){}
bool ofxImageSequencePlayer::isFrameNew() const {
	return true;
}
bool ofxImageSequencePlayer::isVideoDone() const {
	return false;
}


void ofxImageSequencePlayer::setPaused(bool value){}
void ofxImageSequencePlayer::setLoopState(ofLoopType loopState){
    _loopState = loopState;
}
ofLoopType ofxImageSequencePlayer::getLoopState(){
    return _loopState;
}


float ofxImageSequencePlayer::getWidth() const {
	return _frames.size() > 0 ? _frames[0].getWidth() : 0;
}
float ofxImageSequencePlayer::getHeight() const {
	return _frames.size() > 0 ? _frames[0].getHeight() : 0;
};

bool ofxImageSequencePlayer::isPaused() const { return false; };
bool ofxImageSequencePlayer::isLoaded() const { return true; };
bool ofxImageSequencePlayer::isPlaying() const { return true; };

int ofxImageSequencePlayer::getTotalNumFrames(){
    return _frames.size();
}
int ofxImageSequencePlayer::getCurrentFrame(){
    return _currentFrame;
}
float ofxImageSequencePlayer::getPosition(){
	if (_frames.size() == 0) return 0;
    return (float)(_currentFrame)/_frames.size();
}
void ofxImageSequencePlayer::firstFrame(){
    _currentFrame = 0;
}
void ofxImageSequencePlayer::setFrame(int frame){
    _currentFrame = std::min((int)(_frames.size()), frame);
}
void ofxImageSequencePlayer::previousFrame(){
    _currentFrame = std::max(0, _currentFrame-1);
}
void ofxImageSequencePlayer::nextFrame(){
    _currentFrame = std::min((int)(_frames.size()-1), _currentFrame+1);
}
float ofxImageSequencePlayer::getVolume() const {
	return 0;
}

void ofxImageSequencePlayer::setVolume(float volume) {
	ofLogWarning("ofxImageSequencePlayer::setVolume") << "has no effect, there is no support for audio";
}
float ofxImageSequencePlayer::getSpeed() const {
	return 1;
}

void ofxImageSequencePlayer::setSpeed(float speed) {
	ofLogWarning("ofxImageSequencePlayer::setSpeed") << "has no effect, there is no support for speed, not yet";


}

ofPixels & ofxImageSequencePlayer::getPixels() {
	if (!isFrameValid(_currentFrame)) {
		auto pix = ofPixels();
		return pix;
	}
	return _frames[_currentFrame];
}
const ofPixels& ofxImageSequencePlayer::getPixels() const {
	if (!(_currentFrame >= 0 && _currentFrame < _frames.size())) {
		return ofPixels();
	}
	return _frames[_currentFrame];
}

ofPixelFormat ofxImageSequencePlayer::getPixelFormat() const {
	return _frames.size() > 0 ? _frames[0].getPixelFormat() : OF_PIXELS_UNKNOWN;
}
