#include "BlankPiece.h"
#include "RedPiece.h"
#include "YellowPiece.h"
#include "Board.h"


void testYellowPiece()
{
	// Make a yellow test piece with position 0,0
	YellowPiece testPiece(0,0);

	// If filled equals false, first test case passed
	if (testPiece.getFilled() == false)
	{
		cout << "First test case passed for Yellow Piece" << std::endl;
	}
	else
	{ 
		cout << "First test case failed for Yellow Piece" << std::endl;
	}

	// If the radius is equal to 40, second test case pased
	if (testPiece.getRadius() == 40)
	{
		cout << "Second test case passed for Yellow Piece" << std::endl;
	}
	else
	{
		cout << "Second test case failed for Yellow Piece" << std::endl;
	}

	// If the the x and y are still 0 and 0, thirs test case passed
	if (testPiece.getX() == 0 && testPiece.getY() == 0)
	{
		cout << "Third test case passed for Yellow Piece" << std::endl;
	}
	else
	{
		cout << "Third test case failed for Yellow Piece" << std::endl;
	}
}



void testRedPiece()
{
	// Make a new red piece
	RedPiece testPiece(0, 0);

	// If the filled is false, first test case passed
	if (testPiece.getFilled() == false)
	{
		cout << "First test case passed for Red Piece" << std::endl;
	}
	else
	{
		cout << "First test case failed for Red Piece" << std::endl;
	}

	// If the radius is 40, second test case passed
	if (testPiece.getRadius() == 40)
	{
		cout << "Second test case passed for Red Piece" << std::endl;
	}
	else
	{
		cout << "Second test case failed for Red Piece" << std::endl;
	}

	// If the x and y are both still 0, third test case passed
	if (testPiece.getX() == 0 && testPiece.getY() == 0)
	{
		cout << "Third test case passed for Red Piece" << std::endl;
	}
	else
	{
		cout << "Third test case failed for Red Piece" << std::endl;
	}
}


void testVerticalWin()
{
	// Make a new board
	Board board(sf::Vector2f(900, 550), sf::Vector2f(150, 175), sf::Color(0, 0, 255));

	// Make a stack of pieces (on the left chunk of the board)
	for (int i = 5; i > 1; i--)
	{
		board.makeRed(i, 0);
	}

	// Check if someone has won, if so, we passed the test case
	if (board.winCheck(2, 0, sf::Color::Red))
	{
		cout << "Vetical win check passed" << std::endl;
	}
	else
	{
		cout << "Vertical win check failed" << std::endl;
	}

}

void testHorizontalWin()
{
	Board board(sf::Vector2f(900, 550), sf::Vector2f(150, 175), sf::Color(0, 0, 255));

	sf::Color yellow = sf::Color::Yellow;
	sf::Color red = sf::Color::Red;


	//Placing red pieces in last row, should be a win
	board.makeRed(5, 0);
	board.makeRed(5, 1);
	board.makeRed(5, 2);
	board.makeRed(5, 3);

	bool success = board.sidewaysCheck(5, 3, red);

	if (success)
	{
		cout << "Horizontal Win Detected, Test Passed\n";
	}
	else
	{
		cout << "Horizontal Win Not Detected, Test Failed\n";
	}
}


void testDiagonalWin()
{
	// Make a new board
	Board board(sf::Vector2f(900, 550), sf::Vector2f(150, 175), sf::Color(0, 0, 255));

	// Make a diagonal from bottom left going up
	board.makeRed(5, 0);
	board.makeRed(4, 1);
	board.makeRed(3, 2);
	board.makeRed(2, 3);

	// Run a winCheck, if it returns true we passed
	if (board.winCheck(2, 3, sf::Color::Red))
	{
		cout << "Diagonal win check passed" << std::endl;
	}
	else
	{
		cout << "Diagonal win check failed" << std::endl;
	}
}

