#include "block.h"


/*
* The constructor creates the structure of the block based on the blockID.
*/

Block::Block(int xC, int yC){

int structure[4][4] = {
				1, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0
			};
			copyArr(structure, structBlock);	
		}
	x=xC;
	y=yC;

}


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
			copyArr(structure, structBlock);
		}
			break;
		default:			// blockID not matching, no block can be created
			break;
	}
	x = 5;
	y = 0;
}

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


/*
* This method rotates the block by 90.
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

void Block::copyArr(int src[][4], int dest[][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			dest[i][j] = src[i][j];
		}
	}

}

/*
* This method changes the x coordinate of the block, according to the direction passed.
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