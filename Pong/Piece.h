#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


using std::cout;




class Piece : public sf::CircleShape
{
public:

    Piece(int newX, int newY) : sf::CircleShape(40)
    {
        xPos = newX;
        yPos = newY;
    }


    virtual void loadSprite() = 0;

    int getX();
    int getY();


    void setX(int newX);
    void setY(int newY);

    bool getFilled();

    void setFilled(bool newFill);


protected:

    int xPos, yPos;

    bool filled = false;
};