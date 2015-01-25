#pragma once
#include "Danger.h"


class Road : public Danger{
public:
	Road(CConsole * CCon, Player * player);


virtual void hitPlayer();
virtual void move();




};