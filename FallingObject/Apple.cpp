#include "Apple.h"
#include "../Engine.h"

Apple::Apple() {
    SetTexture(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\apple.png)");
    SetSpeed(1000);
    SetScale();
}

void Apple::update(float elapsedTime) {
    if(m_Position.y <= Engine::GetResolution().y){
        m_Position.y += m_Speed * elapsedTime;
    } else{
        SetStartPosition();
    }
    m_Sprite.setPosition(m_Position);
    m_Sprite.setTextureRect(IntRect(0, 0, 512, 512));
}

void Apple::SetScale() {
    m_Sprite.setScale(sf::Vector2f(1./8,1./8));
}
