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
}