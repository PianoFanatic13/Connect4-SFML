#include "Board.h"

// Returns the piece at the coordinates passed in
Piece* Board::getPiece(int x, int y)
{
	return this->arr[x][y];
}

// Changes a piece from a BlankPiece to a yellow piece in the array
void Board::makeYellow(int x, int y)
{
	// Makes the new yellow piece
	YellowPiece* newPiece = new YellowPiece(0,0);
	
	// Loads sprite
	newPiece->loadSprite();

	// Sets the position to where the piece its replacing is
	newPiece->setPosition(arr[x][y]->getX(), arr[x][y]->getY());

	// Changes the BlankPiece into a yellow piece
	arr[x][y] = newPiece;
}

// Changes a piece from a BlankPiece to a red piece
void Board::makeRed(int x, int y)
{
	// Makes the new red piece
	RedPiece* newPiece = new RedPiece(0, 0);

	// Loads the sprite
	newPiece->loadSprite();

	// Sets the position to where the old BlankPiece was
	newPiece->setPosition(arr[x][y]->getX(), arr[x][y]->getY());

	// Change the blankPiece to a red piece
	arr[x][y] = newPiece;
}

// Check if a player has won - ran after every piece is placed
bool Board::winCheck(int x, int y, sf::Color color)
{
	// Checks for vertical win
	if (straightCheck(x, y, color))
	{
		return true;
	}
	// Checks for horizontal win
	if (sidewaysCheck(x, y, color))
	{
		return true;
	}
	// Checks for a diagonal win
	if (diagnolCheck(x, y, color))
	{
		return true;
	}

	return false;
}

bool Board::straightCheck(int x, int y, sf::Color color)
{	
	// Copy the x value
	int copyX = x;
	// Make the pieceCounter and rowCounter
	int pieceCounter = 0, rowCounter = 0;

	//Up to Down
	while (copyX <= 5 && pieceCounter <= 4)
	{
		// If the array color matches, increment row counter
		if (arr[copyX][y]->getFillColor() == color)
		{
			rowCounter++;
		}
		// Increment piececounter
		pieceCounter++;

		// if the row counter equals 4
		if (rowCounter == 4)
		{
			return true;
		}

		copyX++;
	}
	return false;

}

// Checks horizontal wins
bool Board::sidewaysCheck(int x, int y, sf::Color color)
{
	// Automatically one in the column
	int amountInRow = 1;

	// Quick copy of the Y
	int copyY = y;


	// Get one of the Y's off the original piece
	y--;


	// Not to the edge of the board yet - checking to the left
	if (y > 0)
	{
		while (arr[x][y]->getFillColor() == color)
		{
			amountInRow++;
			y--;
		}

	}

	// reset to the original value and go up one
	y = copyY;
	y++;

	// Not the edge of the board yet - checking to the right
	if(y < 6)
	{
		// While its equal to the color, increment amountinRow and y
		while (arr[x][y]->getFillColor() == color)
		{
			amountInRow++;
			y++;
		}
	}
	// If theres 4 or more, someone won
	if (amountInRow >= 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Board::diagnolCheck(int x, int y, sf::Color color)
{

	//4 Ways to check for a win from a piece that's just been droped:
	//Going Up Right from the piece
	//Going Up Left
	//Going Down Left from the piece
	//Going Down Right from the piece


	int copyX = x, copyY = y;
	//PieceCounter counts how many pieces have been checked in a diagonal, should only go up to 4
	//And diagCounter counts how many diagonal pieces in a row there are from the piece just placed
	int pieceCounter = 0, diagCounter = 0;

	//Down Left to Up Right
	while (copyX >= 0 && copyY <= 6 && pieceCounter <= 4)
	{
		if (arr[copyX][copyY]->getFillColor() == color)
		{
			diagCounter++;
		}

		pieceCounter++;

		if (diagCounter == 4)
		{
			return true;
		}

		copyX--;
		copyY++;
	}


	copyX = x, copyY = y;
	pieceCounter = 0, diagCounter = 0;

	//Up Right to Down Left
	while (copyX <= 5 && copyY >= 0 && pieceCounter <= 4)
	{
		if (arr[copyX][copyY]->getFillColor() == color)
		{
			diagCounter++;
		}

		pieceCounter++;

		if (diagCounter == 4)
		{
			return true;
		}

		copyX++;
		copyY--;
	}


	copyX = x, copyY = y;
	pieceCounter = 0, diagCounter = 0;

	//Down Right to Up Left
	while (copyX >= 0 && copyY >= 0 && pieceCounter <= 4)
	{
		if (arr[copyX][copyY]->getFillColor() == color)
		{
			diagCounter++;
		}

		pieceCounter++;

		if (diagCounter == 4)
		{
			return true;
		}

		copyX--;
		copyY--;
	}


	copyX = x, copyY = y;
	pieceCounter = 0, diagCounter = 0;

	//Up Left to Down Right
	while (copyX <= 5 && copyY <= 6 && pieceCounter <= 4)
	{
		if (arr[copyX][copyY]->getFillColor() == color)
		{
			diagCounter++;
		}

		pieceCounter++;

		if (diagCounter == 4)
		{
			return true;
		}

		copyX++;
		copyY++;
	}


	return false;
}
