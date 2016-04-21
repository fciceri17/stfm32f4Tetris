#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "mxgui/level2/input.h"
#include "grid.h"
#include "pthread.h"
#include "movements.h"
#include "utility.h"

class InputManager{
	private:
		pthread_t thread;
		Grid* grid;
		bool exit;
		void run();
		MovementDraw md;
		static void* doRun(void *arg);
		
	public:
		InputManager();
		InputManager(Grid* g,MovementDraw move);
		void startListening();
		void gameOver();
};

#endif //INPUT_MANAGER_H