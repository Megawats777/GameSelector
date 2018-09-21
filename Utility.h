/*
	Developer: James Daniel Semilla
	Date: September 19, 2018
	Github: https://github.com/Megawats777
	Repo link: https://github.com/Megawats777/GameSelector
	Desc: The header file for the utility library
*/

#ifndef NAMESPACE_UTILITY
#define NAMESPACE_UTILITY

#include <iostream>
#include <string>
#include <math.h>

#ifdef _WIN32
#include <Windows.h>

#else
#include <unistd.h>

#endif


using namespace std;




namespace Util
{
	const int dashedLineDefaultWidth = 50;


	// Perform a delay
	// Set the length of the delay with the seconds parameter
	// Ex: delay(2.5f) - this sets the delay to be 2.5 seconds
	void delay(float seconds);

	// Indent text
	// Use with cout
	// Ex: (cout << indentText(3) << "Hello")
	string indentText(int size);

	// Check if number is whole
	bool isWholeNumber(double num);

	// Print dashed line
	void printDashedLine(int size, bool printNewLine = true);

	// Clear the console
	// WARNING: this function may not work with non windows platforms
	void clearConsole();

	// Show continue prompt
	void showContinuePrompt(bool overridePromptMessage = false, string newPromptMessage = "");
}


#endif
