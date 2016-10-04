#include "Particle.h"
#include "cinder/Rand.h"    
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

using namespace ci;

Particle::Particle()
{
}

Particle::Particle( glm::vec2 loc)
{
    mLoc = loc;
    mDir = Rand::randVec2();
    mVel = Rand::randFloat();
    //r = randFloat();
    //g = randFloat();
    //b = randFloat();
    mRadius = 5.0f;
    
}

void Particle::update()
{
    mVel = Rand::randFloat();
    mLoc += mDir * mVel;
    
    if(mLoc.x > app::getWindowWidth() - mRadius || mLoc.x <= 0 + mRadius){
        mDir.x *= -1.0f;
    }
    if(mLoc.y > app::getWindowHeight() - mRadius || mLoc.y <= 0 + mRadius){
        mDir.y *= -1.0f;
    }
}

void Particle::draw()
{
    gl::color( Color( CM_HSV, Rand::randFloat(1.0f), 0.4, 1 ) );
    gl::drawSolidCircle(mLoc, mRadius,7);
}
