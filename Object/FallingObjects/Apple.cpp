#include "Apple.h"
#include "../../Engine/Engine.h"

Apple::Apple() {
    SetTexture(R"(Media\apple.png)");
    SetSpeed(1000 * (Engine::GetResolution().y / 1280.f));
//    MySprite.setScale(Vector2f(1./2, 1./2));
}

void Apple::update(float elapsedTime) {
    if(Position.y <= Engine::GetResolution().y){
        Position.y += Speed * elapsedTime;
    } else{
        SetStartPosition();
    }
    MySprite.setPosition(Position);
    MySprite.setTextureRect(IntRect(0, 0, 64, 64));
}

int Apple::getHealth() {
    return 1;
}

int Apple::getScore() {
    return 0;
}

Sprite Apple::getSprite() {
    return MySprite;
}
