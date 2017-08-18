/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Definitions of the Dragon class functions
***************************************************************************************************/

#include "Dragon.h"

/****************************************************************************************************
**							Sets Dragon object armor and strengthPoints
****************************************************************************************************/
Dragon::Dragon()
{
	armor = 3;
	hitPoints = 12;
}


/****************************************************************************************************
**							Rolls attack dice and returns the value
****************************************************************************************************/
int Dragon::attack()
{
	// Two random numbers between 1 and 10 are added together and returned
	int attackRoll1 = rand() % 8 + 1;
	int attackRoll2 = rand() % 8 + 1;
	cout << "attacks for " << (attackRoll1 + attackRoll2) << " points" << endl;;
	return (attackRoll1 + attackRoll2);
}


/****************************************************************************************************
** Subtracts attack from total defense, uses remaining attack to determine remaining strength points
****************************************************************************************************/
void Dragon::defend(int attack)
{
	// Add defense numbers together and subtract them and armor from attack
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;

	int roll = roll1 + roll2;

	attack -= roll;
	attack -= armor;
	if (attack > -1)
	{
		// Deducts attack from strength
		hitPoints -= attack;
	}

	// Prints total defense
	cout << "defends for " << (roll + armor) << " points";
	if (attack < 1)
	{
		// Prints no damage taken if attack is less than 1
		cout << " and loses 0 strength points" << endl;
	}
	else
	{
		// Prints the number of strength points lost
		cout << " and loses " << attack << " strength points" << endl;
	}
	// Prints defense roll and armor
	cout << "Defense roll: " << roll << endl;
	cout << "Armor: " << armor << endl;
	cout << endl;
}


/****************************************************************************************************
**										Returns the type for Dragon
****************************************************************************************************/
string Dragon::getType()
{
	return type;
}


/****************************************************************************************************
**									Returns the hitPoints for Dragon
****************************************************************************************************/
int Dragon::getHitPoints()
{
	return hitPoints;
}