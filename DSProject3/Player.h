#pragma once
#include "CConsole.h"

using namespace std;

class Player{
public:
	Player(CConsole * CCon);
	

	void display()const; //sets color Prints player to his current location using CC->setColor(white, black) and CC->printChar(x, y, p)/
								//when first called, it will set player to beginning location. 
	
	void move(); //has a char input that gets passed by reference in CC->getInput(input). then a switch is used 
						//to determine if x--, x++, y-- or y++ and printChar in previous player x,y. After switch call displayPlayer() and then
						//checks if player is alive with findAlive(). if player is dead call. playerDead().
	
	bool findAlive()const;  //returns bool alive. 

	void Dead(); //Resets player back to beginning location by changing X and Y and calling displayPlayer(). Also subtracts 1 from player's lives.
						
	void Scored();
	void addScore();
	
	int getX(); //returns x coordinate. Will be used by a Danger if player is in the Y location (I call it the danger's lane) of that Danger. to determine if player is killed.
	void addX();
	void subX();
	int getY(); //returns y coordinate. Will be used by Danger to determine if Player is in its lane.
	
	int getLives(); //returns the number of lives of Player. Will be called by World to determine if game should end.

	int getGoals(); //returns the number of goals Player has reached. Will be called by World to determine if game should go to the next level.

	int getScore();

	int getLevel();

	void setX0();
	void setXend();

	void addScoreFly();
private:
	
	CConsole * CC;//Player's CC pointer to access CConsole instance in World
	int x; //Player's X location
	int y; //Player's Y location
	int lives; //number of lives 
	int goals; //number of goals player has LEFT to score before next level, set to 5 at each level.
	bool alive; //determine if he is alive or dead
	int score;//player's score for the game. set to 0 initially.
	int level;//level player is currently at, initially at 1.
	bool laneCheck[7];//There are 8 y locations player can score +5 points. laneCheck array is used to determine if player
					//has been there before.
	bool flyScore;

};