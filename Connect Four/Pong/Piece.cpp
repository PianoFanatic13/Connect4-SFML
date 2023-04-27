#include "Piece.h"


int Piece::getX()
{
	return this->xPos;
}

int Piece::getY()
{
	return this->yPos;
}

void Piece::setX(int newX)
{
	this->xPos = newX;
}

void Piece::setY(int newY)
{
	this->yPos = newY;
}

bool Piece::getFilled()
{
	return this->filled;
}

void Piece::setFilled(bool newFill)
{
	this->filled = newFill;
}