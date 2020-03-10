#include "Bob.h"
#include "Engine.h"

Bob::Bob() {
    m_LeftPressed = false;
    m_RightPressed = false;
    m_Speed = 5000;
    // Associate a texture with the sprite
    m_Texture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\bob.png)");
    m_Texture.setSmooth(true);
    // Associate the sprite with the texture
    m_Sprite.setTexture(m_Texture);

    // Set the Bob's starting position
    m_Position.x = 427.5;
    m_Position.y = 750;

}

// Make the private spite available to the draw() function
Sprite Bob::getSprite() {
    return m_Sprite;
}

void Bob::moveLeft() {
    m_LeftPressed = true;
}

void Bob::moveRight() {
    m_RightPressed = true;
}

void Bob::stopLeft() {
    m_LeftPressed = false;
}

void Bob::stopRight() {
    m_RightPressed = false;
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Bob::update(float elapsedTime) {
    if (m_RightPressed &&  m_Position.x + 150 < Engine::GetResolution().x) {
        m_Position.x += m_Speed * elapsedTime;
        m_Sprite.setTextureRect(IntRect(150, 0, -150, 192));
    }
    if (m_LeftPressed && m_Position.x >= 0) {
        m_Position.x -= m_Speed * elapsedTime;
        m_Sprite.setTextureRect(IntRect(0, 0, 150, 192));
    }
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);
}