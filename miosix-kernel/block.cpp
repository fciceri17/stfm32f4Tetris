#include "block.h"

/*
* The constructor creates the structure of the block based on the blockID.
*/
Block::Block(int blockID){
	switch(blockID){
		case 0:				// I block
			structure = {
				1, 0, 0, 0
				1, 0, 0, 0
				1, 0, 0, 0
				1, 0, 0, 0
			};
			break;
		case 1:				// L block
			structure = {
				1, 0, 0, 0
				1, 0, 0, 0
				1, 1, 0, 0
				0, 0, 0, 0
			};
			break;
		case 2:				// T block
			structure = {
				1, 1, 1, 0
				0, 1, 0, 0
				0, 0, 0, 0
				0, 0, 0, 0
			};
			break;
		case 3:				// Z block
			structure = {
				1, 1, 0, 0
				0, 1, 1, 0
				0, 0, 0, 0
				0, 0, 0, 0
			};
			break;
		case 4:				// O bock
			structure = {
				1, 1, 0, 0
				1, 1, 0, 0
				0, 0, 0, 0
				0, 0, 0, 0
			};
			break;
		default:			// blockID not matching, no block can be created
			break;
	}	
}

int Block::getX(){
	return x;
}

int Block::getY(){
	return y;
}

int** Block::getStructure(){
	return structure;
}

/*
* This method trasposes the block structure, rotating the block.
*/
void Block::rotate(){
	int tmp[MATX][MATY];
	for(int i; i < MATX; i++)
		for(int j; j < MATY; j++)
			tmp[j][i]=structure[i][j];
	for(int i; i < MATX; i++)
		for(int j; j < MATY; j++)
			structure[i][j]=tmp[i][j];
}

/*
* This method changes the x coordinate of the block, according to the direction passed.
*/
void Block::translate(int d){
	if(d == TRANSLATEDX)
		x++;
	else if(d == TRANSLATESX)
		x--;	
}