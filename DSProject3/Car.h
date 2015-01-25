#include "Road.h"

class Car : public Road{
public:
	Car(CConsole * CCon, Player * player);
	virtual void move();
};
