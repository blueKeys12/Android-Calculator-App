#include "Fly.h"

Fly::Fly(CConsole * CCon, Player * player) : Danger(CCon, player){
	text = white;
	backG = green;
	y = 1;
	x = 3;
	lane = "%";
	limit = 10;//limit is 10 because that's how long I want fly to exist. 
	random = 0;
}


void Fly::move(){

	

	if (random == 5 && limit != 0){
		limit--;
		display();
		if (p->getY() == y && p->getX() == x) p->addScoreFly();//checks to see if player landed on the fly.

	}//if random ends up being a 5, then limit starts reducing. Fly can only be eaten within the time limit.
	 

	if (limit == 0 || random != 5){
		random = rand() % 50 + 1; //random generator from 1 to 5
		limit = 100;//this might be too long of an appearance. 
		switch (x){
		case 3:
			x=11;
			break;
		case 11:
			x = 19;
			break;
		case 19:
			x = 27;
			break;
		case 27:
			x = 35;
			break;
		case 35:
			x = 3;
			break;
		}//switch to change fly's x location randomly. 


		CC->setColor(white, black);
		CC->printChar(x,y,' ');
	}//at the end of time limit, reset it back to to 10 and generate another random number for random. 
	


}
