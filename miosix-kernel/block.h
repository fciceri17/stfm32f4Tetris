#ifndef H_BLOCK
#define H_BLOCK
#define MATX 4
#define MATY 4
#define TRANSLATEDX 0
#define TRANSLATESX 1

class Block{
	private:
		int x, y;
		int structure[MATX][MATY];

	public:
		Block(int blockID);
		int getX();
		int getY();
		int** getStructure();
		void rotate();
		void translate(int d);	
}

#endif //H_BLOCK