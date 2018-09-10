// The implementation file for the Utility header


#include "Utility.h"



namespace Util
{
	// Perform a delay
	void delay(float seconds)
	{
	#ifdef _WIN32
		Sleep(seconds * 1000);

	#else
		usleep(seconds * 1000000);

	#endif

	}


	// Indent text
	string indentText(int size)
	{
		string indent;

		for (int i = 0; i < size; i++)
		{
			indent += " ";
		}

		return indent;
	}

	// Check if number is whole
	bool isWholeNumber(double num)
	{
		double lowestVal = floor(num);
		double highestVal = ceil(num);
		bool answer = false;

		// If the given number is between the lowest value and the highest value
		if (num > lowestVal && num < highestVal)
		{
			answer = false;
		}

		// If the given number is equal to the lowest val
		else if (num == lowestVal)
		{
			answer = true;
		}



		return answer;
	}


	// Print dashed line
	void printDashedLine(int size, bool printNewLine)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "-";
		}

		if (printNewLine == true)
		{
			cout << endl;
		}
	}

	// Clear console
	void clearConsole()
	{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
	}
}