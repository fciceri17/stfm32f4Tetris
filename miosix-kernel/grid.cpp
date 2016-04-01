#include "grid.h"
#include <ctime>

	Grid::Grid(){}
	
	bool Grid::addBlock(){
		bool ret = true;
		Block b(rand%5);
		if(canAddBlock(b))
			block.push_back(b);
		else
			ret = false;
		return ret;
	}	
	
	vector Grid::getBlocks(){
		return blocks;
	}

	void  Grid::rotate(){
		Block last = blocks.pop_back(); //modifing the last block inserted, removed for collision check
		Block tmp = last.rotate();
		if(collision(tmp)){
			blocks.push_back(last);	
		}
		else{
			blocks.push_back(tmp);
		}		
	}
	
	void Grid::translate(int dir){
		Block last = blocks.pop_back(); //modifing the last block inserted, removed for collision check
		Block tmp = last.translate(dir);
		if(collision(tmp)){
			blocks.push_back(last);	
		}
		else{
			blocks.push_back(tmp);
		}		
	}
	
	bool Grid::collision(Block newBlock){
		vector<Block> myBlocks = getBlocks();
		
		int checker[GRIDX][GRIDY]; //initialize test grid
		for(int i=0;i<GRIDX;i++){
			for(int j=0;<GRIDY;j++){
				checker[i][j] = 0;
			}
		}
		int temp[4][4] = newBlock.getStructure();
		for(int i=0;i<4;i++){
			for(int j=0;<4;j++){
				checker[newBlock.getX()+i][newBlock.getY()+j] += temp[i][j]; //add new block to test grid
			}
		}
		
		for(Block curr : myBlocks){
			temp = curr.getStructure();
			for(int i=0;i<4;i++){
				for(int j=0;<4;j++){
					checker[curr.getX()+i][curr.getY()+j] += temp[i][j]; //add currently iterating block
				}
			}
		}
		
		for(int i=0;i<GRIDX;i++){
			for(int j=0;<GRIDY;j++){
				if(checker[i][j] > 1){ return true;}
			}
		}
		return false;
	}