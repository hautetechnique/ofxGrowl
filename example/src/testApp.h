//
//  Created by Sander ter Braak on 24-04-12.
//  Copyright (c) 2012 Haute Technique. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxGrowl.h"


class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void growlEvent(string & e);
    ofxGrowl growl;
    
};

