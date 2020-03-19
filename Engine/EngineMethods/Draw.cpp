#include "../Engine.h"

void Engine::draw() {
    Window.clear(Color::White);
    Window.draw(BackgroundSprite);
    Window.draw(npc.getSprite());
    for (auto &i : fallingObject) {
        Window.draw(i->getSprite());
    }
    Window.draw(HealthSprite);
    Window.draw(ScoreSprite);
    Window.draw(health_text);
    Window.draw(score_text);
    Window.display();
}

void Engine::PrintScore() {
    Text end_game_text;
    end_game_text.setString("Game\nOver");
    end_game_text.setFillColor(Color::White);
    sf::FloatRect textRect = end_game_text.getLocalBounds();
    end_game_text.setOrigin(textRect.left + textRect.width/2.0f,
                            textRect.top  + textRect.height/2.0f);
    end_game_text.setPosition(sf::Vector2f(Engine::GetResolution().x/2.0f,Engine::GetResolution().y/2.0f));
    end_game_text.setFont(font);
    end_game_text.setStyle(sf::Text::Regular);
    end_game_text.setCharacterSize(90 * (Engine::GetResolution().x / 1920));
    Window.draw(end_game_text);
    Window.display();
}