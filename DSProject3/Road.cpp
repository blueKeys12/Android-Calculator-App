#include "Road.h"


Road::Road(CConsole * CCon, Player * player): Danger(CCon, player){

	backG = black;//all of road's background is black
}

void Road::hitPlayer(){

	if (p->getY() == y){
		if (lane[p->getX()] != ' '){
			p->Dead();
		}
	}
	return;
	
}//finds out if Player is in the Y location of the danger and then determines if player's been hit
//by seeing if it's x coordinate is in the same spot as a non ' ' char. call's player's dead if so.

void Road::move(){
	timer++;
	if (timer == limit){
		char first = lane[39];
		for (int i = 39; i > 0; i--){
			lane[i] = lane[i - 1];
		}
		lane[0] = first;
		display();
		
		timer = 0;
	}//Semi Truck and Tractor move in the same direction so it's easier to have them use Road's move.
	//since Semi and Tractor move to the right, first holds onto the last char in the string, and puts it
	//at the front after the loop. 
	hitPlayer();
}