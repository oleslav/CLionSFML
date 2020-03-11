#include "Coin.h"
#include "../Engine.h"

Coin::Coin() {
    srand( time(nullptr) );
    SetSpeed(500);
    SetTexture(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\coin.png)");
    SetStartPosition();
    m_time = 0;
}

void Coin::update(float elapsedTime) {
    if(m_Position.y <= Engine::GetResolution().y){
        m_Position.y += m_Speed * elapsedTime;
    } else {
        SetStartPosition();
    }
    m_time += elapsedTime;
    if (m_time > 1./50) {
        if(n == 0){
            m_time = 0;
            if (m < 9) {
                m++;
            } else {
                n = -1;
            }
            m_Sprite.setPosition(m_Position);
            m_Sprite.setTextureRect(IntRect(0, 74 * m, 74, 74));
        }else{
            m_time = 0;
            if (m > 0) {
                m--;
            } else {
                m = 0;
                n = 0;
            }
            m_Sprite.setPosition(m_Position);
            m_Sprite.setTextureRect(IntRect(74, 74 * m, - 74, 74));
        }
    }
}
