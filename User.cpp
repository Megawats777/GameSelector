/*
	Developer: James Daniel Semilla
	Date: September 19, 2018
	Github: https://github.com/Megawats777
	Repo link: https://github.com/Megawats777/GameSelector
	Desc: The implementation file for the User class and helper functions
*/

#include "User.h"


namespace MainApp
{
	User::User()
	{
		desiredIntensity = 0;
		experimentalLvl = 0;
	}


	/*--Getters and Setters--*/

	int User::getDesiredIntensity()
	{
		return desiredIntensity;
	}

	void User::setDesiredIntensity(int desiredIntensity)
	{
		this->desiredIntensity = desiredIntensity;
	}



	int User::getExperimentalLvl()
	{
		return experimentalLvl;
	}

	void User::setExperimentalLvl(int experimentalLvl)
	{
		this->experimentalLvl = experimentalLvl;
	}


	/*--Getters and Setters End--*/


	// Display user position
	// Parameters: pos
	// pos = 1 : / Configuration
	// pos = 2 : / Configuration / Result
	// pos = 3 : / Configuration / Result / Try Again
	void displayUserPosition(int pos)
	{
		const int pStatesListSize = 3;

		string positionStates[pStatesListSize];
		positionStates[0] = "Configuration";
		positionStates[1] = "Result";
		positionStates[2] = "Try Again";

		cout << Util::indentText(1);

		// If an invalid position was entered (ex: -1) or > pStatesListSize
		if (pos < 1 || pos > pStatesListSize)
		{
			cout << "Invalid Position...";
		}

		// Otherwise
		else
		{
			for (int i = 0; i < pos; i++)
			{
				cout << "/ " << positionStates[i] << " ";
			}
		}

		cout << endl << endl;
	}


}
