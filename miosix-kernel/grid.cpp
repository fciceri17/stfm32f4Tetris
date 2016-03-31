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

	void  rotate(){
		Block last = blocks.pop_back(); //modifing the last block inserted, removed for collision check
		Block tmp = last.rotate();
		if(collision(tmp)){
			blocks.push_back(last);	
		}
		else{
			blocks.push_back(tmp);
		}		
	}
	
	void translate(int dir){
		Block last = blocks.pop_back(); //modifing the last block inserted, removed for collision check
		Block tmp = last.translate(dir);
		if(collision(tmp)){
			blocks.push_back(last);	
		}
		else{
			blocks.push_back(tmp);
		}		
	}