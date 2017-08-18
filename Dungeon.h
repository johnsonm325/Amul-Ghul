/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for Dungeon class
***************************************************************************************************/

#ifndef DUNGEON_H
#define DUNGEON_H

#include "FinalRoom.h"

class Dungeon
{
private:
	Space *front;	// Used to point to front
	Space *rear;	// and rear nodes
	StoryRoom storyRoom;
	DragonRoom dragonRoom;
	int steps = 0,
		choice;
	char input;
	vector<string> inventory;

public:
	Dungeon();
	~Dungeon();
	void beginGame();
	int playGame();
	void addBack(char);
	Space *moveForward();
	Space *moveBack();
	void addSteps(int);
	void addItem(string);
	void removeItem(string);
	bool itemSearch(string);
};
#endif