/*
 Project Title: glitchCulture
 Description: vhs glitch simulation and extrapoloation
 ©Daniel Buzzo 2021
 dan@buzzo.com
 http://buzzo.com
 https://github.com/danbz
 http://youtube.com/danbuzzo
 */


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    vStepRange = 200;
    ofSetBackgroundColor( 0 );
    ofSetFrameRate(24);
    // gui controls and setup
    b_Gui = true;
    gui.setDefaultWidth(250);
    gui.setDefaultTextPadding(4);
    gui.setName("glitchVHS");
    gui.setup();

    gui.add(blackAmount.setup("blackAmount", 3, 1, 10));
    gui.add(blackAmountJitter.setup("black jitter", false));
    gui.add(blackAmountJitterSpeed.setup("jitter speed", 100, 10, 1000)); //jitter change delay in ms
    
    gui.add(numPasses.setup("numPasses", 3, 1, 20));
    gui.add(numPassesJitter.setup("passes jitter", false));
    gui.add(numPassesJitterSpeed.setup("jitter speed", 100, 10, 1000)); //passes change delay in ms
    
    gui.add(hStripeHeightRange.setup("hStripeHeightRange", 50, 1, 200));
    gui.add(hStripeHeightJitter.setup("hStripe jitter", false));
    gui.add(hStripeHeightJitterSpeed.setup("jitter speed", 100, 10, 1000)); //height change delay in ms
    
    gui.add(hStepRange.setup("hStepRange", 10, 1, 100));
    gui.add(hStepRangeJitter.setup("hStep jitter", false));
    gui.add(hStepRangeJitterspeed.setup("jitter speed", 100, 10, 1000)); //hStep change delay in ms

    gui.add(sparkColorPercent.setup("sparkColor %", 1, 99, 1));
    gui.add(sparkColor.setup("colour sparks", false));
    gui.add(sparkColorJitter.setup("colour sparks Jitter", false));

    gui.add(sparkColorJitterSpeed.setup("spark % speed", 100, 10, 1000)); //colour spakr percent change delay in ms

    gui.add(frameRateJitter.setup("framerate Jitter", false));

    // setup timers
    blackJitterTimer = ofGetSystemTimeMillis();
    passesJitterTimer = ofGetSystemTimeMillis();
    hStripeHeightTimer = ofGetSystemTimeMillis();
    hStepRangeTimer = ofGetSystemTimeMillis();
    sparkColorTimer = ofGetSystemTimeMillis();


    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (frameRateJitter){
        ofSetFrameRate(ofRandom(5,30)); // randomise the framerate each frame
    } else {
        ofSetFrameRate(24);
    }
    
    if (blackAmountJitter){
        if (blackJitterTimer + blackAmountJitterSpeed < ofGetSystemTimeMillis()){
            blackAmount = ofRandom(1,10);
            blackJitterTimer = ofGetSystemTimeMillis();
            cout << "black loop says hi!, speed = " << blackAmountJitterSpeed << endl;
        }
    }
    
    if (numPassesJitter){
        if (passesJitterTimer + numPassesJitterSpeed < ofGetSystemTimeMillis()){
            numPasses = ofRandom(1,20);
            passesJitterTimer = ofGetSystemTimeMillis();
            cout << "passes loop says hi!, speed = " << numPassesJitterSpeed << endl;
        }
    }
    
    if ( hStripeHeightJitter ){
        if (hStripeHeightTimer + hStripeHeightJitterSpeed < ofGetSystemTimeMillis()){
            hStripeHeightRange = ofRandom(1,200);
            hStripeHeightTimer = ofGetSystemTimeMillis();
            cout << "passes  loop says hi!, speed = " << hStripeHeightJitterSpeed << endl;
        }
    }
    
    if ( hStepRangeJitter ){
        if (hStepRangeTimer + hStepRangeJitterspeed < ofGetSystemTimeMillis()){
            hStepRange = ofRandom(1,100);
            hStepRangeTimer = ofGetSystemTimeMillis();
            cout << "hstep  loop says hi!, speed = " << hStepRangeJitterspeed << endl;
        }
    }
    
    if ( sparkColor && sparkColorJitter ){
        if (sparkColorTimer + sparkColorJitterSpeed < ofGetSystemTimeMillis()){
            sparkColorPercent = ofRandom(1,100);
            sparkColorTimer = ofGetSystemTimeMillis();
            cout << "spakr color loop says hi!, speed = " << sparkColorJitterSpeed << endl;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    bool b_itsBlack = true;
    int hStripeHeight = 10;
   
   // cam.begin();
    
    for (int i = 0; i< numPasses; i++){

        for (int y = 0; y < ofGetHeight(); y += ofRandom(1, vStepRange)){
            if (ofRandom(blackAmount)>1) {
                b_itsBlack = true;
            } else {
                b_itsBlack = false;
            }
            hStripeHeight = (ofRandom(hStripeHeightRange));
            
            for (int x = 0; x < ofGetWidth(); x += ofRandom(1, hStepRange)){
                if (!b_itsBlack){
                    ofSetColor(ofRandom(255), ofRandom(200));
                } else {
                    ofSetColor(0, ofRandom( 200));
                }
                ofPushStyle();
                if (sparkColor && (ofRandom(100) > sparkColorPercent )) {
                    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(200));
                }
                ofDrawRectangle( x, y, ofRandom(1, hStepRange),  hStripeHeightRange );
                ofPopStyle();
            }
        }
    }
   // cam.end();
    
    if(b_Gui){
        gui.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
        case 'F':
            ofToggleFullscreen();
            break;
            
        case 'g':
        case 'G':
            b_Gui=!b_Gui;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
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
