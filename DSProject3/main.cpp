#include <stdlib.h>
#include "World.h"

void main(int argc, char *argv[]){
	int delay = 50;
	if (argc == 2) delay = atoi(argv[1]);
	World w(delay);
	w.run();
	return;

}