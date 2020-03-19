#include "Engine.h"
#include <windows.h>
#include <iostream>

Engine *Engine::_instance = nullptr;

Engine *Engine::Instance() {
    if (_instance == nullptr) {
        _instance = new Engine;
    }
    return _instance;
}

Engine::Engine() {
    isGameEnd = false;
    score = 0;
    health = 50;
    fillVector();
    setTextureSettings();
    LoadTexturesAndSetSprites();
    setFlexibleScale();
}

void Engine::start() {
    Clock clock;
    while (Window.isOpen()) {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
        if(isGameEnd){
            std::cout << "Not found ";
            PrintScore();
            Sleep(3000);
            Window.close();
        }
    }
}

Vector2f Engine::GetResolution() {
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    return resolution;
}

void Engine::LoadTexturesAndSetSprites() {
    font.loadFromFile(R"(C:\Windows\Fonts\arial.ttf)");
    BackgroundTexture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\back.png)");
    HealthTexture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\life.png)");
    ScoreTexture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\score.png)");
    HealthSprite.setTexture(HealthTexture);
    ScoreSprite.setTexture(ScoreTexture);
    BackgroundSprite.setTexture(BackgroundTexture);
}

void Engine::setTextureSettings() {
    health_text.setFillColor(Color::White);
    health_text.setCharacterSize(50.f * (Engine::GetResolution().x / 1920));
    score_text.setCharacterSize(50.f * (Engine::GetResolution().x / 1920));
    score_text.setFillColor(Color::Black);
    health_text.setStyle(sf::Text::Bold);
    score_text.setStyle(sf::Text::Bold);
    score_text.setPosition(Engine::GetResolution().x - 200.f * (Engine::GetResolution().x / 1920), 118.f  * (Engine::GetResolution().y / 1280));
    health_text.setPosition(70.f * (Engine::GetResolution().x / 1920), 70.f * (Engine::GetResolution().y / 1280));
    health_text.setFont(font);
    score_text.setFont(font);
}

void Engine::fillVector() {
    fallingObject.push_back(&apple);
    fallingObject.push_back(&coin);
    fallingObject.push_back(&stone[0]);
    fallingObject.push_back(&stone[1]);
    fallingObject.push_back(&stone[2]);
    fallingObject.push_back(&stone[3]);
}

void Engine::setFlexibleScale() {
    Vector2f resolution = GetResolution();
    Window.create(VideoMode(resolution.x, resolution.y),
                  "Simple Game Engine",
                  Style::Fullscreen);
    ScoreSprite.setPosition(Engine::GetResolution().x - 256.f * (resolution.x / 1920), 0.f);
    BackgroundSprite.setScale(Vector2f(resolution.x / 1000, resolution.y / 569));
    HealthSprite.setScale(Vector2f(resolution.x / 1920, resolution.y / 1080));
    ScoreSprite.setScale(Vector2f(resolution.x / 1920, resolution.y / 1080));
}