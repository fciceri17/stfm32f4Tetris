#include grid.h
#include <ctime>
	Grid::Grid(){}
	void translate(int direction){
		
	}
	bool addBlock(){
		bool ret = true;
		Block b(rand%5);
		if(canAddBlock(b))
			block.push_back(b);
		else
			ret = false;
		return ret;
	}	
	
	vector getBlocks(){
		return blocks;
	}
