#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // STEP 2: initialize variables
    
    // set initial circle radius:
    mCircleRadius = 30;
    
    // set initial circle position:
    mPos = ofVec2f(ofGetWindowWidth() * 0.5, ofGetWindowHeight() * 0.5);
    
    // set friction:
    mFriction = 0.99;
    
    // no velocity at beginning:
    mVelocity = ofVec2f(0);
    
    // no force at beginning:
    mAcceleration = ofVec2f(0);
    
    // change background color
    ofSetBackgroundColor(ofColor(0));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // STEP 4: update physics in every frame
    
    // reduce velocity according to friction
    if (mVelocity.length() > 0) {
        mVelocity *= ofVec2f(mFriction);
        
        // when velocity is too small, stop updating it.
        if (mVelocity.length() < MIN_VELOCITY) {
            mVelocity = ofVec2f(0);
        }
    }
    
    // update position according to velocity
    if (mVelocity.length() > 0) {
        
        mPos += mVelocity;
        
        // circle size represents velocity
        mCircleRadius = 30 + mVelocity.length() * 30;
    
        // STEP 6: bring back our circle when it is off stage
        
        if (mPos.x < 0) mPos.x = ofGetWindowWidth();
        if (mPos.y < 0) mPos.y = ofGetWindowHeight();
        if (mPos.x > ofGetWindowWidth()) mPos.x = 0;
        if (mPos.y > ofGetWindowHeight()) mPos.y = 0;
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    // STEP 0: draw static circle
//    // (Just for initial playing. Comment out this part afterwards.)
//    ofSetColor(255, 0, 0);
//    ofSetCircleResolution(50);
//    ofDrawCircle(ofVec2f(512, 384), 50);
    
    // STEP 5: draw updated circle in every frame
    
    // draw circle:
    ofSetColor(255, 0, 0);
    ofSetCircleResolution(50);
    ofDrawCircle(mPos, mCircleRadius);
    
    // drawing a string using default font, for custom font use ofTrueTypeFont
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("x: " + ofToString(mPos.x) + "   y:" + ofToString(mPos.y), mPos + ofVec2f(40, -20));
    
    // print stuff to console
    cout << mPos << endl;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // STEP 3: apply a force to the circle when mouse pressed
    
    // put mouse position into a vector (local variable)
    ofVec2f mousePos = ofVec2f(x, y);
    
    // calculate acceleration
    mAcceleration = mPos - mousePos;
        // mAcceleration points from mousePos to mPos.
    
    // normalize acceleration
    mAcceleration = mAcceleration.getNormalized();
        // normalizing a vector keeps its direction but makes its length to 1.
        // We only use the direction of the acceleration, and always apply the same amount of acceleration (1) to the velocity.
    
    // apply the acceleration to velocity/speed
    mVelocity += mAcceleration;
    
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
