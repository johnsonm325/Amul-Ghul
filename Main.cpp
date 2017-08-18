/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Main function
***************************************************************************************************/

#include "Dungeon.h"

int main()
{
	Menu menu1;
	// Random number seed
	srand(size_t(time(NULL)));

	do
	{
		menu1.displayMenu();
		menu1.setChoice();

		if (menu1.getChoice() == 1)
		{
			Dungeon dungeon;

			dungeon.beginGame();
		}
	} while (menu1.getChoice() != 2);

	cout << "Shutting down game..." << endl;
	cin.get();

	return 0;
}