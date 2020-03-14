#include "../Engine.h"

void Engine::draw() {
    Window.clear(Color::White);
    Window.draw(BackgroundSprite);
    auto BobSprite = npc.getSprite();
    BobSprite.setScale(sf::Vector2f(approximation_x * 0.5f, approximation_y * 0.5f));
    Window.draw(BobSprite);
    for (auto &i : fallingObject) {
        Window.draw(i->getSprite());
    }
    Window.draw(HealthSprite);
    Window.draw(ScoreSprite);

    Window.draw(health_text);
    Window.draw(score_text);

    Window.display();
}