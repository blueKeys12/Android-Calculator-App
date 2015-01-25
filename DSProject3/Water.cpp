#include "Water.h"


Water::Water(CConsole * CCon, Player * player) : Danger(CCon, player){

	backG = cyan;//all of water's background is cyan.
	limit = 3;//because longlog and short log are moving at the same speed, limit can be 3.
}


void Water::move(){
	
	timer++;
	if (timer == limit){

		char first = lane[39];
		for (int i = 39; i > 0; i--){
			lane[i] = lane[i - 1];
		}

	
		if (p->getY() == y){
			if (lane[p->getX() + 1] == ' ') p->Dead();
			else p->addX();

			if (p->getX() == 39) p->Dead();

		}

			lane[0] = first;
			display();
			
			timer = 0;
		}




		
	
	
}