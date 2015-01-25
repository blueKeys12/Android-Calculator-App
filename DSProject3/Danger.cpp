#include "Danger.h"


Danger::Danger(CConsole * CCon, Player * player){
	p = player;
	CC = CCon;
	lane = "";
	timer = 0;
	limit = 0;
	backG = black;
	text = white;
	
	y = 0;//y will always change for all the dangers
}


void Danger::move(){
	return;
}

void Danger::display(){
	CC->setColor(text, backG);
	CC->printString(x, y, lane);
}//Display will be used by all dangers. This should not change for all children classes.

