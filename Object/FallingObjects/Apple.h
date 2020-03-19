#pragma once

#include <SFML/Graphics.hpp>
#include "../FallingObject.h"

class Apple : public FallingObject
{
public:
    Apple();
    void update(float elapsedTime) override;
    int getHealth() override;
    int getScore() override;
    Sprite getSprite() override;
};