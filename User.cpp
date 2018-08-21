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
}
