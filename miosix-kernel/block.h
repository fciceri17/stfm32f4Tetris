#ifndef H_BLOCK
#define H_BLOCK

#include "utility.h"
#include <cstring>

class Block{
	private:
		int x, y;
		int structBlock[4][4];
		int colour;
		void copyArr(int src[][4], int dest[][4]);

	public:
		int getBottom();
		int getSide();
		int getColour();
		Block(int blockID);
		Block(int xC, int yC);
		int getX();
		int getY();
		int* getStructure();
		void rotate();
		void translate(int d);	
};

#endif //H_BLOCK