#include "Road.h"


class Tractor: public Road{
public:
	Tractor(CConsole * CCon, Player * player);
	virtual void move();

};