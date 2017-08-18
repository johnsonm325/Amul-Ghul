/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for Dragon class
***************************************************************************************************/

#ifndef DRAGON_H
#define DRAGON_H

#include "Muk.h"

class Dragon
{
protected:
	int armor,
		hitPoints,
		defense;
	string type = "Dragon";

public:
	Dragon();
	int attack();
	void defend(int);
	string getType();
	int getHitPoints();
};
#endif