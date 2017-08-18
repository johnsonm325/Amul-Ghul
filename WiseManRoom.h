/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for WiseManRoom class
***************************************************************************************************/

#ifndef WISEMANROOM_H
#define WISEMANROOM_H

#include "DragonRoom.h"

class WiseManRoom : public Space
{
private:
	bool firstTry = true,
		 keyBone = false;
	int choice;

public:
	WiseManRoom();
	int menu(vector<string>*);
	bool firstTime();
	void wiseManDialogue(int);
	bool hasBoneKey();
	bool itemSearch(vector<string>, string);
};
#endif