#include "ShortLog.h"

ShortLog::ShortLog(CConsole * CCon, Player * player) : Water(CCon, player){
	text = brown;
	y = 2;
	lane = "LL   LL   LL   LL   LL   LL   LL   LL   ";


}

void ShortLog::move(){


	timer++;
	if (timer == limit){

		char first = lane[39];
		for (int i = 39; i > 0; i--){
			lane[i] = lane[i - 1];
		}
		lane[0] = first;
		
		if (p->getY() == y){
			if (lane[p->getX()+1] == ' ') p->Dead();
			else p->addX();
			
			if (p->getX() == 39) p->setX0();
			
		}
		display();
		
		timer = 0;
	}

}
