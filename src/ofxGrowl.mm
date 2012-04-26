//
//  ofxGrowl.mm
//
//  Created by Sander ter Braak on 24-04-12.
//  Copyright (c) 2012 Haute Technique. All rights reserved.
//

#include "ofxGrowl.h"
#include "Growl.h"

Growl * growl;

void ofxGrowl::event(string e){
    ofNotifyEvent(growlClickEvent, e, this);
}

void ofxGrowl::init(string appName){
    growl = [[Growl alloc] init];
    [growl setupWithName:[NSString stringWithUTF8String:appName.c_str()] andProxy:this];
}

void ofxGrowl::send(string title, string description){
    send(title, description,false,0,"","");
}
void ofxGrowl::send(string title, string description, bool sticky){
    send(title, description,sticky,0,"","");
}
void ofxGrowl::send(string title, string description, bool sticky, int priority){
    send(title, description,sticky,priority,"","");
}

void ofxGrowl::send(string title, string description, bool sticky, int priority, string icon){
    send(title, description,sticky,priority,icon,"");    
}

void ofxGrowl::send(string title, string description, bool sticky, int priority, string icon, string event){
    
    if(icon != "") icon = ofToDataPath(icon);
    
    [growl sendWithTitle:[NSString stringWithUTF8String:title.c_str()]
             description:[NSString stringWithUTF8String:description.c_str()]
                  sticky:(BOOL)sticky 
                    icon:[NSString stringWithUTF8String:icon.c_str()]
                priority:priority
                   event:[NSString stringWithUTF8String:event.c_str()]]; 
}

