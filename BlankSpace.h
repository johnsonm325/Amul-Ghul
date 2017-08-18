/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for Blank Space class
***************************************************************************************************/

#ifndef BLANKSPACE_H
#define BLANKSPACE_H

#include "Space.h"

class BlankSpace : public Space
{
private:
	int choice;
	bool firstTry = true;

public:
	BlankSpace();
	int menu(vector<string>*);
	bool firstTime();
};
#endif