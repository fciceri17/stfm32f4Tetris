#include "game.h"
#include <stdlib.h>
		
Game::Game(){
	grid = Grid();
	md = MovementDraw(&grid);
	in = InputManager(&grid,md);
	score = 0;
}

void Game::startGame(){
	setMtx(true);
	md.drawStartingScreen();
	in.waitTouch();
	while(getMtx());
	md.drawInit();
	md.updateScore(score);
	in.startListening();
	while(grid.addBlock()){
		do{
			md.drawGrid();
			usleep(500000);
		}while(!grid.canAddBlock());
		score ++;
		md.updateScore(score);
		while(grid.deleteRow()){
			score += MULTIPLIER;
			md.updateScore(score);
			md.drawGrid();
			usleep(500000);
		};
	}
	in.gameOver();
}