#include "FallingObject.h"
#include "../Engine/Engine.h"
#include "random"

FallingObject::FallingObject() {
    srand(time(nullptr));
    SetSpeed(400);
    SetTexture(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\stone.png)");
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

void FallingObject::SetSpeed(float Speed) {
    this->Speed = Speed;
}