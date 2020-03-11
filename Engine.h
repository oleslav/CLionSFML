#pragma once
#include <SFML/Graphics.hpp>
#include "NPC.h"
#include "FallingObject.h"
#include "FallingObject/Stone.h"
#include "FallingObject/Coin.h"
#include "FallingObject/Apple.h"

using namespace sf;

class Engine
{
private:
    RenderWindow Window;
    Sprite BackgroundSprite;
    Texture BackgroundTexture;
    float approximation_x;
    float approximation_y;
    NPC npc;
//    FallingObject fallingObject[3];
    Stone fallingObject[3];

    void input();
    void update(float dtAsSeconds);
    void draw();
    int score = 0;
public:
    Engine();
    void start();
    static Vector2f GetResolution();
};