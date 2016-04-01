#include "game.h"

		
Game::Game(){
	grid = Grid();
	in = InputManager(&grid);
	md = MovementDraw();
	score = 0;
}

void Game::startGame(){
	md.drawInit();
	in.startListening();
	while(grid.addBlock()){
		while(!grid.canAddBlock());//da sostituire con movimento verso il basso
		score += MULTIPLIER;
		md.drawGrid(grid);
		
	}
	in.gameOver();
}