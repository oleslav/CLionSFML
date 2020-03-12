#pragma once
#include <SFML/Graphics.hpp>

class iEngine {
protected:
    virtual void input() = 0;
    virtual void update(float dtAsSeconds) = 0;
    virtual void draw() = 0;
public:
    virtual void start() = 0;
};