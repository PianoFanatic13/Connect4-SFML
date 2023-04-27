#include "Menu.h"
#include "TestCases.h"



int main(void)
{
	// Make the menu
	Menu menu;

	// Run the game
	menu.runApp();

	testYellowPiece();

	testRedPiece();

	testVerticalWin();

	testHorizontalWin();

	testDiagonalWin();

	bool played = PlaySound(TEXT("sickoBamba.wav"), NULL, SND_SYNC);

	return 0;
}