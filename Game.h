/*
	Developer: James Daniel Semilla
	Date: September 19, 2018
	Github: https://github.com/Megawats777
	Repo link: https://github.com/Megawats777/GameSelector
	Desc: The header file for the Game class and helper functions
*/

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
		bool hasDevNote;
		string devNote;
		size_t processedDevNoteSize;

		// Public members
	public:
		Game();
		Game(char* name, int intensity, int weirdness, bool hasDevNote, string devNote);
		void display(bool showHeader = true, bool showNameHeader = true, bool indentContent = false);
		void displayDevNote();

		/*--Getters and Setters Members--*/

		char* getName();
		void setName(char* name);

		int getIntensity();
		void setIntensity(int intensity);

		int getWeirdness();
		void setWeirdness(int weirdness);


		bool getHasDevNote();
		void setHasDevNote(bool hasDevNote);


		string getDevNote();
		void setDevNote(string devNote);

		size_t getProcessedDevNoteSize();

		/*--Getters and Setters Members End--*/

	};


	// Helper functions
	void setGameProperties(Game& game, char* name, int intensity, int weirdness, bool hasDevNote = false, string devNote = "");
	bool doesGameMatchDesiredIntensity(Game& game, User& user);
	void copyGameProperties(Game& destination, Game& source);
	void displayEnjoymentMessage(Game& game);
}


#endif 
