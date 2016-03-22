#include "Game.h"
#include "Input.cpp"
#include "Graphic.cpp"


namespace std{
	class Game{
		private:
			Input in;
			Graphics g;
			Grid grid;
			int score;
			
		
		public:
			Game::Game(){
				grid.Grid();
				in.Input(grid);
				g.Graphic();
				score = 0;
			}
			
			void Game::start(){
				while(grid.addBlock()){
					while(!grid.nextBlock());
					score += MULTIPLIER;
				}
			}
	}
}