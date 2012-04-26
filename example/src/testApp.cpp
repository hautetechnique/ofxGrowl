//
//  Created by Sander ter Braak on 24-04-12.
//  Copyright (c) 2012 Haute Technique. All rights reserved.
//

#include "testApp.h"


int aa = 1;

//--------------------------------------------------------------
void testApp::setup(){
    
    // setup growl with an app name. The name appears the Growl panel in the system preferences
    growl.init("testApp");
    
    
    // add an eventlistener to Growl. The events are dispatched when the user clicks the growl message. 
    ofAddListener(growl.growlClickEvent, this, &testApp::growlEvent);
}


// eventlistener
void testApp::growlEvent(string & e){
    cout << "Did recieve a growl event: " << e << endl;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofDrawBitmapString("Click me!", 100,100);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    aa++;
    
    
    // send a growl message.
    // title: the message title. The title is also the identifyer of the message. Sending 2 messages with the same title will override the message instead of add it.
    // message: a string containing the message
    // sticky: Make a message sticky 
    // priority: pririoty
    // icon: a string containing the name of the icon file, in the OF data folder. Icons can be .icns files or images (PNG etc)
    // Event: The name of the event that should be dispatched when the user clicks the message.
    growl.send("Unique title NR." + ofToString(aa),
               "CLICK ME!", 
               false,
               0,
               "test.icns",
               "ClickEvent!");
    
    
    //examples of use:
    
    growl.send("Title1", "message");
    growl.send("Sticky message", "message", true);
    growl.send("Priority message", "message", false, 1);
    growl.send("Png icon", "message", true, 1,"test.png");
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}