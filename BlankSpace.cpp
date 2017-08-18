/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Definitions of the Blank Space class functions
***************************************************************************************************/

#include "BlankSpace.h"


/****************************************************************************************************
**								Creates the object with a type name
****************************************************************************************************/
BlankSpace::BlankSpace() : Space("Blank Space")
{

}


/****************************************************************************************************
**							Menu function for the Blank Space class
****************************************************************************************************/
int BlankSpace::menu(vector<string> *i)
{
	cout << "********************************************************************************" << endl;
	cout << "* It's an empty room" << endl;
	cout << "* Would you like to go to forward to the next room or back to the previous room?" << endl;
	
	cout << "*" << endl;

	cout << "* 1: Go forward" << endl;
	cout << "* 2: Move back" << endl;
	cout << "* 3: Exit game" << endl;
	cout << "********************************************************************************" << endl;
	cout << endl;

	do
	{
		cout << "Choose an option: " << endl;
		choice = inputVal1.isPosInteger();
	} while (choice > 3 || choice < 1);

	// MOves forward the next room or back to the previous
	if (choice == 1 || choice == 2)
	{
		return choice;
	}

	// Returns 50 to exit the game
	else
	{
		return 50;
	}
}


bool BlankSpace::firstTime()
{
	return firstTry;
}