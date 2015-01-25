#include "Gator.h"

Gator::Gator(CConsole * CCon, Player * player) : Water(CCon, player){
	text = blue;
	y = 3;
	lane = " >=-     >=-     >=-     >=-     >=-    ";
	limit = 4;

}

void Gator::move(){


	timer++;
	if (timer == limit){

		char first = lane[0];
		for (int i = 0; i < 39; i++){
			
			lane[i] = lane[i + 1];
			if (lane[i] == '>') lane[i] = '+';
			else if (lane[i] == '+') lane[i] = '>';//for openning and closing gator's mouth
		}

		lane[39] = first;

		if (p->getY() == y){
			if (lane[p->getX()] == ' ' || lane[p->getX()] == '>') p->Dead();// > won't kill the player. Needs to be fixed.
			p->subX();//like shortLog, but removing 1 from x because moving to the left.

			if (p->getX() == 0) p->setXend();

		}
		display();
		

		timer = 0;
	}

}
