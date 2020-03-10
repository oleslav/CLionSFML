#include "FallingObject.h"
#include "Engine.h"

FallingObject::FallingObject() {
    m_Speed = 400;
    m_Texture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\stone.png)");
    m_Texture.setSmooth(true);
    m_Sprite.setTexture(m_Texture);
    m_Position.x = 0;
    m_Position.y = 0;
    m_time = 0;
}

Sprite FallingObject::getSprite() {
    return m_Sprite;
}

bool FallingObject::update(float elapsedTime) {
    if(m_Position.y <= Engine::GetResolution().y - 100){
        m_Position.y += m_Speed * elapsedTime;
    } else{
        delete this;
        return false;
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
    return true;
}

FallingObject::~FallingObject() = default;