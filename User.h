// The header file for the User class

#ifndef NAMESPACE_USER_CLASS
#define NAMESPACE_USER_CLASS



#include <iostream>
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
}


#endif