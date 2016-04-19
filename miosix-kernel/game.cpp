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
	//in.startListening();
	while(true){
		md.updateScore(score);
		grid.addBlock();
		while(!grid.canAddBlock()){
			md.drawGrid(grid);
			sleep(1);
		}
			//da sostituire con movimento verso il basso
		score += MULTIPLIER;
	}
	//in.gameOver();
}