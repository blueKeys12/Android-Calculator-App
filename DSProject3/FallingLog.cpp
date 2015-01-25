#include "FallingLog.h"

FallingLog::FallingLog(CConsole * CCon, Player * player) : Water(CCon, player){
	text = purple;
	y = 4;
	
	lane = "   ======    ======    ======    ====== ";
	

}
