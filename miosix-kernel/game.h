#ifndef GAME_H
#define	GAME_H

#include "movements.h"
#include "grid.h"
#include "input_manager.h"
#include "utility.h"

using namespace std;

class Game
{
	private:
		Grid grid;
		MovementDraw md;
		InputManager in;
		int score;
	
	public:		
		Game();		
		void startGame();			
};

#endif //GAME_H