#ifndef GRID
#define GRID

#include <vector>
#include "block.h"
#include <stdlib.h>
#include <time.h>
#include "miosix/arch/common/drivers/stm32_hardware_rng.h"


#define GRIDX 12
#define GRIDY 13

using namespace std;
using namespace miosix;

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