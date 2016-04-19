#include "grid.h"


	Grid::Grid(){}
	
	bool Grid::addBlock(){
		bool ret = true;
		HardwareRng& random=HardwareRng::instance();
		Block b(random.get()%5);
		if(true || !collision(b))
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
		if(!blocks.empty()){
			Block last = blocks.back();
			Block tmp = last;
			blocks.pop_back();
			tmp.translate(2);
			if(collision(tmp)){
				ret = true;
				blocks.push_back(last);
			}else{
				blocks.push_back(tmp);
			}
		}
		else{
			ret = true;
		}
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
		int* temp = newBlock.getStructure();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				checker[newBlock.getX()+i][newBlock.getY()+j] += *(temp+4*j+i); //add new block to test grid
			}
		}
		
		for(Block curr : myBlocks){
			temp = curr.getStructure();
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					checker[curr.getX()+i][curr.getY()+j] += *(temp+4*j+i); //add currently iterating block
				}
			}
		}
		
		for(int i=0;i<GRIDX;i++){
			for(int j=0;j<GRIDY;j++){
				if(checker[i][j] > 1){ return true;}
			}
		}
		if(newBlock.getBottom()+newBlock.getY()<=GRIDY){
			return false;
		}else{
			return true;
		}
	}