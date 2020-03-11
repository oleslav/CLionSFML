#include "NPC.h"
#include "Engine.h"

NPC::NPC() {
    LeftPressed = false;
    RightPressed = false;
    Speed = 5000;
    // Associate a texture with the sprite
    Texture.loadFromFile(R"(C:\Users\Oleslav Boychuk\CLionProjects\CLionSFML\Media\bob.png)");
    Texture.setSmooth(true);
    // Associate the sprite with the texture
    NPC_Sprite.setTexture(Texture);

    // Set the NPC's starting position
    Position.x = 427.5;
    Position.y = 750;

}

// Make the private spite available to the draw() function
Sprite NPC::getSprite() {
    return NPC_Sprite;
}

void NPC::moveLeft() {
    LeftPressed = true;
}

void NPC::moveRight() {
    RightPressed = true;
}

void NPC::stopLeft() {
    LeftPressed = false;
}

void NPC::stopRight() {
    RightPressed = false;
}

// Move NPC based on the input this frame,
// the time elapsed, and the speed
void NPC::update(float elapsedTime) {
    if (RightPressed &&  Position.x + 150 < Engine::GetResolution().x) {
        Position.x += Speed * elapsedTime;
        NPC_Sprite.setTextureRect(IntRect(150, 0, -150, 192));
    }
    if (LeftPressed && Position.x >= 0) {
        Position.x -= Speed * elapsedTime;
        NPC_Sprite.setTextureRect(IntRect(0, 0, 150, 192));
    }
    // Now move the sprite to its new position
    NPC_Sprite.setPosition(Position);
}

Vector2f NPC::getPosition() {
    return Position;
}
