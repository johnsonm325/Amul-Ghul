/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for Space parent class
***************************************************************************************************/

#ifndef SPACE_H
#define SPACE_H

#include "Dragon.h"

class Space
{
protected:
	InputValid inputVal1;
	Space *up = NULL;		// Pointer to space for up
	Space *forward;			// Pointer to space for forward
	Space *down = NULL;		// Pointer to space for down
	Space *back;			// Pointer to space for back
	Character character;
	string type;

public:
	Space(string);
	~Space();
	void setForward(Space*);
	Space *getForward();
	void setBack(Space*);
	Space *getBack();
	virtual int menu(vector<string>*) = 0;	// For abstract class
	virtual bool firstTime() = 0;			// For abstract class
	virtual string getType();
};
#endif