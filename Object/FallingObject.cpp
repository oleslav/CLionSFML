#include "FallingObject.h"
#include "../Engine/Engine.h"
#include "random"

FallingObject::FallingObject() {
    srand(time(nullptr));
    Vector2f resolution = Engine::GetResolution();
    MySprite.setScale(Vector2f(resolution.x / 1920.f, resolution.y / 1080.f));
    SetStartPosition();
    TimeAnimation = 0;
}

Sprite FallingObject::getSprite() {
    return MySprite;
}

void FallingObject::SetTexture(const String &location) {
    Texture.loadFromFile(location);
    Texture.setSmooth(true);
    MySprite.setTexture(Texture);
}

void FallingObject::SetStartPosition() {
    Position.x = rand() % int(Engine::GetResolution().x - 128);
    Position.y = -128;
}

void FallingObject::SetSpeed(float ValueSpeed) {
    this->Speed = ValueSpeed;
}