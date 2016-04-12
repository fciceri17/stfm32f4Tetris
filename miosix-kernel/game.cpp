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
		while(!grid.canAddBlock());//da sostituire con movimento verso il basso
		grid.addBlock();
		score += MULTIPLIER;
		//md.drawGrid(grid);
		md.updateScore(score);
	}
	in.gameOver();
}