#include "NPC.h"
#include "../Engine/Engine.h"

NPC::NPC() {
    LeftPressed = false;
    RightPressed = false;
    Speed = 1000;
    // Associate a texture with the sprite
    Texture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\bob.png)");
    Texture.setSmooth(true);
    // Associate the sprite with the texture
    NPC_Sprite.setTexture(Texture);
    Position.x = 427.5;
    Position.y = 750;
}

Sprite NPC::getSprite() {
    return NPC_Sprite;
}

void NPC::moveLeft() {
    LeftPressed = true;
}

void NPC::moveRight() {
    RightPressed = true;
}

void NPC::stopLeft() {
    LeftPressed = false;
}

void NPC::stopRight() {
    RightPressed = false;
}


void NPC::update(float elapsedTime) {
    if (RightPressed &&  Position.x + 150 < Engine::GetResolution().x) {
        Position.x += Speed * elapsedTime;
        NPC_Sprite.setTextureRect(IntRect(150, 0, -150, 192));
    }
    if (LeftPressed && Position.x >= 0) {
        Position.x -= Speed * elapsedTime;
        NPC_Sprite.setTextureRect(IntRect(0, 0, 150, 192));
    }
    NPC_Sprite.setPosition(Position);
}

Vector2f NPC::getPosition() {
    return Position;
}
