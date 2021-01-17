#pragma once

#include "ofMain.h"
#include "Character.h"

class Particle {

public:
    Particle();

    void setup();
    void update();
    void draw();

    ofVec3f position;
    ofVec3f velocity;

    ofColor color;

    Character character;
    const float GRAVITY = 0.98;
    const float LIMITY = -400;

};