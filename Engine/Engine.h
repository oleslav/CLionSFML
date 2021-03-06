#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../NPC/NPC.h"
#include "../Object/FallingObject.h"
#include "../Object/FallingObjects/Stone.h"
#include "../Object/FallingObjects/Coin.h"
#include "../Object/FallingObjects/Apple.h"
#include "../iEngine.h"
#include "../Collision.h"

using namespace sf;

class Engine
        : public iEngine {
private:
    bool isGameEnd;
    int score;
    int health;
    Font font;
    Text score_text;
    Texture ScoreTexture;
    Sprite ScoreSprite;

    Text health_text;
    Texture HealthTexture;
    Sprite HealthSprite;

    RenderWindow Window;
    Texture BackgroundTexture;
    Sprite BackgroundSprite;
    NPC npc;
    Apple apple;
    Coin coin;
    Stone stone[4];
    std::vector<FallingObject *> fallingObject;

    void input() override;
    void update(float dtAsSeconds) override;
    void draw() override;

    void fillVector();
    void setTextureSettings();
    void setFlexibleScale();
    void LoadTexturesAndSetSprites();
    void PrintScore();

    Engine();
    static Engine *_instance;
public:

    static Engine *Instance();
    void start() override;
    static Vector2f GetResolution();
};