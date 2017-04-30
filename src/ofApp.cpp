#include "ofMain.h"

#include "ofApp.h"

    
    void ofApp::setup()
    {
        ofSetVerticalSync(true);
        ofSetFrameRate(60);
        em.setup(1024, this);
        em2.setup(1024, this, GL_RGB, 4);
        ofSpherePrimitive p(1000, 24);
        
        
        m = p.getMesh();
        
            box.set( ofGetWidth()*.12*1.25 );
        
        // shininess is a value between 0 - 128, 128 being the most shiny //
        material.setShininess( 120 );
        // the light highlight of the material //
        material.setSpecularColor(ofColor(255, 255, 255, 255));
        
        // GL_REPEAT for texture wrap only works with NON-ARB textures //
        ofDisableArbTex();
        texture.load("of.png");
        texture.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );


    }
    
    void ofApp::drawEquiScene()
    {
        ofPushStyle();
        ofSetLineWidth(3);
        ofSetColor(192);
        m.drawWireframe();
        
        
        // Box //
        ofEnableDepthTest();
        texture.getTexture().bind();
        box.mapTexCoordsFromTexture( texture.getTexture() );

        box.setScale(0.9f);
        box.setPosition(ofGetWidth()*.5 + sin(ofGetElapsedTimeMillis()/300.0f)*200.0f, ofGetHeight()*.5, 0);
        box.rotate(0.1f, 1.0, 0.0, 0.0);
        box.rotate(0.1f, 0, 1.0, 0.0);
        ofFill();
        box.draw();
        texture.getTexture().unbind();
        
        ofPopStyle();
    }
    
    void ofApp::update() {
        em.render();
        em2.render();
    }
    
    void ofApp::draw()
    {
        ofClear(0);
        if (ofGetKeyPressed(' ')) {
            em.draw(0, 0, ofGetWidth(), ofGetHeight());
            ofDrawBitmapStringHighlight("Renderer", 10, 40);
        } else {
            em2.draw(0, 0, ofGetWidth(), ofGetHeight());
            ofDrawBitmapStringHighlight("CustomFboRenderer", 10, 40);
        }
        
        

        

        ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
    }
    

//========================================================================

