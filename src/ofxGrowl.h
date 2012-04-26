//
//  ofxGrowl.h
//
//  Created by Sander ter Braak on 24-04-12.
//  Copyright (c) 2012 Haute Technique. All rights reserved.
//

#ifndef emptyExample_ofxGrowl_h
#define emptyExample_ofxGrowl_h

#include "ofMain.h" 


class ofxGrowl {
public:
    void init(string appName);
    
    void send(string title, string description);
    void send(string title, string description, bool sticky);
    void send(string title, string description, bool sticky, int priority);
    void send(string title, string description, bool sticky, int priority, string icon);
    void send(string title, string description, bool sticky, int priority, string icon, string event);
    
    void event(string e);
    ofEvent<string> growlClickEvent;

};



#endif

