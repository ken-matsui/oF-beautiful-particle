#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Setup the screen.
    ofSetVerticalSync(false);
    //ofSetBackgroundAuto(false);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetFrameRate(60);
    ofBackground(0);
    
    // Setup the mesh.
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(0.1);
    
    // Initialize particle.
    for (auto& pos : particlePos)
        pos.zero();
    for (auto& vel : particleVel)
        vel = ofVec3f(ofRandom(-1.0, 1.0),ofRandom(-1.0, 1.0),ofRandom(-1.0, 1.0));
    
    cam.setDistance(2000);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ceil(ofGetFrameRate())));
    
    for (auto& vel : particleVel){
        vel.x += ofMap(ofNoise(vel), 0.0, 1.0, -1.0, 1.0);
        vel.y += ofMap(ofNoise(vel), 0.0, 1.0, -1.0, 1.0);
        vel.z += ofMap(ofNoise(vel), 0.0, 1.0, -1.0, 1.0);
    }
    
    for (auto i = 0; i < NUM; i++){
        particlePos[i] += particleVel[i];
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(0, 0, 0, 10);
    //ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    cam.begin();
    
    // Draw mesh.
    mesh.clear();
    ofSetColor(255);
    for (auto& pos : particlePos)
        mesh.addVertex(ofVec3f(pos.x, pos.y, pos.z));
    mesh.draw();
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
