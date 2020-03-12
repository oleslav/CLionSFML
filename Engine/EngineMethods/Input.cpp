#include "../Engine.h"

void Engine::input() {
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        Window.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        npc.moveLeft();
    } else {
        npc.stopLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        npc.moveRight();
    } else {
        npc.stopRight();
    }
}