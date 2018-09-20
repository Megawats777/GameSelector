/*
	Developer: James Daniel Semilla
	Date: September 19, 2018
	Github: https://github.com/Megawats777
	Repo link: https://github.com/Megawats777/GameSelector
	Desc: The header file for the User class and helper functions
*/

#ifndef NAMESPACE_USER_CLASS
#define NAMESPACE_USER_CLASS



#include <iostream>
#include <string>
#include "Utility.h"
using namespace std;

namespace MainApp
{
	const int desiredIntensity_Min = 0;
	const int desiredIntensity_Max = 10;

	const int experementalLvl_Min = 0;
	const int experementalLvl_Max = 10;

	class User
	{
		// Private members
	private:
		int desiredIntensity;
		int experimentalLvl;


		// Public members
	public:
		User();


		/*--Getters and Setters--*/

		int getDesiredIntensity();
		void setDesiredIntensity(int desiredIntensity);

		int getExperimentalLvl();
		void setExperimentalLvl(int experimentalLvl);

		/*--Getters and Setters End--*/

	};


	// Helper functions

	// Display user position
	// Parameters: pos
	// pos = 1 : / Configuration
	// pos = 2 : / Configuration / Result
	// pos = 3 : / Configuration / Result / Try Again
	void displayUserPosition(int pos);
}


#endif