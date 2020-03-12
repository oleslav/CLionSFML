#include <SFML/Graphics.hpp>

class iObject {
public:
    virtual sf::Sprite getSprite() = 0;
    virtual void update(float elapsedTime) = 0;
protected:
    virtual void SetTexture(const sf::String& location) = 0;
    virtual void SetStartPosition() = 0;
    virtual void SetSpeed(float Speed) = 0;
};

