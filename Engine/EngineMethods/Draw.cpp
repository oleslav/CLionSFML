#include "../Engine.h"

void Engine::draw() {
    Window.clear(Color::White);
    Window.draw(BackgroundSprite);
    auto BobSprite = npc.getSprite();
    BobSprite.setScale(sf::Vector2f(approximation_x * 0.5f, approximation_y * 0.5f));
    Window.draw(BobSprite);
    Window.draw(fallingObject[0].getSprite());
    Window.draw(fallingObject[1].getSprite());
    Window.draw(fallingObject[2].getSprite());
    Window.display();
}

Vector2f Engine::GetResolution() {
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    return resolution;
}