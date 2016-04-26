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
	md.updateScore(score);
	in.startListening();
	md.drawGameOver();
	/*
	while(grid.addBlock()){
		do{
			md.drawGrid(grid);
			usleep(300000);
		}while(!grid.canAddBlock());
		while(grid.deleteRow()){
			score += MULTIPLIER;
			md.updateScore(score);
			md.drawGrid(grid);
			usleep(150000);
		};
		
	}
	
	in.gameOver();
	*/
}