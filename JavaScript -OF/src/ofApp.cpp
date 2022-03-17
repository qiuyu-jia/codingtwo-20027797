#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    //intialize the drawing variables
    for (int i = 0; i< ofGetWidth(); ++i){
        waveform[i] = 0;
    }
    waveIndex = 0;
    //Maximilian audio stuff
    int sampleRate = 44100;/*sampling ratr*/
    int bufferSize = 512;/*buffer size. you have to fill this buffer with sound using the for loop in the sudioOut method*/
    ofxMaxiSettings::setup(sampleRate,2,bufferSize);
    
    //setup ofsound
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels =2;
    settings.numInputChannels =0;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(0, ofGetHeight()/2);
    ofSetColor(0,255,0);
    ofFill();
    ofDrawLine(0,0,1,waveform[1]*ofGetHeight()/2.);//first line
    for (int i = 1; i<(ofGetWidth()-1);++i){
    
        ofDrawLine(i,waveform[i] * ofGetHeight()/2.,i+1, waveform[i+1]* ofGetWidth()/2);
    }
    
     
}
//------------------------------
void ofApp::audioIn(ofSoundBuffer& input){
    std::size_t nChannels = input.getNumChannels();
    for (size_t i=0; i < input.getNumFrames();i++)
    {
        //handle input here
    }
}
//------------------------------
void ofApp::audioOut(ofSoundBuffer& output){
    std::size_t outChannels = output.getNumChannels();
    for(int i = 0; i<output.getNumFrames(); ++i){
        
        output[i * outChannels] = (oscillator1.triangle(50 + oscillator2.coswave(oscillator6.triangle(0.5) * oscillator7.sinewave(1.5))/5)+oscillator1.triangle(oscillator3.coswave(8*5) + oscillator4.phasor(50))/0.5) * 0.5 + oscillator5.coswave(0.1)*2 + oscillator8.square(1)*0.5 + oscillator9.square(20)*0.5 + oscillator10.square(4)*0.2;
        output[i * outChannels +1]=output[i*outChannels];
        waveform[waveIndex] =  output[i * outChannels];
        if (waveIndex <(ofGetWidth() - 1)){
            ++waveIndex;
        }else {
            waveIndex = 0;
        }
    }
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
