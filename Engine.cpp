#include "Engine.h"

Engine::Engine() {
    Vector2f resolution = GetResolution();
    Window.create(VideoMode(resolution.x, resolution.y),
                    "Simple Game Engine",
                    Style::Fullscreen);
    BackgroundTexture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\back2.png)");
    BackgroundTexture.setSmooth(true);
    this->approximation_x = resolution.x / 1000;
    this->approximation_y = resolution.y / 569;
    BackgroundSprite.setTexture(BackgroundTexture);
    BackgroundSprite.setScale(sf::Vector2f(approximation_x, approximation_y));
}

void Engine::start() {
    Clock clock;
    while (Window.isOpen()) {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
    }
}