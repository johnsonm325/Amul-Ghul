/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for the character class
***************************************************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Menu.h"

class Character
{
private:
	int armor,
		hitPoints,
		defense;
	string type = "Sir Edward Francis III";

public:
	Character();
	int attack();
	void defend(int);
	string getType();
	int getHitPoints();
};
#endif