#ifndef GRID_H
#define GRID_H

#include <vector>
#include <stdlib.h>
#include "block.h"
#include "miosix/arch/common/drivers/stm32_hardware_rng.h"
#include "utility.h"

using namespace std;
using namespace miosix;

class Grid
{
	private:
		vector <Block> blocks;
		vector<Block> gameOverBlocks;
		bool collision(Block newBlock);
	public: 
		Grid();
		bool deleteBlock();
		bool deleteRow();
		void rotate();
		void translate(int direction);
		bool addBlock();
		bool canAddBlock();
		vector<Block> getBlocks();
		vector<Block> getGameOverBlocks();
};

#endif //GRID_H