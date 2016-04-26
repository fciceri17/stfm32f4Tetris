#ifndef H_BLOCK
#define H_BLOCK

#include "utility.h"
#include <cstring>
#include <stdio.h>

class Block{
	private:
		int x, y;
		int structBlock[4][4];
		int structBlock2[5][4];
		int colour;
		void copyArr(int src[][4], int dest[][4]);
		void copyArr2(int src[][4], int dest[][4]);

	public:
		int getBottom();
		int getSide();
		int getColour();
		Block(int blockID);
		Block(char c);
		Block(int xC, int yC);
		int getX();
		int getY();
		int* getStructure();
		int* getStructure2();
		void deleteRow(int row);
		void rotate();
		void translate(int d);	
};

#endif //H_BLOCK