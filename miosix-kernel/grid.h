#ifndef GRID
#define GRID

#include <vector>
#include <stdlib.h>
#include "block.h"
#include "miosix/arch/common/drivers/stm32_hardware_rng.h"
#include "utility.h"

using namespace std;
using namespace miosix;

class Grid{
	private:
		vector <Block> blocks;
		bool collision(Block newBlock);
	public: 
		Grid();
		void deleteRow();
		void rotate();
		void translate(int direction);
		bool addBlock();
		bool canAddBlock();
		vector<Block> getBlocks();

};

#endif //GRID