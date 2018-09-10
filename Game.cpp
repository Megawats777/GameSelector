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
		hasDevNote = false;
		devNote = "";
	}

	Game::Game(char* name, int intensity, int weirdness, bool hasDevNote, string devNote)
	{
		this->name = "No game name assigned.";
		this->intensity = 0;
		this->weirdness = 0;
		this->hasDevNote = false;
		this->devNote = "";

		if (name != nullptr)
		{
			int nameLength = strlen(name);

			if (nameLength > 0 && intensity > -1 && weirdness > -1)
			{
				this->name = name;
				setIntensity(intensity);
				setWeirdness(weirdness);
				this->hasDevNote = hasDevNote;
				this->devNote = devNote;
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


	// Display the developer's note
	void Game::displayDevNote()
	{
		cout << Util::indentText(3) << "Developer's note:" << endl;
		cout << endl;
		cout << Util::indentText(5) << getDevNote() << endl;
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





	bool Game::getHasDevNote()
	{
		return hasDevNote;
	}

	void Game::setHasDevNote(bool hasDevNote)
	{
		this->hasDevNote = hasDevNote;
	}





	string Game::getDevNote()
	{
		if (hasDevNote == true)
		{
			return devNote;
		}
		else
		{
			return "This Game object does not have a dev note.";
		}
	}

	void Game::setDevNote(string devNote)
	{
		this->devNote = devNote;
	}



	/*--Getters and Setters End--*/


	// Helper functions


	void setGameProperties(Game & game, char * name, int intensity, int weirdness, bool hasDevNote, string devNote)
	{
		game.setName(name);
		game.setIntensity(intensity);
		game.setWeirdness(weirdness);
		game.setHasDevNote(hasDevNote);
		game.setDevNote(devNote);
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
		destination.setHasDevNote(source.getHasDevNote());
		destination.setDevNote(source.getDevNote());
	}


	void displayEnjoymentMessage(Game& game)
	{
		int gIntensity = game.getIntensity();
		int pMessagesListSize = 0;
		string* possibleMessages = nullptr;
		string selectedMessage;

		if (gIntensity == 10 || gIntensity == 9)
		{
			pMessagesListSize = 2;
			possibleMessages = new string[pMessagesListSize];
			possibleMessages[0] = "Enjoy and don't get a heart attack!";
			possibleMessages[1] = "You may start to sweat...";
			//possibleMessages[2] = "At least you're on the road to Germany.";
		}

		else if (gIntensity == 8 || gIntensity == 7)
		{
			pMessagesListSize = 2;
			possibleMessages = new string[pMessagesListSize];
			possibleMessages[0] = "Have a fun time!";
			possibleMessages[1] = "Enjoy!";
		}

		else if (gIntensity == 6 || gIntensity == 5)
		{
			pMessagesListSize = 2;
			possibleMessages = new string[pMessagesListSize];
			possibleMessages[0] = "Sit back and enjoy!";
			possibleMessages[1] = "Relax and have fun!";
		}

		else if (gIntensity == 4 || gIntensity == 3)
		{
			pMessagesListSize = 2;
			possibleMessages = new string[pMessagesListSize];
			possibleMessages[0] = "At least you won't get a heart attack from this game.";
			possibleMessages[1] = "Enjoy a calm and soothing experience!";
		}

		else if (gIntensity == 2 || gIntensity == 1)
		{
			pMessagesListSize = 2;
			possibleMessages = new string[pMessagesListSize];
			possibleMessages[0] = "Enjoy a REALLY calming experience!";
			possibleMessages[1] = "Prepare for a nap...";
		}

		else
		{
			pMessagesListSize = 1;
			possibleMessages = new string[pMessagesListSize];
			possibleMessages[0] = "No enjoyment message available.";
		}

		// Select the message to use
		srand(time(NULL));
		int selectionIndex = rand() % pMessagesListSize;
		selectedMessage = possibleMessages[selectionIndex];

		cout << Util::indentText(3);
		cout << selectedMessage << endl;

		delete[] possibleMessages;
		possibleMessages = nullptr;
	}

}
