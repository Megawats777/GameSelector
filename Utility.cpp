// The implementation file for the Utility header


#include "Utility.h"


namespace Utility
{
	// Perform a delay
	void delay(unsigned seconds)
	{
		#ifdef _WIN32
			Sleep(seconds * 1000);

		#else
			usleep(seconds * 1000000);

		#endif

	}
}