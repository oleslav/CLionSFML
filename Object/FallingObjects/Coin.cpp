#include "Coin.h"
#include "../../Engine/Engine.h"

Coin::Coin() {
    srand( time(nullptr) );
    SetSpeed(500);
    SetTexture(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\coin.png)");
    SetStartPosition();
    TimeAnimation = 0;
}

void Coin::update(float elapsedTime) {
    if(Position.y <= Engine::GetResolution().y){
        Position.y += Speed * elapsedTime;
    } else {
        SetStartPosition();
    }
    TimeAnimation += elapsedTime;
    if (TimeAnimation > 1./50) {
        if(n == 0){
            TimeAnimation = 0;
            if (m < 9) {
                m++;
            } else {
                n = -1;
            }
            MySprite.setPosition(Position);
            MySprite.setTextureRect(IntRect(0, 74 * m, 74, 74));
        }else{
            TimeAnimation = 0;
            if (m > 0) {
                m--;
            } else {
                m = 0;
                n = 0;
            }
            MySprite.setPosition(Position);
            MySprite.setTextureRect(IntRect(74, 74 * m, - 74, 74));
        }
    }
}
