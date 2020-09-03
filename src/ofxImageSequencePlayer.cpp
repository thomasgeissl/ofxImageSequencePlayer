#include "ofxImageSequencePlayer.h"
ofxImageSequencePlayer::ofxImageSequencePlayer(): _currentFrame(-1), _loopState(OF_LOOP_NORMAL){}
void ofxImageSequencePlayer::setup(){}
void ofxImageSequencePlayer::update(){
	if (_currentFrame >= 0 && _currentFrame < _frames.size()) {
		_currentTexture.loadData(_frames[_currentFrame]);
	}
}
void ofxImageSequencePlayer::draw(int x, int y, int width, int height){
    if(_currentTexture.isAllocated()){
        _currentTexture.draw(x, y, width, height);
    }
}
bool ofxImageSequencePlayer::load(std::string path) {
    if(ofDirectory::doesDirectoryExist(path)){
		_frames.clear();
        ofDirectory dir(path);
        dir.listDir();
        dir = dir.getSorted();
        auto frames = dir.getFiles();
        for(auto & frame : dir.getFiles()){
            ofLogNotice() << frame.getFileName();
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
void ofxImageSequencePlayer::play(){}
void ofxImageSequencePlayer::stop(){}
void ofxImageSequencePlayer::setPaused(bool value){}
void ofxImageSequencePlayer::setLoopState(ofLoopType loopState){
    _loopState = loopState;
}
ofLoopType ofxImageSequencePlayer::getLoopState(){
    return _loopState;
}

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
