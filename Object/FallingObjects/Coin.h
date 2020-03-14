#pragma once

#include <SFML/Graphics.hpp>
#include "../FallingObject.h"

class Coin : public FallingObject {
public:
    Coin();
    void update(float elapsedTime) override;
    int getHealth() override;
    int getScore() override;
};
