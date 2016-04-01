#include "grid.h"
#include <ctime>

	Grid::Grid(){}
	
	bool Grid::addBlock(){
		bool ret = true;
		Block b(rand()%5);
		if(collision(b))
			blocks.push_back(b);
		else
			ret = false;
		return ret;
	}	
	
	vector<Block> Grid::getBlocks(){
		return blocks;
	}
	
	bool Grid::canAddBlock(){
		bool ret=false;
		Block last = blocks.back();
		blocks.pop_back();
		if(collision(tmp)){
			ret = true;
		}
		blocks.push_back(last);
		return ret;
	}
	
	void  Grid::rotate(){
		Block last = blocks.back(); //modifing the last block inserted, removed for collision check
		blocks.pop_back();
		Block tmp = Block(last);
		tmp.rotate();
		if(collision(tmp)){
			blocks.push_back(last);	
		}
		else{
			blocks.push_back(tmp);
		}		
	}
	
	void Grid::translate(int dir){
		Block last = blocks.back(); //modifing the last block inserted, removed for collision check
		blocks.pop_back();
		Block tmp = Block(last);
		tmp.translate(dir);
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
			for(int j=0;j<GRIDY;j++){
				checker[i][j] = 0;
			}
		}
		int** temp = newBlock.getStructure();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				checker[newBlock.getX()+i][newBlock.getY()+j] += temp[i][j]; //add new block to test grid
			}
		}
		
		for(Block curr : myBlocks){
			temp = curr.getStructure();
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					checker[curr.getX()+i][curr.getY()+j] += temp[i][j]; //add currently iterating block
				}
			}
		}
		
		for(int i=0;i<GRIDX;i++){
			for(int j=0;j<GRIDY;j++){
				if(checker[i][j] > 1){ return true;}
			}
		}
		return false;
	}