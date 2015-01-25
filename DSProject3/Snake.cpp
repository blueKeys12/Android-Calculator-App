#include "Snake.h"

Snake::Snake(CConsole * CCon, Player * player) : Danger(CCon, player){
	
	y = 5;
	lane = "         >~~                            ";
	backG = brown;
	text = black;
	limit = 3;//snake should be fast, so limit is low.

}



void Snake::hitPlayer(){

	if (p->getY() == y){
		if (lane[p->getX()] == '>'){
			p->Dead();
		}
	}
	

}//finds out if Player is in the Y location of the snake and if player's x location is at the mouth of snake.
//kills player if he is at the mouth.

void Snake::move(){
	timer++;
	if (timer == limit){
		char first = lane[0];
		for (int i = 0; i < 39; i++){
			lane[i] = lane[i + 1];
		}
		lane[39] = first;
		display();
		
		timer = 0;
	}
	hitPlayer();
}