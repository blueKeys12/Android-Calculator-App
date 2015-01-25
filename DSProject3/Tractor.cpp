#include "Tractor.h"


Tractor::Tractor(CConsole * CCon, Player * player) : Road(CCon, player){
	text = green;
	y = 6;
	lane = "     TTT     TTT     TTT     TTT     TTT";
	limit = 6;

}


void Tractor::move(){
	timer++;
	if (timer == limit){
		char first = lane[39];
		for (int i = 39; i > 0; i--){
			lane[i] = lane[i - 1];
		}
		lane[0] = first;

		if (p->getLevel() == 2){
			text = red;
			limit = 4;
		}//for super tractor, when level 2 is reached. text color is now red and speed is set to 4.

		display();
		
		timer = 0;
	}
	hitPlayer();
}