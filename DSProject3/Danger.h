#pragma once
#include <iostream>
#include <string>
#include "CConsole.h"
#include "Player.h"

using namespace std;

class Danger{
public:
	 Danger(CConsole * CCon, Player * player);
	

	virtual void display(); //Similar to Player display. will call set Color.

	virtual void move();
	

protected:
	
	string lane;  //lane is the combination of Danger chars and space chars. It is the array that will shift across the screen. 
	int timer;	//timer is the ticker. i just like timer better.
	int limit;	//limit is the time it takes before movement changes. 
	Color text; //color of the text.
	Color backG; //color of the background
	int y; //y location.
	int x; //x location 
	CConsole * CC; // the pointer to  CConsole in World. only way to access CConsole in dangers.
	Player * p; // the pointer to player in World. only way to access player's data in dangers.

	//These are all subject to change so based on what the children classes need so I set them to protected.
	//CC and p would not compile if they are private so I put them in protected. 

private:
	
	//x was in here until I made Fly, then X had to be protected. 
	//These don't change so they stay private. 

};