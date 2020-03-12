#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class NPC
{
private:
    Vector2f Position;
    Sprite NPC_Sprite;
    Texture Texture;
    bool LeftPressed;
    bool RightPressed;
    float Speed;
public:
    NPC();
    Sprite getSprite();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void update(float elapsedTime);
    Vector2f getPosition();
};