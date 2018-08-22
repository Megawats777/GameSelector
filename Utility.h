// The header for a set of utility functions

#ifndef NAMESPACE_UTILITY
#define NAMESPACE_UTILITY

#ifdef _WIN32
#include <Windows.h>

#else
#include <unistd.h>

#endif



namespace Utility
{
	// Perform a delay
	void delay(unsigned seconds);



}


#endif
