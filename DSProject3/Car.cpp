#include "Car.h"


Car::Car(CConsole * CCon, Player * player) : Road(CCon, player){
	text = white;
	y = 7;
	lane = "  CC        CC        CC        CC      ";
	limit = 2;

}


void Car::move(){
	timer++;
	if (timer == limit){
		char first = lane[0];
		for (int i = 0; i < 39; i++){
			lane[i] = lane[i + 1];
		}
		lane[39] = first;
		display();
		
		timer = 0;
	}//Car is moving to the left, so first holds on to first char of the string and at end of loop moves it to the back.
	hitPlayer();
}//Moving to the right