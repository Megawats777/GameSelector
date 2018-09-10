// The main entry point of the program


#include <iostream>
#include <time.h>
#include <string>
#include <math.h>
#include <cstdio>
#include "Game.h"
#include "User.h"
#include "Utility.h"

using namespace std;
using namespace MainApp;


const int gameListSize = 21;


// Forward declare functions
void showWelcomeScreen();
void enterUserProperties(User& user);
void selectGame(User& user, Game* gameList);
void checkGameWeirdness(Game& game, User& user);
void showContinuePrompt();
void showRepeatPrompt(bool& loopControlVar);


int main()
{
	Game* gameList = new Game[gameListSize];

	setGameProperties(gameList[0], "Rainbow Six Siege", 10, 3, true, "Always play ranked.");
	setGameProperties(gameList[1], "CSGO", 10, 2);

	setGameProperties(gameList[2], "Vanquish", 9, 5, true, "Sega and Platinum please make Vanquish 2.");
	setGameProperties(gameList[3], "Mirror's Edge", 9, 4);

	setGameProperties(gameList[4], "Nier Automata", 8, 9, true, "The real game begins after ending B.");
	setGameProperties(gameList[5], "Warframe", 8, 7);

	setGameProperties(gameList[6], "Superhot", 7, 10, true, "Don't play this at 2am.");
	setGameProperties(gameList[7], "The Division", 7, 3);

	setGameProperties(gameList[8], "The Phantom Pain", 6, 9, true, "D-Dog is the best buddy.");
	setGameProperties(gameList[9], "GRID", 6, 2);

	setGameProperties(gameList[10], "Skate 2", 5, 3, true, "Still one of the best skateboarding games ever made.");
	setGameProperties(gameList[11], "Star Wars Battlefront 2 (The real one.)", 5, 4);

	setGameProperties(gameList[12], "Gran Turismo 5", 4, 2, true, "You'll spend more time installing instead of playing.");
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
	showWelcomeScreen();



	// Application loop
	do
	{
		displayUserPosition(1);
		enterUserProperties(user);

		Util::clearConsole();

		displayUserPosition(2);
		selectGame(user, gameList);

		cout << endl;
		Util::clearConsole();

		displayUserPosition(3);
		showRepeatPrompt(repeat);

	} while (repeat == true);


	showContinuePrompt();


	delete[] gameList;
	gameList = nullptr;

	return 0;
}


// Show welcome screen
void showWelcomeScreen()
{
	const string versionText = "1.05";

	cout << Util::indentText(1) << "Loading Game Selector Ver " << versionText << endl;
	cout << endl;

	Util::delay(1.5f);

	cout << Util::indentText(5) << "Welcome to Game Selector!" << endl;
	cout << endl;

	Util::delay(0.25f);
	cout << Util::indentText(5) << "By: James Daniel Semilla" << endl;
	cout << endl << endl;


	Util::delay(0.25f);

	Util::printDashedLine(Util::dashedLineDefaultWidth, true);
	cout << endl;

	showContinuePrompt();
	Util::clearConsole();
}

