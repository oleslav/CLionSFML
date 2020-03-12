#pragma once

#include <SFML/Graphics.hpp>
#include "../iObject.h"

using namespace sf;

class FallingObject : public iObject {
protected:
    Vector2f Position;
    Sprite MySprite;
    Texture Texture;
    float Speed{};
    float TimeAnimation = 0;
    int n = 0, m = 0;

    void SetStartPosition() override;

    void SetTexture(const String &location) override;

    void SetSpeed(float Speed) override;

public:
    FallingObject();

    Sprite getSprite() override;
};