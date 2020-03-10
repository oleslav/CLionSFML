#include "Engine.h"

void Engine::input() {
    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        m_Window.close();
    }

    // Handle the player moving
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        m_Bob.moveLeft();
    } else {
        m_Bob.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        m_Bob.moveRight();
    } else {
        m_Bob.stopRight();
    }

//    if (Keyboard::isKeyPressed(Keyboard::Right)) {
//        m_Bob.
//    }

}