#pragma once

#include "ofMain.h"

class Character {
public:
    Character();

    void setup();
    void update(ofVec3f position);
    void draw(ofVec3f position);

    vector<char> characters;
    int font_size;
    int rotate = 0;
    char character;
    ofPath path;
    vector<ofPolyline> outline;
    ofVec3f position;
    ofTrueTypeFont font;
};
