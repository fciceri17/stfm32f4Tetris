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
		bool deleteRow();
		void rotate();
		void translate(int direction);
		bool addBlock();
		bool canAddBlock();
		vector<Block> getBlocks();
		
		static vector<Block> getGameOverBlocks(){
			vector<Block> blocks;
			Block g('G'), a('A'), m('M'), e('E'), o('O'), v('V'), r('R');
			blocks.push_back(g);
			blocks.push_back(a);
			blocks.push_back(m);
			blocks.push_back(e);
			blocks.push_back(o);
			blocks.push_back(v);
			blocks.push_back(e);
			blocks.push_back(r);
			return blocks;
		}
};

#endif //GRID