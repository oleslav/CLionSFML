#include "Engine.h"

Engine::Engine() {
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution = GetResolution();
    m_Window.create(VideoMode(resolution.x, resolution.y),
                    "Simple Game Engine",
                    Style::Fullscreen);
    // Load the background into the texture
    // Be sure to scale this image to your screen size
    m_BackgroundTexture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\back2.png)");
    m_BackgroundTexture.setSmooth(true);
    //Approximation_ to screen size
    this->approximation_x = resolution.x / 1000;
    this->approximation_y = resolution.y / 569;
    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    m_BackgroundSprite.setScale(sf::Vector2f(approximation_x, approximation_y));
}

void Engine::start() {
    // Timing
    Clock clock;

    while (m_Window.isOpen()) {
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();

        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}