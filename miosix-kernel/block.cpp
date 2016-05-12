#include "block.h"

/**
*	Constructor that creates the structure of the 1x1 block and sets its position.
*/
Block::Block(int xC, int yC){

	int structure[4][4] = {
		1, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};
	copyArr(structure, structBlock);	
	x=xC;
	y=yC;
	colour = RED;

}

/**
*	Constructor that creates the structure of the block and set the colour based on the blockID.
*/
Block::Block(int blockID){
	switch(blockID){
		case 0:				// I block
		{
			int structure[4][4] = {
				1, 0, 0, 0,
				1, 0, 0, 0,
				1, 0, 0, 0,
				1, 0, 0, 0
			};
			colour = CYAN;
			copyArr(structure, structBlock);	
		}
			break;
		case 1:				// L block
		{
			int structure[4][4] = {
				1, 0, 0, 0,
				1, 0, 0, 0,
				1, 1, 0, 0,
				0, 0, 0, 0
			};
			colour = ORANGE;
			copyArr(structure, structBlock);
		}
			break;
		case 2:				// T block
		{
			int structure[4][4] = {
				1, 1, 1, 0,
				0, 1, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0
			};
			colour = MAGENTA;
			copyArr(structure, structBlock);
		}
			break;
		case 3:				// Z block
		{
			int structure[4][4] = {
				1, 1, 0, 0,
				0, 1, 1, 0,
				0, 0, 0, 0,
				0, 0, 0, 0
			};
			colour = RED;
			copyArr(structure, structBlock);
		}
			break;
		case 4:				// O bock
		{
			int structure[4][4] = {
				1, 1, 0, 0,
				1, 1, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0
			};
			colour = YELLOW;
			copyArr(structure, structBlock);
		}
			break;
		case 5:				// L reverse block
		{
			int structure[4][4] = {
				1, 1, 0, 0,
				1, 0, 0, 0,
				1, 0, 0, 0,
				0, 0, 0, 0
			};
			colour = BLUE;
			copyArr(structure, structBlock);
		}
			break;
		case 6:				// O bock
		{
			int structure[4][4] = {
				0, 1, 1, 0,
				1, 1, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0
			};
			colour = GREEN;
			copyArr(structure, structBlock);
		}
			break;
		default:			// blockID not matching, no block can be created
			break;
	}
	x = GRIDX/2-1;
	y = 0;
}

/**
*	Constructor that creates the structure of the block based on the char passed, for the game over blocks.
*/
Block::Block(char c){
	switch(c){
		case 'G':				// G block
		{
			int structure[5][4] = {
				1, 1, 1, 1,
				1, 0, 0, 0,
				1, 0, 1, 1,
				1, 0, 0, 1,
				1, 1, 1, 1
			};
			colour = CYAN;
			copyArr2(structure, structBlock2);	
		}
			break;
		case 'A':				// A block
		{
			int structure[5][4] = {
				0, 1, 1, 0,
				1, 0, 0, 1,
				1, 1, 1, 1,
				1, 0, 0, 1,
				1, 0, 0, 1
			};
			colour = ORANGE;
			copyArr2(structure, structBlock2);
		}
			break;
		case 'M':				// M block
		{
			int structure[5][4] = {
				1, 0, 0, 1,
				1, 1, 1, 1,
				1, 0, 0, 1,
				1, 0, 0, 1,
				1, 0, 0, 1
			};
			colour = MAGENTA;
			copyArr2(structure, structBlock2);
		}
			break;
		case 'E':				// E block
		{
			int structure[5][4] = {
				1, 1, 1, 1,
				1, 0, 0, 0,
				1, 1, 1, 0,
				1, 0, 0, 0,
				1, 1, 1, 1
			};
			colour = RED;
			copyArr2(structure, structBlock2);
		}
			break;
		case 'O':				// O block
		{
			int structure[5][4] = {
				0, 1, 1, 0,
				1, 0, 0, 1,
				1, 0, 0, 1,
				1, 0, 0, 1,
				0, 1, 1, 0
			};
			colour = YELLOW;
			copyArr2(structure, structBlock2);
		}
			break;
		case 'V':				// V block
		{
			int structure[5][4] = {
				1, 0, 0, 1,
				1, 0, 0, 1,
				1, 0, 0, 1,
				1, 0, 1, 0,
				0, 1, 0, 0
			};
			colour = BLUE;
			copyArr2(structure, structBlock2);
		}
			break;
		case 'R':				// R block
			{
			int structure[5][4] = {
				1, 1, 1, 1,
				1, 0, 0, 1,
				1, 1, 1, 1,
				1, 0, 1, 0,
				1, 0, 0, 1
			};
			colour = GREEN;
			copyArr2(structure, structBlock2);
		}
			break;
		default:
			break;
	}
	x=0;
	y=0;
}

/**
*	Getters.
*/
int Block::getX(){
	return x;
}

int Block::getY(){
	return y;
}

int Block::getBottom(){
	int x=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(x<i && structBlock[i][j]==1)
				x=i;
	return x;
}

int Block::getSide(){
	int x=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(x<j && structBlock[i][j]==1)
				x=j;
	return x;
}

int* Block::getStructure(){
	return &structBlock[0][0];
}

int* Block::getStructure2(){
	return &structBlock2[0][0];
}

int Block::getColour(){
	return colour;
}
	
/**
*	This method rotates the block by 90 degrees.
*/
void Block::rotate(){
	int tmp[MATX][MATY];
	for(int i=0; i < MATX; i++)
		for(int j=0; j < MATY; j++){
			tmp[i][j]=structBlock[3-j][i];
		}
	int x,y;
	x=3;
	y=3;
	for(int i=0; i < MATX; i++)
		for(int j=0; j < MATY; j++){
			structBlock[i][j]=0;
			if(tmp[i][j]==1 && i<y)
				y=i;
			if(tmp[i][j]==1 && j<x)
				x=j;
		}
		
	for(int i=0; i < MATX-y; i++)
		for(int j=0; j < MATY-x; j++){
			structBlock[i][j]=tmp[i+y][j+x];
		}
}

/**
*	This method creates a copy of a 4x4 matrix.
*/
void Block::copyArr(int src[][4], int dest[][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			dest[i][j] = src[i][j];
		}
	}
}

/**
*	This method creates a copy of a 5x4 matrix.
*/
void Block::copyArr2(int src[][4], int dest[][4]){
	for(int i=0;i<5;i++){	
		for(int j=0;j<4;j++){	
			dest[i][j] = src[i][j];
		}
	}
}

/**
*	This method receives a row and deletes that row from the block structure.
*/
void Block::deleteRow(int row){
	for(int i=row;i<4;i++)
		for(int j=0;j<4;j++){
			structBlock[i][j]=structBlock[i+1][j];
		}
	for(int j=0;j<4;j++){
		structBlock[3][j]=0;
	}
	y++;
}

/**
*	This method increments by one the x or y coordinate of the block, according to the direction passed (right, left or down).
*/
void Block::translate(int d){
	if(d == TRANSLATEDX){
		x++;
	}
	else{
		if(d == TRANSLATESX){
			x--;	
		}
		else{
			if(d == TRANSLATEY){
				y++;	
			}
		}
	}
}