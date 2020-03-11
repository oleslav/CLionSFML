#include "FallingObject.h"
#include "Engine.h"
#include "random"

FallingObject::FallingObject() {
    srand(time(nullptr));
    SetSpeed(400);
    SetTexture(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\stone.png)");
    SetStartPosition();
    m_time = 0;
}

Sprite FallingObject::getSprite() {
    return m_Sprite;
}

void FallingObject::update(float elapsedTime) {
}

void FallingObject::SetTexture(const String &location) {
    m_Texture.loadFromFile(location);
    m_Texture.setSmooth(true);
    m_Sprite.setTexture(m_Texture);
}

void FallingObject::SetStartPosition() {
    m_Position.x = rand() % int(Engine::GetResolution().x - 128);
    m_Position.y = -128;
}

void FallingObject::SetSpeed(float Speed) {
    m_Speed = Speed;
}

bool FallingObject::collision(Vector2f npc_position) {
    if (npc_position.y == m_Position.y || npc_position.x == m_Position.x) {
        return true;
    } else {
        return false;
    }
}
