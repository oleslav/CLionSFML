#include "Engine.h"

Engine *Engine::_instance = nullptr;

Engine *Engine::Instance() {
    if (_instance == nullptr) {
        _instance = new Engine;
    }
    return _instance;
}

Engine::Engine() {
    if (!font.loadFromFile(R"(C:\Windows\Fonts\arial.ttf)")) {
        exit(0);
    }
    score = 0;
    health = 50;
    fallingObject.push_back(&apple);
    fallingObject.push_back(&coin);
    fallingObject.push_back(&stone[0]);
    fallingObject.push_back(&stone[1]);
    fallingObject.push_back(&stone[2]);
    fallingObject.push_back(&stone[3]);
    health_text.setFillColor(Color::White);
    score_text.setFillColor(Color::Black);
    health_text.setStyle(sf::Text::Bold);
    score_text.setStyle(sf::Text::Bold);
    score_text.setPosition(Engine::GetResolution().x - 200.f, 118.f);
    health_text.setPosition(50.f, 50.f);
    health_text.setFont(font);
    score_text.setFont(font);
    Vector2f resolution = GetResolution();
    Window.create(VideoMode(resolution.x, resolution.y),
                  "Simple Game Engine",
                  Style::Fullscreen);
    BackgroundTexture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\back.png)");
    HealthTexture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\life.png)");
    ScoreTexture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\score.png)");
    HealthSprite.setTexture(HealthTexture);

    ScoreSprite.setTexture(ScoreTexture);
    ScoreSprite.setScale(0.5f, 0.5f);
    ScoreSprite.setPosition(Engine::GetResolution().x - 256.f, 0.f);
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

Vector2f Engine::GetResolution() {
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    return resolution;
}