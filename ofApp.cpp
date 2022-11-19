#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(19);
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	ofTranslate(ofGetWindowSize() * 0.5);

	float radius = 300;
	float deg_span = 30;

	for (float radius = 130; radius <= 300; radius += 5) {

		for (float deg_start = 0; deg_start < 360; deg_start += deg_span) {

			float deg_param = ofMap(ofNoise(radius * 0.01 + ofGetFrameNum() * 0.0025), 0, 1, -360, 360);

			ofNoFill();
			ofBeginShape();
			for (float deg = deg_start + deg_param; deg < deg_start + deg_param + deg_span * 0.5; deg += 1) {

				ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			}
			ofEndShape(false);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}