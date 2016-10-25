#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // STEP 1 : declaring variables and constants
    
    // circle properties:
    float	mCircleRadius;
    
    // physics variables:
    ofVec2f mPos;
    ofVec2f mVelocity;
    ofVec2f mAcceleration;
    float	mFriction;
    
    // constants:
    const float MIN_VELOCITY = 0.01;
    
};
