#include "Icecream.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

using namespace ci;

Icecream::Icecream()
{
    fDir = 1.0f;
    fConeLength = 60;
    fConeRadius = 15;
    fConeSide = 4;
    fZitter = 2;
    fFlavor = Rand::randFloat(360);
}

void Icecream::draw(glm::vec2 loc)
{
    vLoc = loc+Rand::randFloat(fZitter)-fZitter/2;
    
    // preserve the default Model matrix
    gl::pushModelMatrix();
    
    int numCones = 12;
    int iMargin = 20;
    int iScoopWidth = (fConeRadius + fConeSide)*2;
    int iScoopHeight = 20;
    vec2 offset(iMargin+iScoopWidth, iMargin+iScoopHeight);
    
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
        gl::color( Color( CM_HSV, rel, 1, 1 ) );
        // draw a circle relative to Model matrix
        gl::drawSolidCircle( vec2(0,-10), 20 );

    
        // restore the Model matrix
        gl::popModelMatrix();
    }
    
    // draw a white circle at window center
    gl::color( Color(1,1,1));
    gl::drawSolidCircle(vec2(), 30);
    
    // restore the default Model matrix
    gl::popModelMatrix();
}


void Icecream::drawScoop(glm::vec2 loc)
{
    vLoc = loc+Rand::randFloat(fZitter)-fZitter/2;
    fFlavor = Rand::randFloat(360);
    
    // reset the matrices
    gl::setMatricesWindow( cinder::app::getWindowSize() );
    
    
    // Draw a scoop of ice cream
    gl::translate( vLoc );
    ////
    ////// main triangle
    gl::color( Color( CM_HSV, fFlavor/360, 0.3f, 1.0f ) );
    // draw a triangle relative to Model matrix
    gl::drawSolidTriangle(vec2( 0.0f, 0.0f+fConeLength), vec2( -fConeRadius*0.5, fConeLength*0.6 ), vec2( fConeRadius*0.5, fConeLength*0.6 ));
}


