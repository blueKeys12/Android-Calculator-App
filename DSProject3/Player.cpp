#include "Player.h"



Player::Player(CConsole * CCon){
	lives = 3;
	y = 9;
	x = 20;
	goals = 5;
	alive = true;
	CC = CCon;
	score = 0;
	level = 1;
	laneCheck[0] = false;
	laneCheck[1] = false;
	laneCheck[2] = false;
	laneCheck[3] = false;
	laneCheck[4] = false;
	laneCheck[5] = false;
	laneCheck[6] = false;
	laneCheck[7] = false;
	flyScore = false;

}


void Player::display()const{
	if (y == 5) CC->setColor(white, brown);
	else if (y < 5)CC->setColor(white, cyan);
	else CC->setColor(white, black);
	CC->printChar(x, y, '@');
	
}//Display that set's player's background to whatever that lane's background is. 

void Player::move(){
	
	if (y == 5) CC->setColor(white, brown);
	else if (y < 5)CC->setColor(white, cyan);
	else CC->setColor(white, black);
	CC->printChar(x, y, ' ');
	
	char input = ' ';
	 CC->getInput(input);//gets arrow key input of player and putting it in char input.
	
	switch (input){
	case '4':
		x--;
		if (x < 0) x = 39;//if player walks off the end on the right, player moves to the end on the left.
		
		break;
	case '6':
		x++;
		if (x > 39) x = 0;//if player walks off the end to left, player moves to the end on the right.
		
		break;
	case '8':
		y--;
		addScore();//if player moves up, addScore is called to determine if +5 should be added to score.
		
		break;
	case '2':
		y++;
		if (y > 9) y = 9;//keeps player from moving below the game.
		
		break;
	}//switch uses char input to determine if player's x or y should be changed. 

	if (y == 1){
		if (x == 3 || x == 11 || x == 19 || x == 27 || x == 35){
			Scored();
		}//if player is in Y location, determines if Scored should be called. 
		else
			Dead();// if player is not in Scored positions, player must be dead. 
	}
	
}

void Player::Dead(){
	CC->setColor(white, black);
	CC->printString(0, 12, "You Died!");
	CC->printString(0, 13, "Press Enter to Begin");
	x = 20;
	y = 9;
	lives--;
	CC->printInt(7, 11, lives);
	for (int i = 0; i < 8; i++) laneCheck[i] = false; //resets laneChecks for +5 scoring. 
	CC->waitForEnter();
	
	CC->printString(0, 12, "                    ");
	CC->printString(0, 13, "                    ");
	
}//When dead is called, gives Dead message, waits for enter and subtracts one from life. 



void Player::Scored(){
	CC->setColor(black, red);
	CC->printChar(x, y, '*');
	CC->setColor(white, black);
	CC->printString(0, 12, "You Scored!");
	CC->printString(0, 13, "Press Enter to Begin");
	x = 20;
	y = 9;
	goals--;

	//everytime player scores, subtract 1 from goals. 
	if (flyScore == true) {
		score += 10;
		flyScore = false;
	}//when fly is eaten by player. add 10 to score. 
	//the +10 will be added only after player has moved up one spot after pressing enter.
	

	if (goals == 0){
		goals = 5; 
		level++;
		CC->setColor(white, black);
		CC->printInt(15, 11, level);
		CC->printString(0, 1, "### ####### ####### ####### ####### ####");  
	}// if player has scored all the goals, player moves up a level. 
	//resets line 1 so player can score again. 

	for (int i = 0; i < 8; i++) laneCheck[i] = false;//resets all of the lane checks to false.	
													//needed for +5 upward scoring. 
	
	CC->waitForEnter();
	CC->setColor(white, black);
	CC->printString(0, 12, "                  ");
	//resets the 12th line to blank. 
}



int Player::getX(){
	return x;
}//used by Dangers to determine if player is hit, or is safe.

int Player::getY(){
	return y;
}//Very important, used by dangers to determine if player is in their lane.

int Player::getLives(){
	return lives;
}

int Player::getGoals(){
	return goals;
}//returns the number of goals left for player to reach BEFORE next leve.

int Player::getScore(){
	return score;
}//returns the score not the number of goals left.

int Player::getLevel(){
	return level;
}//pretty straightforward call of what level player is on.

void Player::addX(){
	x++;
}//for water dangers moving to the right.

void Player::subX(){
	x--;
}//for water dangers moving to the left.

void Player::setX0(){
	x = 0;
}//this is for water dangers moving to the right.
void Player::setXend(){
	x = 39;
}//this is for water dangers moving to the left.

void Player::addScore(){
	if (laneCheck[y-1] == false){
		laneCheck[y-1] = true;
		score += 5;
		CC->setColor(white, black);
		CC->printInt(31, 11, score);
	}
	
}//laneCheck is used to determine if player has been at Y spot before, if player has not
//then +5 to players score. 




void Player::addScoreFly(){
	flyScore = true;
}//special case for when player has landed on the fly. 

