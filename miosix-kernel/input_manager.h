#ifndef INPUT_H
#define INPUT_H

#include "mxgui/level2/input.h"
#include "grid.h"

#define TRANSLATEDX 0
#define TRANSLATESX 1


class InputManager{
	private:
		Grid* grid;
		bool exit;
		void run();
	public:
		InputManager();
		InputManager(Grid* g);
		void startListening();
		void gameOver();
};

#endif //INPUT_H