#include "Icecream.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace std;

Icecream::Icecream()
{
    fDir = 1.0f;
    fConeLength = 60;
    fConeRadius = 12;
    fConeSide = 6;
    fZitter = 2;
    iMargin = 20;
    iScoopWidth = (fConeRadius + fConeSide)*2;
    iScoopHeight = 30;
    numCones = cinder::app::getWindowWidth()/iScoopWidth;
    numScoop = 1;   // will be updated
}

void Icecream::draw()
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
        gl::color( Color( CM_HSV, 0.125f, 0.8f, 0.87f ) );
        gl::drawSolidTriangle(vec2(-fConeRadius,0), vec2(fConeRadius,0), vec2(0, fConeLength));
        gl::color( Color( CM_HSV, 0.125f, 0.8f, 0.75f ) );
        gl::drawSolidTriangle(vec2(-fConeRadius,0),vec2(-fConeRadius-fConeSide,0),vec2(0,fConeLength));
        gl::drawSolidTriangle(vec2(fConeRadius,0),vec2(fConeRadius+fConeSide,0),vec2(0,fConeLength));
    
        // restore the Model matrix
        gl::popModelMatrix();
    }
    
    // restore the default Model matrix
    gl::popModelMatrix();
}


void Icecream::drawScoop()
{
    // preserve the default Model matrix
    gl::pushModelMatrix();
    
    // set margins and gap between ice creams
    vec2 offset(iMargin+iScoopWidth, cinder::app::getWindowHeight()-iMargin-fConeLength);
    float fGap = (cinder::app::getWindowWidth()-iMargin-iScoopWidth)/numCones;
    
    // draw scoop - rows
    for( int r = 0; r < numScoop; ++r){
        for( int c = 0; c < numCones; ++c ) {
            
            float rel = c / (float)numCones;
            // flip coin
            int coin = (Rand::randFloat(1.0f) > 0.5) ? 1 : -1;
            
            // preserve the Model matrix
            gl::pushModelMatrix();
            
            // move to the correct position
            gl::translate( offset + vec2(fGap * c, -r*(iScoopHeight-4)) +vec2(Rand::randFloat(fZitter)-fZitter/2,Rand::randFloat(fZitter)-fZitter/2));
            
            // set the color using HSV color
            gl::color( Color( CM_HSV, rel, 0.3, 1 ) );
            gl::drawSolidTriangle(vec2(-30*coin,-6), vec2(-30*coin,-24), vec2(-12*coin,-30));
            gl::drawSolidTriangle(vec2(6*coin,-30), vec2(24*coin,-24), vec2(30*coin,-6));
            gl::color( Color( CM_HSV, rel, 0.4, 1 ) );
            gl::drawSolidTriangle(vec2(-12*coin,-30), vec2(-30*coin,-6), vec2(-24*coin,0));
            gl::drawSolidTriangle(vec2(24*coin,0), vec2(6*coin,-30), vec2(30*coin,-6));
            gl::color( Color( CM_HSV, rel, 0.45, 1 ) );
            gl::drawSolidTriangle(vec2(-24*coin,0), vec2(-12*coin,-30), vec2(0*coin,0));
            gl::drawSolidTriangle(vec2(24*coin,0), vec2(6*coin,-30), vec2(0*coin,0));
            gl::color( Color( CM_HSV, rel, 0.5, 1 ) );
            gl::drawSolidTriangle(vec2(-12*coin,-30), vec2(6*coin,-30), vec2(0*coin,0));
            
            // restore the Model matrix
            gl::popModelMatrix();
        }
    }
    
    // restore the default Model matrix
    gl::popModelMatrix();
}

void Icecream::update()
{
    int iFrame = cinder::app::getElapsedFrames();
    cout << "Count frame: " + std::to_string( iFrame ) + "\n";
    if (iFrame%2==0){
        if (numScoop < cinder::app::getWindowHeight()/iScoopHeight){
            numScoop++;
        }else{
            numScoop = 1;
        }
    }
}
