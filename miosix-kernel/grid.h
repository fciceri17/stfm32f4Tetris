#ifndef GRID
#define GRID
#include <vector>
using namespace std;

class Grid{
	private:
		vector <Block> blocks;
		bool collision(Block newBlock);
		void deleteRow();
		bool canAddBlock();
	public: 
		Grid();
		void rotate();
		void translate(int direction);
		bool addBlock();
		vector<Block> getBlocks();

};

#endif //GRID