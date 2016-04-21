#ifndef GAME
#define	GAME

#include "movements.h"
#include "grid.h"
#include "input_manager.h"
#include "utility.h"

using namespace std;

class Game{
	private:
		InputManager in;
		MovementDraw md;
		Grid grid;
		int score;
	
	public:		
		/**
		*	Constructor, create a new game initializing input and graphic reference
		*/
		Game();		
		/**
		*	Start the game session
		*/
		void startGame();			
};

#endif //GAME