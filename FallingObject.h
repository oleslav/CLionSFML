#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class FallingObject {
protected:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;
    float m_Speed{};
    float m_time;
    int n = 0, m = 0;
    void SetStartPosition();
    void SetTexture(const String& location);
    void SetSpeed(float Speed);
public:
    FallingObject();
    Sprite getSprite();
    virtual void update(float elapsedTime);
    bool collision(Vector2f npc_position);
};