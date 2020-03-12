#pragma once

#include <SFML/Graphics.hpp>
#include "../FallingObject.h"

class Stone : public FallingObject {
public:
    Stone();
    void update(float elapsedTime) override;
};
