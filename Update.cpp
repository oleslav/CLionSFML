#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
    npc.update(dtAsSeconds);
    fallingObject[0].update(dtAsSeconds);
    if(fallingObject[0].collision(npc.getPosition())){
        score++;
    }
}