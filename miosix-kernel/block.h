#ifndef H_BLOCK
#define H_BLOCK
#define MATX 4
#define MATY 4
#define TRANSLATEDX 0
#define TRANSLATESX 1

#include <cstring>


class Block{
	private:
		int x, y;
		int structBlock[4][4];
		void copyArr(int src[][4], int dest[][4]);
		int *retV[4];

	public:
		Block(int blockID);
		int getX();
		int getY();
		int** getStructure();
		void rotate();
		void translate(int d);	
};

#endif //H_BLOCK