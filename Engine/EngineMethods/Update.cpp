#include "../Engine.h"
#include "../../Object/FallingObject.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
    npc.update(dtAsSeconds);
    fallingObject[0].update(dtAsSeconds);
    fallingObject[1].update(dtAsSeconds);
    fallingObject[2].update(dtAsSeconds);
}