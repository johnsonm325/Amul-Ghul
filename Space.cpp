/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Definitions of the Space class functions
***************************************************************************************************/

#include "Space.h"

/****************************************************************************************************
**						Virtual function to create the object with a type name
****************************************************************************************************/
Space::Space(string t)
{
	type = t;
}


/****************************************************************************************************
**								Destructor sets the pointers to NULL
****************************************************************************************************/
Space::~Space()
{
	up = NULL;
	forward = NULL;
	down = NULL;
	back = NULL;
}


/****************************************************************************************************
**							Sets the forward pointer to set up the gameplay area
****************************************************************************************************/
void Space::setForward(Space *f)
{
	forward = f;
}


/****************************************************************************************************
**									Returns the forward pointer
****************************************************************************************************/
Space * Space::getForward()
{
	return forward;
}


/****************************************************************************************************
**							Sets the back pointer to set up the gameplay area
****************************************************************************************************/
void Space::setBack(Space *b)
{
	back = b;
}


/****************************************************************************************************
**									Returns the back pointer
****************************************************************************************************/
Space * Space::getBack()
{
	return back;
}


/****************************************************************************************************
**								Virtual function for abstract class
****************************************************************************************************/
int Space::menu(vector<string> *i)
{
	return 0;
}


/****************************************************************************************************
**						Virtual function to return the type of each derived class
****************************************************************************************************/
string Space::getType()
{
	return type;
}