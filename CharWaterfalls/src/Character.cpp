#include "Character.h"

Character::Character() {
    font_size = ofRandom(5, 20);
    font.load("fonts/Kazesawa-Bold.ttf", font_size, true, true, true);
    characters = {
		'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R',
		'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z'};
}

void Character::setup() {
    int index = ofRandom(0, 25);
    character = characters[index];
    path = font.getCharacterAsPoints(character, true, false);
	outline = path.getOutline();
}

void Character::update(ofVec3f position) {
    float noise_value = ofNoise(position.x * 0.005, position.y * 0.005, ofGetFrameNum() * 0.005);
	rotate += ofMap(noise_value, 0.5, 1, 3, 10);
}

void Character::draw(ofVec3f position) {
    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    ofRotateXDeg(rotate);
    ofRotateYDeg(rotate);

    // ofFill();
    // ofSetColor(239);
    // ofBeginShape();
    // for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

    //     if (outline_index != 0) { ofNextContour(true); }

    //     auto vertices = outline[outline_index].getVertices();
    //     for (int vertices_index = 0; vertices_index < vertices.size(); vertices_index++) {

    //         auto location = glm::vec2(vertices[vertices_index].x - this->font.stringWidth(string{character}) * 0.5, vertices[vertices_index].y + this->font.stringHeight(string{character}) * 0.5);
    //         ofVertex(location);
    //     }
    // }
    // ofEndShape(true);
    // if (font_size < 10) {
    //     ofFill();
    // }
    // else {
    //     ofNoFill();
    // }
    ofFill();
    ofBeginShape();
    for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

        if (outline_index != 0) { ofNextContour(true); }

        auto vertices = outline[outline_index].getVertices();
        for (int vertices_index = 0; vertices_index < vertices.size(); vertices_index++) {

            auto location = glm::vec2(vertices[vertices_index].x - this->font.stringWidth(string{character}) * 0.5, vertices[vertices_index].y + this->font.stringHeight(string{character}) * 0.5);
            ofVertex(location);
        }
    }
    ofEndShape(true);
    ofPopMatrix();
}
