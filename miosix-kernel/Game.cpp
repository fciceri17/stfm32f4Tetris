#include "Game.h"
#include "Input.cpp"
#include "Graphic.cpp"


using namespace std;			
	public:
		Game::Game(){
			grid.Grid();
			in.Input(grid);
			g.Graphic();
			score = 0;
		}
		
		void Game::start(){
			while(grid.addBlock()){
				while(!grid.nextBlock());//da sostituire con movimento verso il basso
				score += MULTIPLIER;
				
			}
		}	}
}