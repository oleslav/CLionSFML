#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class NPC {
private:
    Vector2f Position;
    Texture texture;
    Sprite NPC_Sprite;
    bool LeftPressed{};
    bool RightPressed{};
    float Speed{};
    void SetSpeed(float Speed);
    void SetPosition(float x, float y);
    void SetPressed();
public:
    NPC();
    Sprite getSprite();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void update(float elapsedTime);
};