#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(0.5);

    for (int i = 0; i < NUM; i++) {
        particle[i].setup();
    }
    camPos.x = ofGetWidth()/2;
    camPos.y = ofGetHeight()/2;
    camPos.z = camRad;
    cam.setPosition(camPos);
	cam.setTarget(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM; i++) {
        particle[i].update();
    }

    // float time = ofGetElapsedTimef();
    // camPos.x = ofGetWidth()/2 + camRad * cos(coef * time * v);
    // camPos.y = ofGetHeight()/2 - camRad * sin(coef * time * v);
    // camPos.z = camRad * 0.8 * sin(coef * time * v);
    // cam.setPosition(camPos);
    // cam.setTarget(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0);

    for (int i = 0; i < NUM; i++) {
        particle[i].draw();
    }

    ofPopMatrix();
    cam.end();
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