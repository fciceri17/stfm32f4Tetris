#include "game.h"
#include <stdlib.h>
#include <iostream>

Mutex mtx, inputMtx;
ConditionVariable cv;

Game::Game(){
	grid = Grid();
	md = MovementDraw(&grid);
	in = InputManager(&grid,md);
	score = 0;
}

void Game::startGame(){
	md.drawStartingScreen();
	in.waitTouch();
	Lock<Mutex> lck(inputMtx);
	cv.wait(lck);
	md.drawInit();
	md.updateScore(score);
	in.startListening();
	while(grid.addBlock()){
		do{
			md.drawGrid();
			usleep(500000);
		}while(!grid.canAddBlock());
		score ++;
		if(onEnd)
			printf("true");
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