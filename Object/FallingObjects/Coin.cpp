#include "Coin.h"
#include "../../Engine/Engine.h"

Coin::Coin() {
    srand(time(nullptr));
    SetSpeed(1000 * (Engine::GetResolution().y / 1280.f));
    SetTexture(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\coin.png)");
    TimeAnimation = 0;
}

void Coin::update(float elapsedTime) {
    if (Position.y <= Engine::GetResolution().y) {
        Position.y += Speed * elapsedTime;
    } else {
        SetStartPosition();
    }
    TimeAnimation += elapsedTime;
    if (TimeAnimation > 1. / 50) {
        if (n == 0) {
            TimeAnimation = 0;
            if (m < 9) {
                m++;
            } else {
                n = -1;
            }
            MySprite.setPosition(Position);
            MySprite.setTextureRect(IntRect(0, 64 * m, 64, 64));
        } else {
            TimeAnimation = 0;
            if (m > 0) {
                m--;
            } else {
                m = 0;
                n = 0;
            }
            MySprite.setPosition(Position);
            MySprite.setTextureRect(IntRect(64, 64 * m, -64, 64));
        }
    }
}

int Coin::getHealth() {
    return 0;
}

int Coin::getScore() {
    return 1;
}
