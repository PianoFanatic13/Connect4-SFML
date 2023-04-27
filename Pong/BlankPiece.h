#pragma once

#include "Piece.h"

class BlankPiece : public Piece
{

public:

    BlankPiece(int newX, int newY) : Piece(newX, newY)
    {
        xPos = newX;
        yPos = newY;
    }

    virtual void loadSprite();



private:

};