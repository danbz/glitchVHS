/*
Project Title:
Description:
©Daniel Buzzo 2021
dan@buzzo.com
http://buzzo.com
https://github.com/danbz
http://youtube.com/danbuzzo
*/

#pragma once

#include "ofMain.h"
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
    int vStepRange;
    
    ofxFloatSlider blackAmount,blackAmountJitterSpeed, numPassesJitterSpeed, hStripeHeightJitterSpeed, hStepRangeJitterspeed, sparkColorJitterSpeed ;
    ofxToggle blackAmountJitter, numPassesJitter, hStripeHeightJitter, hStepRangeJitter, sparkColor, sparkColorJitter, frameRateJitter;
    ofxIntSlider numPasses, sparkColorPercent;
    ofxIntSlider hStripeHeightRange, hStepRange;

    ofxPanel gui;
    bool b_Gui;
    float blackJitterTimer, passesJitterTimer, hStripeHeightTimer, hStepRangeTimer, sparkColorTimer;

    ofEasyCam cam;
};
