#include "Stone.h"
#include "../Engine.h"

Stone::Stone() {
    SetTexture(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\stone.png)");
    SetSpeed(1000);
}

void Stone::update(float elapsedTime) {
    if(m_Position.y <= Engine::GetResolution().y){
        m_Position.y += m_Speed * elapsedTime;
        if(m < 4){
            m_Position.x -= m_Speed * elapsedTime;
            if(m_Position.x < 0){
                m_Position.x = 0;
            }
        }else{
            m_Position.x += m_Speed * elapsedTime;
            if(m_Position.x > Engine::GetResolution().x - 128){
                m_Position.x = Engine::GetResolution().x - 128;
            }
        }
    } else{
        SetStartPosition();
    }
    m_time += elapsedTime;
    if (m_time > 1./25) {
        m_time = 0;
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
    m_Sprite.setPosition(m_Position);
    m_Sprite.setTextureRect(IntRect(128 * n, 128 * m, 128, 128));
}