// Perform user input
void enterUserProperties(User& user)
{
	int dashedLineWidthAddition = 50;

	float desiredIntensityAnswer = 0;
	float desiredExperimentalLvl = 0;
	bool validInput = false;

	// Get the desired intensity
	while (validInput == false)
	{
		cout << Util::indentText(3) << "From a scale of 0 to 10 what is your desired intensity: ";
		cin >> desiredIntensityAnswer;


		// If the input is incorrect
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << Util::indentText(5) << "ERROR: Please enter a number." << endl;
			cout << endl;

			Util::printDashedLine(Util::dashedLineDefaultWidth + dashedLineWidthAddition);
			cout << endl;
		}

		else if (desiredIntensityAnswer < desiredIntensity_Min || desiredIntensityAnswer > desiredIntensity_Max)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << Util::indentText(5) << "ERROR Please enter a number between 0 and 10." << endl;
			cout << endl;

			Util::printDashedLine(Util::dashedLineDefaultWidth + dashedLineWidthAddition);
			cout << endl;
		}


		// If input is correct
		else
		{
			// If the response is not a whole number
			if (Util::isWholeNumber(desiredIntensityAnswer) == false)
			{
				cout << endl;
				cout << Util::indentText(5) << "Answer converted to: " << floor(desiredIntensityAnswer) << endl;
				desiredIntensityAnswer = floor(desiredIntensityAnswer);
			}

			validInput = true;
			user.setDesiredIntensity(desiredIntensityAnswer);
		}

	}

	cout << endl;

	Util::printDashedLine(Util::dashedLineDefaultWidth + dashedLineWidthAddition);
	cout << endl;

	validInput = false;


	// Get the desired experimental level
	while (validInput == false)
	{
		cout << Util::indentText(3) << "From a scale of 0 to 10 how experimental do you wanna get: ";
		cin >> desiredExperimentalLvl;


		// If the input is incorrect
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << Util::indentText(5) << "Please enter a number." << endl;
			cout << endl;

			Util::printDashedLine(Util::dashedLineDefaultWidth + dashedLineWidthAddition);
			cout << endl;
		}

		else if (desiredExperimentalLvl < experementalLvl_Min || desiredExperimentalLvl > experementalLvl_Max)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << Util::indentText(5) << "Please enter a number between 0 and 10." << endl;
			cout << endl;
		
			Util::printDashedLine(Util::dashedLineDefaultWidth + dashedLineWidthAddition);
			cout << endl;
		}


		// If input is correct
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');

			if (Util::isWholeNumber(desiredExperimentalLvl) == false)
			{
				cout << endl;
				cout << Util::indentText(5) << "Answer converted to: " << floor(desiredExperimentalLvl) << endl;
				cout << endl;
				desiredExperimentalLvl = floor(desiredExperimentalLvl);
				
				Util::printDashedLine(Util::dashedLineDefaultWidth + dashedLineWidthAddition);
				cout << endl;
				
				showContinuePrompt();
			}
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
			cout << Util::indentText(3) << "No games found." << endl;
			cout << endl;
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

			cout << Util::indentText(3) << "Selected game:" << endl << endl;
			gameCandidates[selectionIndex].display(false, false, true);
			cout << endl;

			// Check game weirdness
			checkGameWeirdness(selectedGame, user);
			cout << endl;

			displayEnjoymentMessage(selectedGame);
			cout << endl;

			// If the selected game has a developer's note
			if (selectedGame.getHasDevNote() == true)
			{
				cout << endl;
				Util::printDashedLine(Util::dashedLineDefaultWidth);
				cout << endl;
				selectedGame.displayDevNote();
				cout << endl;
				Util::printDashedLine(Util::dashedLineDefaultWidth);
				cout << endl;
			}


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
		cout << Util::indentText(3);

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
	cout << Util::indentText(1) << "Press enter to continue: ";
	cin.ignore(1000, '\n');
}


// Show repeat prompt
void showRepeatPrompt(bool& loopControlVar)
{
	bool validInput = false;
	float response = -1;

	while (validInput == false)
	{
		cout << Util::indentText(3) << "Do you want to look for another game?" << endl;
		cout << endl;
		cout << Util::indentText(3) << "Press 1 for yes." << endl;
		cout << Util::indentText(3) << "Press 2 for no." << endl;
		cout << endl;
		cout << Util::indentText(3) << "Response: ";
		cin >> response;


		// If input is incorrect
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << Util::indentText(5) << "Please enter a number." << endl;
			cout << endl;

			Util::printDashedLine(Util::dashedLineDefaultWidth);
			cout << endl;
		}

		// If input data is correct
		else
		{
			// If a number less than 1 or greater than 2 was entered
			if (response < 1 || response > 2)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << endl;
				cout << Util::indentText(5) << "Please enter a number that is either 1 or 2." << endl;
				cout << endl;

				Util::printDashedLine(Util::dashedLineDefaultWidth);
				cout << endl;
			}

			// Otherwise
			else
			{
				// If the response is not a whole number
				if (Util::isWholeNumber(response) == false)
				{
					cout << endl;
					cout << Util::indentText(5) << "Response converted to: " << floor(response) << endl;
					response = floor(response);
				}

				if (response == 1)
				{

					cin.clear();
					cin.ignore(1000, '\n');

					validInput = true;
					cout << endl;
					cout << Util::indentText(3) << "Restarting..." << endl;
					cout << endl;

					loopControlVar = true;
					Util::printDashedLine(Util::dashedLineDefaultWidth);
					cout << endl;

					showContinuePrompt();
					Util::clearConsole();
				}

				else if (response == 2)
				{
					cin.clear();
					cin.ignore(1000, '\n');

					validInput = true;
					loopControlVar = false;
					cout << endl;
					cout << Util::indentText(5) << "Thank you for your time!" << endl;
					cout << endl;

					Util::printDashedLine(Util::dashedLineDefaultWidth);
					cout << endl;
				}
			}

		}
	}
}

