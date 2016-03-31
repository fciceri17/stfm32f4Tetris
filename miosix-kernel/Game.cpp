#include "game.h"

		
Game::Game(){
	grid.Grid();
	in.InputManger(&grid);
	md.MovementDraw();
	score = 0;
}

void Game::startGame(){
	md.drawInit();
	while(grid.addBlock()){
		while(!grid.nextBlock());//da sostituire con movimento verso il basso
			score += MULTIPLIER;
			md.drawGrid(grid);
		}
	}	
}