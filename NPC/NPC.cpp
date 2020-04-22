#include "NPC.h"
#include "../Engine/Engine.h"

NPC::NPC() {
    SetSpeed(1000 * (Engine::GetResolution().x / 1920.f));
    SetPosition(428 * (Engine::GetResolution().x / 1920.f), 750 * (Engine::GetResolution().y / 1080.f));
    SetPressed();
    texture.loadFromFile(R"(Media\bob.png)");
    NPC_Sprite.setTexture(texture);
    NPC_Sprite.setScale(
            Vector2f(Engine::GetResolution().x / 1920.f, Engine::GetResolution().y / 1080.f));
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
    if (RightPressed && Position.x + 128 < Engine::GetResolution().x) {
        Position.x += Speed * elapsedTime;
        NPC_Sprite.setTextureRect(IntRect(128, 0, -128, 164));
    }
    if (LeftPressed && Position.x >= 0) {
        Position.x -= Speed * elapsedTime;
        NPC_Sprite.setTextureRect(IntRect(0, 0, 128, 164));
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