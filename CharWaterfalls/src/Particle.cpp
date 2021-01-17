#include "Particle.h"

Particle::Particle() {
    setup();
}

void Particle::setup() {
    position = ofVec3f(ofRandom(-200, 200), ofRandom(-30, 100), ofRandom(0, -400));
    velocity = ofVec3f(ofRandom(-0.5, 0.5), 0.0, ofRandom(1.0, 2.0));
    color = ofColor(ofRandom(0, 128), ofRandom(64, 192), ofRandom(128, 255));

    character.setup();
}

void Particle::update() {
    position.x += velocity.x;
    position.z += velocity.z;

    if (position.z > 0) {
        position.y -= GRAVITY / (2 * pow(velocity.z, 2)) * pow(position.z, 2) * 0.0008;
    }

    if (position.y < LIMITY) {
        setup();
    }

    color.b += ofRandom(-10, 10) * ofMap(position.y, -300, 100, 1.0, 0.5);
    character.update(position);
}

void Particle::draw() {
    ofSetColor(color);
    character.draw(position);
}