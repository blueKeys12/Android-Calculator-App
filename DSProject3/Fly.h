#include "Danger.h"
#include <stdlib.h> //for random generator 


class Fly : public Danger{
public:
	Fly(CConsole * CCon, Player * player);
	virtual void move();

private:
	int random;
};

