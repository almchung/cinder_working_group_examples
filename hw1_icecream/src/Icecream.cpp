#include "Icecream.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

using namespace ci;

Icecream::Icecream()
{
    fDir = 1.0f;
    fConeLength = 60;
    fConeRadius = 12;
    fConeSide = 6;
    fZitter = 2;
    numCones = 8;
    iMargin = 20;
    iScoopWidth = (fConeRadius + fConeSide)*2;
}

void Icecream::draw(glm::vec2 loc)
{
    // preserve the default Model matrix
    gl::pushModelMatrix();
    
    // set margins and gap between cones
    vec2 offset(iMargin+iScoopWidth, cinder::app::getWindowHeight()-iMargin-fConeLength);
    float fGap = (cinder::app::getWindowWidth()-iMargin-iScoopWidth)/numCones;
    
    // draw cones
    for( int c = 0; c < numCones; ++c ) {
        // preserve the Model matrix
        gl::pushModelMatrix();
        
        // move to the correct position
        gl::translate( offset + vec2(fGap * c,0) +vec2(Rand::randFloat(fZitter)-fZitter/2,Rand::randFloat(fZitter)-fZitter/2));
        
        // draw a cone
        gl::color( Color( CM_HSV, 0.125f, 1.0f, 0.77f ) );
        gl::drawSolidTriangle(vec2(-fConeRadius,0), vec2(fConeRadius,0), vec2(0, fConeLength));
        gl::color( Color( CM_HSV, 0.125f, 1.0f, 0.65f ) );
        gl::drawSolidTriangle(vec2(-fConeRadius,0),vec2(-fConeRadius-fConeSide,0),vec2(0,fConeLength));
        gl::drawSolidTriangle(vec2(fConeRadius,0),vec2(fConeRadius+fConeSide,0),vec2(0,fConeLength));
    
        // restore the Model matrix
        gl::popModelMatrix();
    }
    
    // restore the default Model matrix
    gl::popModelMatrix();
}


void Icecream::drawScoop(glm::vec2 loc)
{
    vLoc = loc+Rand::randFloat(fZitter)-fZitter/2;
    
    // preserve the default Model matrix
    gl::pushModelMatrix();
    
    int numCones = 8;
    int iMargin = 20;
    int iScoopWidth = (fConeRadius + fConeSide)*2;
    //int iScoopHeight = 20;
    vec2 offset(iMargin+iScoopWidth, cinder::app::getWindowHeight()-iMargin-fConeLength);
    
    float fGap = (cinder::app::getWindowWidth()-iMargin-iScoopWidth)/numCones;
    
    for( int c = 0; c < numCones; ++c ) {
        
        float rel = c / (float)numCones;
        
        // preserve the Model matrix
        gl::pushModelMatrix();
        
        // move to the correct position
        gl::translate( offset + vec2(fGap * c,0) +vec2(Rand::randFloat(fZitter)-fZitter/2,Rand::randFloat(fZitter)-fZitter/2));
        
        // draw a cone
        gl::color( Color( CM_HSV, 0.125f, 1.0f, 0.77f ) );
        gl::drawSolidTriangle(vec2(-fConeRadius,0), vec2(fConeRadius,0), vec2(0, fConeLength));
        gl::color( Color( CM_HSV, 0.125f, 1.0f, 0.65f ) );
        gl::drawSolidTriangle(vec2(-fConeRadius,0),vec2(-fConeRadius-fConeSide,0),vec2(0,fConeLength));
        gl::drawSolidTriangle(vec2(fConeRadius,0),vec2(fConeRadius+fConeSide,0),vec2(0,fConeLength));
        
        // set the color using HSV color
        gl::color( Color( CM_HSV, rel, 0.3, 1 ) );
        gl::drawSolidTriangle(vec2(-30,-6), vec2(-30,-24), vec2(-12,-30));
        gl::drawSolidTriangle(vec2(6,-30), vec2(24,-24), vec2(30,-6));
        gl::color( Color( CM_HSV, rel, 0.4, 1 ) );
        gl::drawSolidTriangle(vec2(-12,-30), vec2(-30,-6), vec2(-24,0));
        gl::drawSolidTriangle(vec2(24,0), vec2(6,-30), vec2(30,-6));
        gl::color( Color( CM_HSV, rel, 0.45, 1 ) );
        gl::drawSolidTriangle(vec2(-24,0), vec2(-12,-30), vec2(0,0));
        gl::drawSolidTriangle(vec2(24,0), vec2(6,-30), vec2(0,0));
        gl::color( Color( CM_HSV, rel, 0.5, 1 ) );
        gl::drawSolidTriangle(vec2(-12,-30), vec2(6,-30), vec2(0,0));
        
        // restore the Model matrix
        gl::popModelMatrix();
    }
    
    // restore the default Model matrix
    gl::popModelMatrix();
}


