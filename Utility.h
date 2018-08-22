// The header for a set of utility functions

#ifndef NAMESPACE_UTILITY
#define NAMESPACE_UTILITY

#include <iostream>
#include <string>

#ifdef _WIN32
#include <Windows.h>

#else
#include <unistd.h>

#endif


using namespace std;




namespace Util
{
	// Perform a delay
	void delay(float seconds);

	// Indent text
	string indentText(int size);
}


#endif
