#include "Engine.h"

void Engine::draw()
{
    //Background
    m_Window.clear(Color::White);
    // Draw the background
    m_Window.draw(m_BackgroundSprite);

    auto m_BobSprite = m_Bob.getSprite();
    m_BobSprite.setScale(sf::Vector2f(approximation_x*0.5f, approximation_y*0.5f));
    m_Window.draw(m_BobSprite);

    if(isFallingObjectExist){
        m_Window.draw(m_fallingObject.getSprite());
    }

    // Show everything we have just drawn
    m_Window.display();
}

Vector2f Engine::GetResolution() {
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    return resolution;
}