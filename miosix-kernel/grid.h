#ifndef GRID
#define GRID
#include <vector>
#include "block.h"

using namespace std;
	class Grid{
		private:
			vector<Block> blocks;
			
			void updateGrid();
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