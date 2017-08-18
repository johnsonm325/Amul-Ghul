/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file 
***************************************************************************************************/

#ifndef DRAGONROOM_H
#define DRAGONROOM_H

#include "StoryRoom.h"

class DragonRoom : public Space
{
private:
	int choice,
		attack;
	bool firstTry = true,
		 goneDragon = false,
		 goneEdward = false,
		 questOne = false,
		 questTwo = false,
		 questThree = false,
		 aKey = false;

public:
	DragonRoom();
	int menu(vector<string>*);
	bool firstTime();
	void dragonDialogue();
	void fightDragon();
	bool dragonGone();
	bool edwardGone();
	void pickUpKey();
	bool hasAKey();
};
#endif