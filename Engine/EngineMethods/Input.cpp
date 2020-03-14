#include "../Engine.h"
#include "iostream"

void Engine::input() {
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        std::cout << score << "\t" << health << std::endl;
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