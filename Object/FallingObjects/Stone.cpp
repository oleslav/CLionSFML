#include "Stone.h"
#include "../../Engine/Engine.h"

Stone::Stone() {
    SetTexture(R"(Media\stone.png)");
    SetSpeed(500 * (Engine::GetResolution().y / 1280.f));
}

void Stone::update(float elapsedTime) {
    if(Position.y <= Engine::GetResolution().y){
        Position.y += Speed * elapsedTime;
        if(m < 4){
            Position.x -= Speed * elapsedTime;
            if(Position.x < 0){
                Position.x = 0;
            }
        }else{
            Position.x += Speed * elapsedTime;
            if(Position.x > Engine::GetResolution().x - 128){
                Position.x = Engine::GetResolution().x - 128;
            }
        }
    } else{
        SetStartPosition();
    }
    TimeAnimation += elapsedTime;
    if (TimeAnimation > 1./25) {
        TimeAnimation = 0;
        if (m < 7) {
            if (n < 7) {
                n++;
            } else {
                m++;
                n = 0;
            }
        } else {
            m = 0;
            n = 0;
        }
    }
    MySprite.setPosition(Position);
    MySprite.setTextureRect(IntRect(128 * n, 128 * m, 128, 128));
}

int Stone::getHealth() {
    return -3;
}

int Stone::getScore() {
    return 0;
}
