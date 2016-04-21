#include "game.h"
#include <stdlib.h>
		
Game::Game(){
	grid = Grid();
	md = MovementDraw();
	in = InputManager(&grid,md);
	score = 0;
}

void Game::startGame(){
	md.drawInit();
	in.startListening();
	while(grid.addBlock()){
		do{
			md.drawGrid(grid);
			usleep(300000);
		}while(!grid.canAddBlock());
		//grid.deleteRow();
			//da sostituire con movimento verso il basso
		score += MULTIPLIER;
	}
	in.gameOver();
}