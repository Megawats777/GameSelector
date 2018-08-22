// The header for the Game class

#ifndef NAMESPACE_GAME_CLASS
#define NAMESPACE_GAME_CLASS

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <time.h>
#include "User.h"
#include "Utility.h"

using namespace std;


namespace MainApp
{
	class Game
	{
		// Private members
	private:
		char* name;
		int intensity;
		int weirdness;

		// Public members
	public:
		Game();
		Game(char* name, int intensity, int weirdness);
		void display(bool showHeader = true, bool showNameHeader = true, bool indentContent = false);

		/*--Getters and Setters Members--*/

		char* getName();
		void setName(char* name);

		int getIntensity();
		void setIntensity(int intensity);

		int getWeirdness();
		void setWeirdness(int weirdness);

		/*--Getters and Setters Members End--*/

	};


	// Helper functions
	void setGameProperties(Game& game, char* name, int intensity, int weirdness);
	bool doesGameMatchDesiredIntensity(Game& game, User& user);
	void copyGameProperties(Game& destination, Game& source);
	void displayEnjoymentMessage(Game& game);
}


#endif 
