//
// main.cpp
//

#include "main.h"

//Program main entry point
int main(int argc, char *argv[])

{
	Game *g = new Game();	
	
	if (g->Init() == false) {
		std::cout << "Error launching game!" << std::endl;
	}
	else {
		g->Refresh();
		g->Shutdown();
	}
			
	delete g;

	return 0;
}