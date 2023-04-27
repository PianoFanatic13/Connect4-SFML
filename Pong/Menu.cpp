#include "Menu.h"


void Menu::menu()
{
	// Track which menu option we're on
	int menuOption = 1;

	// Window for the game
	sf::RenderWindow window{ {1200,800 }, "Connect Four" };

	// Textures, one is the logo one is a font
	sf::Texture logoTexture;
	sf::Font textTexture;

	// Sprite and text, for the logo and the start, instructions and exit
	sf::Sprite sprite;
	sf::Text start;
	sf::Text instructions;
	sf::Text exit;

	
	// Change the scale for the image
	sprite.scale(.8, .8);

	// Set the character size of the buttons
	start.setCharacterSize(70);
	instructions.setCharacterSize(70);
	exit.setCharacterSize(70);

	sprite.setPosition(120, 0);

	// Underline the first menu option
	start.setStyle(sf::Text::Underlined);

	// While the window is open
	while (window.isOpen())
	{
		
		sf::Event event;
		// Handles events
		while (window.pollEvent(event))
		{
			// If they close the game
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			// If they press down, check if we can move down the menu
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				// If its less than three
				if (menuOption < 3)
				{
					// On start - change start from underlined to regular and underline instructions
					if (menuOption == 1)
					{
						start.setStyle(sf::Text::Regular);
						instructions.setStyle(sf::Text::Underlined);
						menuOption++;
					}
					// On instructions - change instructions from underlined to regular and underline exit
					else if (menuOption == 2)
					{
						instructions.setStyle(sf::Text::Regular);
						exit.setStyle(sf::Text::Underlined);
						menuOption++;
					}
				}
			}
			// If they press up, check if we can move up
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				//cout << "Up pressed" << std::endl;

				// We can move up if greater than 1
				if (menuOption > 1)
				{
					// On Exit - un-underline exit and underline instructions
					if (menuOption == 3)
					{
						exit.setStyle(sf::Text::Regular);
						instructions.setStyle(sf::Text::Underlined);
						menuOption--;
					}
					// On Instructions - un-underline instructions and underline start
					else if (menuOption == 2)
					{
						instructions.setStyle(sf::Text::Regular);
						start.setStyle(sf::Text::Underlined);
						menuOption--;
					}
					
				}
			}
			// If they press start, bring them to the option that was underlined
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				// Start
				if (menuOption == 1)
				{
					this->start(window);
				}
				// Instructions
				else if (menuOption == 2)
				{
					this->instructions(window);
				}
				// Exit
				else if (menuOption == 3)
				{
					window.close();
				}
			}

		}
		// Clear the window
		window.clear();

		// Load textures
		if (!logoTexture.loadFromFile("Assets/connect-four-wide.png"))
		{
			cout << "error";
		}
		else
		{
			sprite.setTexture(logoTexture);
			window.draw(sprite);
		}
		if (!textTexture.loadFromFile("Assets/Roboto-Black.ttf"))
		{
			cout << "error";
		}
		else
		{
			start.setFont(textTexture);
			start.setString("START");
			start.setPosition(450,250);

			instructions.setFont(textTexture);
			instructions.setString("INSTRUCTIONS");
			instructions.setPosition(320, 370);

			exit.setFont(textTexture);
			exit.setString("EXIT");
			exit.setPosition(480, 490);

			window.draw(start);
			window.draw(instructions);
			window.draw(exit);
		}

		// Display everything that was drawn to the screen
		window.display();

	}

}


