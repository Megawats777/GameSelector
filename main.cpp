// The main entry point of the program


#include <iostream>
#include <time.h>
#include "Game.h"
#include "User.h"
using namespace std;
using namespace MainApp;

const int gameListSize = 21;


// Forward declare functions
void performUserInput(User& user);
void selectGame(User& user, Game* gameList);
void checkGameWeirdness(Game& game, User& user);
void showContinuePrompt();
void showRepeatPrompt(bool& loopControlVar);
void clearConsole();


int main()
{
	Game* gameList = new Game[gameListSize];

	setGameProperties(gameList[0], "Rainbow Six Siege", 10, 3);
	setGameProperties(gameList[1], "CSGO", 10, 2);
	
	setGameProperties(gameList[2], "Vanquish", 9, 5);
	setGameProperties(gameList[3], "Mirror's Edge", 9, 4);
	
	setGameProperties(gameList[4], "Nier Automata", 8, 9);
	setGameProperties(gameList[5], "Warframe", 8, 7);
	
	setGameProperties(gameList[6], "Superhot", 7, 10);
	setGameProperties(gameList[7], "The Division", 7, 3);
	
	setGameProperties(gameList[8], "The Phantom Pain", 6, 9);
	setGameProperties(gameList[9], "GRID", 6, 2);

	setGameProperties(gameList[10], "Skate 2", 5, 3);
	setGameProperties(gameList[11], "Star Wars Battlefront 2 (The real one.)", 5, 4);
	
	setGameProperties(gameList[12], "Gran Turismo 5", 4, 2);
	setGameProperties(gameList[13], "Little Big Planet", 4, 7);

	setGameProperties(gameList[14], "Portal", 3, 6);
	setGameProperties(gameList[15], "Hexic", 3, 2);

	setGameProperties(gameList[16], "XCOM Enemy Unknown", 2, 6);
	setGameProperties(gameList[17], "Kerbal Space Program", 2, 5);
	setGameProperties(gameList[18], "Flower", 2, 5);

	setGameProperties(gameList[19], "Tonka Construction 2", 1, 4);
	setGameProperties(gameList[20], "Bob the Builder: Can we fix it?", 1, 2);

	User user;

	bool repeat = false;


	// Show the welcome screen
	cout << "Welcome to Game Selector!" << endl;
	cout << endl;
	cout << "By: James Daniel Semilla" << endl;
	cout << endl;

	showContinuePrompt();
	clearConsole();

	// Application loop
	do
	{
		performUserInput(user);
		selectGame(user, gameList);

		cout << endl;
		clearConsole();

		showRepeatPrompt(repeat);
		
	} while (repeat == true);


	showContinuePrompt();


	delete[] gameList;
	gameList = nullptr;

	return 0;
}


// Perform user input
void performUserInput(User& user)
{
	int desiredIntensityAnswer = 0;
	int desiredExperimentalLvl = 0;
	bool validInput = false;

	// Get the desired intensity
	while (validInput == false)
	{
		cout << "From a scale of 0 to 10 what is your desired intensity: ";
		cin >> desiredIntensityAnswer;

		// If the input is incorrect
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ERROR: Please enter a whole number." << endl;
			cout << endl;
		}

		else if (desiredIntensityAnswer < desiredIntensity_Min || desiredIntensityAnswer > desiredIntensity_Max)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ERROR Please enter a number between 0 and 10." << endl;
			cout << endl;
		}


		// If input is correct
		else
		{
			validInput = true;
			user.setDesiredIntensity(desiredIntensityAnswer);
		}

	}

	cout << endl;

	validInput = false;


	// Get the desired experimental level
	while (validInput == false)
	{
		cout << "From a scale of 0 to 10 how experimental do you wanna get: ";
		cin >> desiredExperimentalLvl;

		// If the input is incorrect
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a whole number." << endl;
		}

		else if (desiredExperimentalLvl < experementalLvl_Min || desiredExperimentalLvl > experementalLvl_Max)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a number between 0 and 10." << endl;
		}


		// If input is correct
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			validInput = true;
			user.setExperimentalLvl(desiredExperimentalLvl);
		}
	}

	cout << endl;
}

