#ifndef GAME
#define	GAME
#define MULTIPLIER 5
#include "movements.h"
#include "grid.h"
#include "input_manager.h"

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