#include "World.h"

World::World(int d){
	delay = d;
	CC = new CConsole(40, 15);
	p = new Player(CC);
	Semi = new SemiTruck(CC, p);
	tractor = new Tractor(CC, p);
	car = new Car(CC, p);
	fLog = new FallingLog(CC, p);
	sLog = new ShortLog(CC, p);
	gator = new Gator(CC, p);
	snake = new Snake(CC, p);
	fly = new Fly(CC, p);

}//creating all of the dangers and player. 

World::~World(){
	delete CC;
	delete p;
	delete Semi;
	delete tractor;
	delete car;
	delete sLog;
	delete gator;
	delete snake;
	delete fly;
}//deletes all objects created when world is destroyed.  

void World::run(){
	CC->printString(0, 0, "########################################");
	CC->printString(0, 1, "### ####### ####### ####### ####### ####");
	CC->printString(0, 10, "########################################");
	CC->printString(0, 11, "Lives: ");
	CC->printInt(7, 11, p->getLives());
	CC->printString(9, 11, "Level: ");
	CC->printInt(15, 11, p->getLevel());
	CC->printString(17, 11, "Count: ");
	CC->printInt(23, 11, 5 - p->getGoals());
	CC->printString(25, 11, "Score: ");
	CC->printInt(31, 11, p->getScore());

	CC->setColor(white, brown);
	CC->printString(0, 5, "                                        ");

	
	Semi->display();
	tractor->display();
	car->display();
	fLog->display();
	sLog->display();
	gator->display();
	p->display();
	CC->printString(0, 12, "Press Enter to Begin");
	CC->waitForEnter();
	

	//All of the code above is displaying the game's start screen. And waits until player presses enter.
	//After enter game begins.

	CC->printString(0, 12, "                     ");
	while (p->getLives() != 0){
		
	
		

		
		p->display();
		
		CC->delay(delay-((p->getLevel()-1) * 5)); 
		


		if (p->getLevel() > 1) snake->move();//at higher levels, snake appears and moves across the screen.
		Semi->move();
		tractor->move();
		car->move();
		fLog->move();
		sLog->move();
		gator->move();
		fly->move();
		p->move();//player's move must be called last. 
	
	}//while player still has lives, keep calling delay and all of the dangers' and player's moves. 
	return;
	

}