// Displays the instructions of the game to the screen
void Menu::instructions(sf::RenderWindow &window)
{
	// The four lines of instructions we need
	std::string inst1 = "1) Players will alternate turns after playing their piece.\nThe goal of the game is to be the first player with four in a row";
	std::string inst2 = "2) On your turn, drop one of your checkers down ANY of the slots in the top of the grid";
	std::string inst3 = "3) Play alternates until one player gets FOUR checkers of their color in a row.\nThe row can be vertical, horizontal or diagnal";
	std::string inst4 = "Press ENTER to continue";

	// Four text lines for the four lines of instructions
	sf::Text instructions1;
	sf::Text instructions2;
	sf::Text instructions3;
	sf::Text instructions4;

	// Font for the text
	sf::Font textTexture;

	sf::Event event;

	bool leave = false;

	// Load textures, set chracter sizes, set string and position
	if (!textTexture.loadFromFile("Assets/Roboto-Black.ttf"))
	{
		cout << "error";
	}
	else
	{
		instructions1.setFont(textTexture);
		instructions1.setCharacterSize(30);
		instructions1.setString(inst1);
		instructions1.setPosition(0, 50);

		instructions2.setFont(textTexture);
		instructions2.setCharacterSize(30);
		instructions2.setString(inst2);
		instructions2.setPosition(0, 150);

		instructions3.setFont(textTexture);
		instructions3.setCharacterSize(30);
		instructions3.setString(inst3);
		instructions3.setPosition(0, 250);

		instructions4.setFont(textTexture);
		instructions4.setCharacterSize(30);
		instructions4.setString(inst4);
		instructions4.setPosition(0, 350);

		// Until they hit enter, leave the screen up
		while (leave != true)
		{
			// Draw the instructions to screen
			window.draw(instructions1);
			window.draw(instructions2);
			window.draw(instructions3);
			window.draw(instructions4);

			// Poll
			window.pollEvent(event);
			
			// If they hit enter, leave instructions
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				leave = true;
			}
			// Display & clear
			window.display();
			window.clear();
		}
	}
}

// Starts the game of connect four
void Menu::start(sf::RenderWindow& window)
{
	// Make the board
	Board board(sf::Vector2f(900, 550), sf::Vector2f(150, 175), sf::Color(0, 0, 255));

	// gameOver variable
	bool gameOver = false;

	// Track player turns
	int turn = 1;

	// Empty winner string for the win functions
	std::string winner = "";

	// Tracks the piece
	int pieceY = 5;
	int pieceLocation = 0;

	// Makes a new piece for players to control
	BlankPiece newPiece(0, 0);

	// Load sprite of newPiece, set the position and change the color
	newPiece.loadSprite();
	newPiece.setPosition(156, 85);
	newPiece.setFillColor(sf::Color::Red);

	// Clear the window
	window.clear();

	// Make two color variables to alternate newPiece color
	sf::Color yellow = sf::Color::Yellow;
	sf::Color red = sf::Color::Red;

	sf::Event event;
	
	// Until someone wins the game, they play
	while (!gameOver)
	{
		
		while (window.pollEvent(event))
		{

			// For moving pieces
			if (event.type == sf::Event::KeyReleased)
			{
				// Move the piece once to the left
				if (event.key.code == sf::Keyboard::Left)
				{
					if (pieceLocation > 0)
					{
						pieceLocation--;

						newPiece.setPosition(newPiece.getPosition().x - 135, 85);
					}
				}
				// Move the piece once to the right
				else if (event.key.code == sf::Keyboard::Right)
				{
					if (pieceLocation < 6)
					{
						pieceLocation++;

						newPiece.setPosition(newPiece.getPosition().x + 135, 85);

					}
				}
				
			}

			// For dropping a piece
			if(event.type == sf::Event::KeyPressed)
			{

				// Player wants to drop a piece
				if (event.key.code == sf::Keyboard::Enter)
				{
					// Checks if the whole column is filled
					if (board.getPiece(0, pieceLocation)->getFilled() != true)
					{
						pieceY = 0;

						// Finds where in the board to drop the piece
						for (int i = 0; i < 6; i++)
						{
							if (!board.getPiece(pieceY, pieceLocation)->getFilled())
							{
								pieceY++;
							}
						}

						// Need to increment down by one, not entirely sure why but I do
						pieceY--;

						// Set the fill to true
						

						if (turn == 1)
						{

							// Make a red piece at the location that a piece is being dropped
							board.makeRed(pieceY, pieceLocation);

							// Increment turn
							turn++;

							// Check for a win
							if (board.winCheck(pieceY, pieceLocation, newPiece.getFillColor()))
							{
								cout << "Red WINS" << std::endl;

								winner = "RED";

								

								gameOver = true;
							}

							// Change the color of newPiece to yellow, signals other players turn 
							newPiece.setFillColor(yellow);
							
						}
						else if (turn == 2)
						{
							// Make the piece being dropped into a yellow
							board.makeYellow(pieceY, pieceLocation);

							// Increment the turn
							turn--;

							// Check for a win
							if( board.winCheck(pieceY, pieceLocation, newPiece.getFillColor()))
							{
								cout << "Yellow WINS" << std::endl;

								winner = "YELLOW";

								gameOver = true;
							}

							// Set the fill color to red
							newPiece.setFillColor(red);
						}
						// Set the piece that was just dropped to filled
						board.arr[pieceY][pieceLocation]->setFilled(true);

					}
				}
			}


			// Draw the board, the board pieces and the piece the player is controlling
			window.draw(board);
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					window.draw(*board.arr[i][j]);
				}
			}
			window.draw(newPiece);


			// Display everything thats been drawn
			window.display();
			
			// Clear the screen
			window.clear();
		}
	}

	// Someone won the game, move onto the win functions
	win(window, winner);
}

