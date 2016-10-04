#pragma once

#include <vector>

class Icecream{
 public:
    Icecream();
    void draw();
    void drawScoop();
    void update();
    
    glm::vec2   vLoc;
    float       fDir;
    float       fConeLength;
    float       fConeRadius;
    float       fConeSide;
    float       fZitter;
    float       fFlavor;
    int         numCones;
    int         iMargin;
    int         iScoopWidth;
    int         iScoopHeight;
    int         numScoop;
};
