#include "Water.h"


class Gator : public Water{
public:
	Gator(CConsole * CCon, Player * player);

	virtual void move();


};