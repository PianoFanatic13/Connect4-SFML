#pragma once

#include "BlankPiece.h"
#include "YellowPiece.h"
#include "RedPiece.h"
#include "windows.h"
#include <SFML/Audio.hpp>

// Inherent from sf::RectangleShape
class Board : public sf::RectangleShape
{

public:

    // Board constructor
    Board(sf::Vector2f& newSize, sf::Vector2f& newPosition, sf::Color&& newColor) : RectangleShape(newSize)
    {
        setFillColor(newColor);
        setPosition(newPosition);

        // Sets the starting positions to what is passed in, subtracting from the Y to line up with the board
        int startX = newPosition.x , startY = newPosition.y - 85;

        for (int i = 0; i < 6; i++)
        {
            startY += 90;
            startX = newPosition.x - 129;

            // Places the pieces
            for (int j = 0; j < 7; j++)
            {
                startX += 135;
                arr[i][j] = new BlankPiece(startX, startY);
                arr[i][j]->loadSprite();
            }
        }
    }

    Piece* getPiece(int x, int y);

    Piece* arr[6][7];

    void makeYellow(int x, int y);

    void makeRed(int x, int y);

    bool winCheck(int x, int y, sf::Color color);

    bool straightCheck(int x, int y, sf::Color color);

    bool sidewaysCheck(int x, int y, sf::Color color);

    bool diagnolCheck(int x, int y, sf::Color color);



private:


};