#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "mxgui/level2/input.h"
#include "grid.h"
#include "pthread.h"

#define TRANSLATEDX 0
#define TRANSLATESX 1


class InputManager{
	private:
		pthread_t thread;
		Grid* grid;
		bool exit;
		void run();
		
		static void* doRun(void *arg);
		
	public:
		InputManager();
		InputManager(Grid* g);
		void startListening();
		void gameOver();
};

#endif //INPUT_MANAGER_H