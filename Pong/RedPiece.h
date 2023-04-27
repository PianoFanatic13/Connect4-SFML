#pragma once

#include "BlankPiece.h"



class RedPiece : public BlankPiece
{
public:

    RedPiece(int newX, int newY) : BlankPiece(newX, newY)
    {
        xPos = newX;
        yPos = newY;
    }


    void loadSprite();

private:


};