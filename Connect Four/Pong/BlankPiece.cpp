#include "BlankPiece.h"

// Basic loadsprite which is virtual
void BlankPiece::loadSprite()
{
    setPosition(xPos, yPos);
    setFillColor(sf::Color(128, 128, 128));
}

