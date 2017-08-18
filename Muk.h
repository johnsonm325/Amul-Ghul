/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for the Muk class
***************************************************************************************************/

#ifndef MUK_H
#define MUK_H

#include "Character.h"

class Muk
{
private:
	int armor,
		hitPoints,
		defense;
	bool g = true;
	string type = "Muk";

public:
	Muk();
	int attack();
	void defend(int);
	string getType();
	int getHitPoints();
};
#endif