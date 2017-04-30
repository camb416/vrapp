#pragma once

#include "ofMain.h"
#include "ofxEquiMap.h"

class ofApp : public ofBaseApp, public ofxEquiMap::Scene{

	public:
		void setup();
		void update();
		void draw();

//		void keyPressed(int key);
//		void keyReleased(int key);
//		void mouseMoved(int x, int y );
//		void mouseDragged(int x, int y, int button);
//		void mousePressed(int x, int y, int button);
//		void mouseReleased(int x, int y, int button);
//		void mouseEntered(int x, int y);
//		void mouseExited(int x, int y);
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);
    
    void drawEquiScene();
    
    ofxEquiMap::Renderer em;
    ofxEquiMap::CustomFboRenderer em2;
    
    ofVboMesh m;
    
    ofVboMesh m2;
    
    ofBoxPrimitive box;
    
        ofMaterial material;
    
    ofImage texture;
		
};
