#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "BlankPiece.h"
#include "Board.h"
#include "YellowPiece.h"
#include "RedPiece.h"

using std::cout;



class Menu
{
public:

	void runApp()
	{
		menu();
	}

	void instructions(sf::RenderWindow &window);

	void start(sf::RenderWindow& window);

	void win(sf::RenderWindow& window, std::string winner);

private:

	void menu();

};