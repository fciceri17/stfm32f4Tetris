#ifndef GAME
#define	GAME

#include "movements.h"
#include "grid.h"
#include "input_manager.h"
#include "utility.h"

using namespace std;

class Game
{
	private:
		InputManager in;
		MovementDraw md;
		Grid grid;
		int score;
	
	public:		
		Game();		
		void startGame();			
};

#endif //GAME