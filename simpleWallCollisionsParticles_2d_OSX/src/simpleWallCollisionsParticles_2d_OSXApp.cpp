#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Text.h"
#include "Particle.h"
#include "ParticleController.h"
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

class simpleWallCollisionsParticles_2d_OSXApp : public App {
  public:
    void prepareSettings(Settings *settings);
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    Font mFont;
    
    ParticleController mParticleController;
};

void simpleWallCollisionsParticles_2d_OSXApp::prepareSettings(Settings *settings){
    settings->setWindowSize(600, 600);
    settings->setFrameRate(120.0f);
}

void simpleWallCollisionsParticles_2d_OSXApp::setup()
{
    mParticleController.addParticles(50);
}

void simpleWallCollisionsParticles_2d_OSXApp::mouseDown( MouseEvent event )
{
}

void simpleWallCollisionsParticles_2d_OSXApp::update()
{
    mParticleController.update();
}

void simpleWallCollisionsParticles_2d_OSXApp::draw()
{
	gl::clear( Color( 0.2f, 0.1f, 0.2f ) );
    mParticleController.draw();
    cout << "Avgerage FPS: " + to_string(getAverageFps()) + "\n";
}

CINDER_APP( simpleWallCollisionsParticles_2d_OSXApp, RendererGl )
