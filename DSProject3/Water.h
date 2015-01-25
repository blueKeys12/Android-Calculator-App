#pragma once
#include "Danger.h"


class Water : public Danger{
public:
	Water(CConsole * CCon, Player * player);


	virtual void move();

};