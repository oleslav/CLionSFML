#pragma once
#include <SFML/Graphics.hpp>
#include "Bob.h"
#include "FallingObject.h"

using namespace sf;

class Engine
{
private:
    // A regular RenderWindow
    RenderWindow m_Window;
    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    float approximation_x;
    float approximation_y;
    // An instance of Bob
    Bob m_Bob;
    // An instance of FallingObject
    FallingObject m_fallingObject;
    bool isFallingObjectExist = true;
    // Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();
public:
    // The Engine constructor
    Engine();
    // start will call all the private functions
    void start();
    static Vector2f GetResolution();
};