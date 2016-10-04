#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Icecream.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class hw1_icecreamApp : public App {
  public:
    void prepareSettings(Settings *settings);
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    Icecream cIcecream;
};

void hw1_icecreamApp::prepareSettings(Settings *settings){
    settings->setWindowSize(800,1200);
    settings->setFrameRate(20.0f);
}

void hw1_icecreamApp::setup()
{
}

void hw1_icecreamApp::mouseDown( MouseEvent event )
{
}

void hw1_icecreamApp::update()
{
    //cIcecream.draw(vec2(20,50));
}

void hw1_icecreamApp::draw()
{
	gl::clear( Color( CM_HSV, Rand::randFloat(1.0f), 1.0, 0.2 ) );
    cIcecream.draw(vec2(300,450));
    cIcecream.drawScoop(vec2(200,400));
    cout << "Avgerage FPS: " + to_string(getAverageFps()) + "\n";
}

CINDER_APP( hw1_icecreamApp, RendererGl )
