#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


class FallingObject {

private:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;

    float m_Speed;

    float m_time;
    int n = 0, m = 0;
public:
    FallingObject();
    ~FallingObject();
    Sprite getSprite();
    bool update(float elapsedTime);
};


