#include "block.h"


/*
* The constructor creates the structure of the block based on the blockID.
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
	x = 0;
	y = 0;
}

int Block::getX(){
	return x;
}

int Block::getY(){
	return y;
}

int** Block::getStructure(){
	int *retST[4] = { structBlock[0], structBlock[1], structBlock[2], structBlock[3] }; //TODO FIX
	std::memcpy(*retV, *retST, 4*sizeof(int));
	return retV;
}


/*
* This method trasposes the block structure, rotating the block.
*/
void Block::rotate(){
	int tmp[MATX][MATY];
	for(int i; i < MATX; i++)
		for(int j; j < MATY; j++){
			tmp[j][i]=structBlock[i][j];
		}
	for(int i; i < MATX; i++)
		for(int j; j < MATY; j++){
			structBlock[i][j]=tmp[i][j];
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
			
		}
	}
}