void Menu::win(sf::RenderWindow& window, std::string winner)
{
	// The two things that will be said when someone wins
	std::string inst1 = "RED WINS!";
	std::string inst2 = "YELLOW WINS!";
	
	// Text to be changed depending on who wins
	sf::Text winText;

	// Text that will say press enter to continue
	sf::Text enterToContinue;

	// Font
	sf::Font textTexture;

	// Sprite & Texture
	sf::Texture texture;
	sf::Sprite sprite;

	// Set scale and position of sprite
	sprite.scale(.8, .8);
	sprite.setPosition(120, 0);

	// Event
	sf::Event event;

	// Check if they've hit enter to leave
	bool leave = false;

	// Set string, character size & position of the enter to continue text
	enterToContinue.setString("PRESS ENTER TO CONTINUE");
	enterToContinue.setCharacterSize(50);
	enterToContinue.setPosition(240, 700);

	// If red won, change the text so that it says red won
	if (winner == "RED")
	{
		winText.setString(inst1);
		winText.setColor(sf::Color::Red);
		winText.setPosition(230, 500);
	}
	// If yellow won, change the text so that it says yellow won
	else 
	{
		winText.setString(inst2);
		winText.setColor(sf::Color::Yellow);
		winText.setPosition(60, 500);
	}

	// Check for texture loading
	if (!texture.loadFromFile("Assets/connect-four-wide.png"))
	{
		cout << "error";
	}
	else
	{
		sprite.setTexture(texture);	
	}

	if (!textTexture.loadFromFile("Assets/Roboto-Black.ttf"))
	{
		cout << "error";
	}
	else
	{
		// Set font, character size 
		winText.setFont(textTexture);
		winText.setCharacterSize(160);
		enterToContinue.setFont(textTexture);

		// Draw everything to the screen and display it
		window.draw(winText);
		window.draw(sprite);
		window.draw(enterToContinue);
		window.display();

		// Play the victory sound
		bool played = PlaySound(TEXT("victory.wav.wav"), NULL, SND_SYNC);

		// Wait for the player to hit enter to leave
		while (leave != true)
		{
			window.draw(winText);
			window.draw(sprite);
			window.draw(enterToContinue);

			window.pollEvent(event);

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				leave = true;
			}
			window.display();
			window.clear();
		}
	}
}