// The header for the Game class

#ifndef NAMESPACE_GAME_CLASS
#define NAMESPACE_GAME_CLASS

#include <iostream>
#include <cstring>
#include "User.h"

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
		void display(bool showHeader = true, bool showNameHeader = true);

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
}


#endif 
