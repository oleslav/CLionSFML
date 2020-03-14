#include "NPC.h"
#include "../Engine/Engine.h"

NPC::NPC() {
    SetSpeed(1000);
    SetPosition(427.5, 750);
    SetPressed();
    texture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\bob.png)");
    NPC_Sprite.setTexture(texture);
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

void NPC::SetSpeed(float Value_Speed) {
    this->Speed = Value_Speed;
}

void NPC::SetPosition(float x, float y) {
    Position.x = x;
    Position.y = y;
}

void NPC::SetPressed() {
    LeftPressed = false;
    RightPressed = false;
}