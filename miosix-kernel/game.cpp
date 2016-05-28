#include "game.h"
#include <stdlib.h>

Mutex mtx, inputMtx;
ConditionVariable cv;

/**
*	Constructor that creates the grid, the movement draw and the input manager elements and initializes the score.
*/
Game::Game() : md(&grid), in(&grid,&md) {
	score = 0;
}

/**
*	This method handles the game progress.
*/
void Game::startGame(){
	md.drawStartingScreen();
	in.waitTouch();
	Lock<Mutex> lck(inputMtx);
	cv.wait(lck); // on starting screen, wait for a tap on the screen
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
	in.gameOver(); // stop listening for inputs and draw the game over screen
}