#pragma once

#include <SFML/Graphics.hpp>
#include "../NPC/NPC.h"
#include "../Object/FallingObject.h"
#include "../Object/FallingObjects/Stone.h"
#include "../Object/FallingObjects/Coin.h"
#include "../Object/FallingObjects/Apple.h"
#include "../iEngine.h"

using namespace sf;

class Engine
        : public iEngine {
private:
    int score = 0;
    RenderWindow Window;
    float approximation_x;
    float approximation_y;
    Texture BackgroundTexture;
    Sprite BackgroundSprite;
    NPC npc;
    Apple fallingObject[3];

    void input() override;

    void update(float dtAsSeconds) override;

    void draw() override;

    Engine();

    static Engine* _instance;
public:

    static Engine* Instance();

    void start() override;

    static Vector2f GetResolution();
};