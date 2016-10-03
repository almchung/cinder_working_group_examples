#pragma once

#include <vector>

class Icecream{
 public:
    Icecream();
    void draw(glm::vec2);
    void drawScoop(glm::vec2);
    
    glm::vec2   vLoc;
    float       fDir;
    float       fConeLength;
    float       fConeRadius;
    float       fConeSide;
    float       fZitter;
    float       fFlavor;
    
};
