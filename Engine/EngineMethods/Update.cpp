#include "../Engine.h"
#include <iostream>

using namespace sf;
using namespace Collision;

void Engine::update(float dtAsSeconds)
{
    npc.update(dtAsSeconds);
    for (auto & i : fallingObject) {
        i->update(dtAsSeconds);
        if(BoundingBoxTest(npc.getSprite(), i->getSprite())) {
            health += i->getHealth();
            score += i->getScore();
            i->SetStartPosition();
        }
    }
    health_text.setString(std::to_string(health));
    score_text.setString(std::to_string(score));
    if(health <= 0){
        isGameEnd = true;
    }
}