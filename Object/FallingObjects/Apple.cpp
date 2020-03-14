#include "Apple.h"
#include "../../Engine/Engine.h"

Apple::Apple() {
    SetTexture(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\apple.png)");
    SetSpeed(1000);
    SetScale();
}

void Apple::update(float elapsedTime) {
    if(Position.y <= Engine::GetResolution().y){
        Position.y += Speed * elapsedTime;
    } else{
        SetStartPosition();
    }
    MySprite.setPosition(Position);
    MySprite.setTextureRect(IntRect(0, 0, 512, 512));
}

void Apple::SetScale() {
    MySprite.setScale(sf::Vector2f(1./8,1./8));
}

int Apple::getHealth() {
    return 1;
}

int Apple::getScore() {
    return 0;
}
