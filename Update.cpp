#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
    m_Bob.update(dtAsSeconds);
    if(isFallingObjectExist){
        isFallingObjectExist = m_fallingObject.update(dtAsSeconds);
    }
}