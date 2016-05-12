#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "mxgui/level2/input.h"
#include "grid.h"
#include "pthread.h"
#include "movements.h"
#include "utility.h"
#include <iostream>

class InputManager
{
	private:
		pthread_t thread, startThread;
		Grid* grid;
		MovementDraw md;
		bool exit;
		void run();
		void runStartThread();
		static void* doRun(void *arg);
		static void* doRunStartThread(void *arg);
		
	public:
		InputManager();
		InputManager(Grid* g,MovementDraw move);
		void waitTouch();
		void startListening();
		void gameOver();
};

#endif //INPUT_MANAGER_H