// Select a game
void selectGame(User& user, Game* gameList)
{
	if (gameList != nullptr)
	{
		// A list of game candidates
		Game* gameCandidates = nullptr;
		int gameCandidateListSize = 0;

		Game selectedGame;


		// Go through the given game list
		for (int i = 0; i < gameListSize; i++)
		{
			// If a game's intensity and weirdness
			// are equal to the player's desired intensity
			if (doesGameMatchDesiredIntensity(gameList[i], user))
			{
				// Increase the game candidate list size
				gameCandidateListSize++;
			}
		}

		// If no games were found
		if (gameCandidateListSize == 0)
		{
			cout << "No games found." << endl;
			showContinuePrompt();
		}

		// Otherwise
		// add games to game candidates list
		else
		{
			int candidateIndex = 0;
			gameCandidates = new Game[gameCandidateListSize];

			for (int i = 0; i < gameListSize; i++)
			{

				if (doesGameMatchDesiredIntensity(gameList[i], user))
				{
					copyGameProperties(gameCandidates[candidateIndex], gameList[i]);
					candidateIndex++;
				}

			}


			// Select a game from the game candidates list
			srand(time(NULL));
			int selectionIndex = rand() % gameCandidateListSize;
			copyGameProperties(selectedGame, gameCandidates[selectionIndex]);

			cout << "Selected game:" << endl << endl;
			gameCandidates[selectionIndex].display(false, false);
			cout << endl;

			// Check game weirdness
			checkGameWeirdness(selectedGame, user);
			cout << endl;
		
			displayEnjoymentMessage(selectedGame);
			cout << endl;
		
			showContinuePrompt();
		}

		delete[] gameCandidates;
		gameCandidates = nullptr;

	}

	else
	{
		cout << "No game list given." << endl;
	}
}


// Check game weirdness
void checkGameWeirdness(Game& game, User& user)
{
	// If a game's weirdness is higher that the user's
	// desired experemental lvl
	if (game.getWeirdness() > user.getExperimentalLvl())
	{
		int weirdnessDifference = game.getWeirdness() - user.getExperimentalLvl();

		// If the weirdness difference
		// is greater than 2
		if (weirdnessDifference > 2)
		{
			cout << "This game's weirdness might be too much for you." << endl;
		}


		// Otherwise
		else
		{
			cout << "This game might be a little too weird for you." << endl;
		}
	}
}

// Show continue prompt
void showContinuePrompt()
{
	cout << "Press enter to continue: ";
	cin.ignore();
}


// Show repeat prompt
void showRepeatPrompt(bool& loopControlVar)
{
	bool validInput = false;
	int response = -1;

	while (validInput == false)
	{
		cout << "Do you want to look for another game?" << endl;
		cout << "Press 1 for yes." << endl;
		cout << "Press 2 for no." << endl;
		cout << "Response: ";
		cin >> response;


		// If input is incorrect
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a number." << endl;
			cout << endl;
		}

		// If input is correct
		else
		{
			if (response == 1)
			{
				cin.clear();
				cin.ignore(1000, '\n');

				validInput = true;
				cout << "Restarting..." << endl;
				loopControlVar = true;
				showContinuePrompt();
				cout << endl << endl;
				clearConsole();
			}

			else if (response == 2)
			{
				cin.clear();
				cin.ignore(1000, '\n');

				validInput = true;
				loopControlVar = false;
				cout << endl;
				cout << "Thank you for your time!" << endl;
				cout << endl;
			}

			// If a number that was not 1 or 2 was entered
			else
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Please enter a number that is 1 or 2." << endl;
				cout << endl;
			}
		}
	}
}

// Clear console
void clearConsole()
{
#ifdef _WIN32
	system("cls");
#endif

#ifdef linux
	system("clear");
#endif

}
