// The header for a set of utility functions

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
	void delay(float seconds);

	// Indent text
	string indentText(int size);

	// Check if number is whole
	bool isWholeNumber(double num);

	// Print dashed line
	void printDashedLine(int size, bool printNewLine = true);

	// Clear the console
	void clearConsole();

	// Show continue prompt
	void showContinuePrompt();
}


#endif
