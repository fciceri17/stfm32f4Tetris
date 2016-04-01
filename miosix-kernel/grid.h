#ifndef GRID
#define GRID

#include <vector>
#include "block.h"
#include <stdlib.h>


#define GRIDX 7
#define GRIDY 20

using namespace std;

class Grid{
	private:
		vector <Block> blocks;
		bool collision(Block newBlock);
		void deleteRow();
	public: 
		Grid();
		void rotate();
		void translate(int direction);
		bool addBlock();
		bool canAddBlock();
		vector<Block> getBlocks();

};

#endif //GRID