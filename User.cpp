// The implementation file for the User class

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
		cout << Util::indentText(1);

		if (pos == 1)
		{
			cout << "/ Configuration" << endl;
		}

		else if (pos == 2)
		{
			cout << "/ Configuration / Result" << endl;
		}

		else if (pos == 3)
		{
			cout << "/ Configuration / Result / Try Again" << endl;
		}

		else
		{
			cout << "Invalid position" << endl;
		}

		cout << endl;
	}


}
