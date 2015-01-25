#include "Danger.h"


class Snake : public Danger{
public:
	Snake(CConsole * CCon, Player * player);


	virtual void hitPlayer();
	virtual void move();




};