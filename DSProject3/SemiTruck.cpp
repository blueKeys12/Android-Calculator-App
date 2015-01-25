#include "SemiTruck.h"


SemiTruck::SemiTruck(CConsole * CCon, Player * player) : Road(CCon, player){
	text = blue;
	y = 8;
	lane = "$$$$      $$$$      $$$$      $$$$      ";
	limit = 4;
	
}





