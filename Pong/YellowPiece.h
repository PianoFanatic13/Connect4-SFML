#pragma once

#include "BlankPiece.h"



class YellowPiece : public BlankPiece
{
public:

    YellowPiece(int newX, int newY) : BlankPiece(newX, newY)
    {
        xPos = newX;
        yPos = newY;
    }


	void loadSprite();

private:


};