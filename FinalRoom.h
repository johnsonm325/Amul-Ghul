/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for FinalRoom class
***************************************************************************************************/

#ifndef FINALROOM_H
#define FINALROOM_H

#include "WiseManRoom.h"

class FinalRoom : public Space
{
private:
	bool firstTry = true,
		 openDoor = false,
		 trashBool = false;
	int choice;

public:
	FinalRoom();
	int menu(vector<string>*);
	bool firstTime();
	bool doorOpen();
	bool isTrash();
	bool itemSearch(vector<string>, string);
};
#endif
