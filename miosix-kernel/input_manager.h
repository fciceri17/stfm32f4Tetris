#ifndef INPUT_H
#define INPUT_H

#include "mxgui/level2/input.h"
#include "Grid.h"
#include <thread>
#define TRANSLATEDX 0
#define TRANSLATESX 1


class InputManager{
	private:
		Grid* grid;
		thread t;
		bool exit;
		void run();
	public:
		InputManager(Grid g);
		void startListening();
		void gameOver();
}

#endif //INPUT_H