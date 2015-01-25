#pragma once
#include "CConsole.h"
#include "SemiTruck.h"
#include "Tractor.h"
#include "Car.h"
#include "FallingLog.h"
#include "ShortLog.h"
#include "Gator.h"
#include "Snake.h"
#include "Fly.h"
#include "Player.h"


//There will be more Danger headers to add
#include <iostream>

class World{
public:
	World(int d);//taking in a delay value. creates new player, new SemiTruck new CConsole and all other new Dangers needed.
	~World(); 


	void run(); //prints first line of "####" and prints second line of "####" with spaces for player score. then calls all of dangers display functions
				// and player display function. then within a while(p->getPlayerLives()!=0) call player move and all of dangers move functions. 
				
private:
	int delay;
	CConsole * CC;
	SemiTruck * Semi;
	Tractor * tractor;
	Player * p;
	Car * car;
	FallingLog * fLog;
	ShortLog * sLog;
	Gator * gator;
	Snake * snake;
	Fly * fly;

};