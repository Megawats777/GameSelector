// The implementation file for the game class

#define _CRT_SECURE_NO_WARNINGS

#define PARAM_MIN 0
#define PARAM_MAX 10


#include "Game.h"


namespace MainApp
{
	// Constructors
	Game::Game()
	{
		name = "No game name assigned.";
		intensity = 0;
		weirdness = 0;
	}

	Game::Game(char* name, int intensity, int weirdness)
	{
		this->name = "No game name assigned.";
		this->intensity = 0;
		this->weirdness = 0;

		if (name != nullptr)
		{
			int nameLength = strlen(name);

			if (nameLength > 0 && intensity > -1 && weirdness > -1)
			{
				this->name = name;
				setIntensity(intensity);
				setWeirdness(weirdness);
			}
			else
			{
				Game();
			}
		}

		else
		{
			Game();
		}
	}


	// Display function
	void Game::display(bool showHeader, bool showNameHeader, bool indentContent)
	{
		if (name != nullptr)
		{
			if (strlen(name) > 0 || intensity > -1 || weirdness > -1)
			{
				if (showHeader == true)
				{
					cout << "Game Properties" << endl;
				}

				if (showNameHeader == true)
				{
					cout << "Name: ";
				}

				
				indentContent == true ? cout << Util::indentText(5) : cout << "";
				cout << name << endl;
				cout << endl;

				indentContent == true ? cout << Util::indentText(5) : cout << "";
				cout << "Intensity: " << intensity << endl;

				indentContent == true ? cout << Util::indentText(5) : cout << "";
				cout << "Weirdness: " << weirdness << endl;
			}
		}

	}

	/*--Getters and Setters--*/

	char* Game::getName()
	{
		return name;
	}

	void Game::setName(char * name)
	{
		if (name != nullptr)
		{
			if (strlen(name) > 0)
			{
				this->name = name;
			}

			else
			{
				this->name = "No name assigned.";
			}
		}

		else
		{
			this->name = "No name assigned.";
		}
	}

	int Game::getIntensity()
	{
		return intensity;
	}

	void Game::setIntensity(int intensity)
	{
		if (intensity < PARAM_MIN)
		{
			this->intensity = PARAM_MIN;
		}

		else if (intensity > PARAM_MAX)
		{
			this->intensity = PARAM_MAX;
		}

		else
		{
			this->intensity = intensity;
		}

	}




	int Game::getWeirdness()
	{
		return weirdness;
	}

	void Game::setWeirdness(int weirdness)
	{
		if (weirdness < PARAM_MIN)
		{
			this->weirdness = PARAM_MIN;
		}

		else if (weirdness > PARAM_MAX)
		{
			this->weirdness = PARAM_MAX;
		}

		else
		{
			this->weirdness = weirdness;
		}

	}



	/*--Getters and Setters End--*/


	// Helper functions


	void setGameProperties(Game & game, char * name, int intensity, int weirdness)
	{
		game.setName(name);
		game.setIntensity(intensity);
		game.setWeirdness(weirdness);
	}

	bool doesGameMatchDesiredIntensity(Game& game, User& user)
	{
		return game.getIntensity() == user.getDesiredIntensity();
	}

	void copyGameProperties(Game& destination, Game& source)
	{
		destination.setName(source.getName());
		destination.setIntensity(source.getIntensity());
		destination.setWeirdness(source.getWeirdness());
	}


	void displayEnjoymentMessage(Game& game)
	{
		int gIntensity = game.getIntensity();
		string* possibleMessages = new string[2];
		string selectedMessage;

		if (gIntensity == 10 || gIntensity == 9)
		{
			possibleMessages[0] = "Enjoy and don't get a heart attack!";
			possibleMessages[1] = "You may start to sweat...";
		}

		else if (gIntensity == 8 || gIntensity == 7)
		{
			possibleMessages[0] = "Have a fun time!";
			possibleMessages[1] = "Enjoy!";
		}

		else if (gIntensity == 6 || gIntensity == 5)
		{
			possibleMessages[0] = "Sit back and enjoy!";
			possibleMessages[1] = "Relax and have fun!";
		}

		else if (gIntensity == 4 || gIntensity == 3)
		{
			possibleMessages[0] = "At least you won't get a heart attack from this game.";
			possibleMessages[1] = "Enjoy a calm and soothing experience!";
		}

		else if (gIntensity == 2 || gIntensity == 1)
		{
			possibleMessages[0] = "Enjoy a REALLY calming experience!";
			possibleMessages[1] = "Prepare for a nap...";
		}

		// Select the message to use
		srand(time(NULL));
		int selectionIndex = rand() % 2;
		selectedMessage = possibleMessages[selectionIndex];

		cout << Util::indentText(3);
		cout << selectedMessage << endl;

		delete[] possibleMessages;
		possibleMessages = nullptr;
	}

}
