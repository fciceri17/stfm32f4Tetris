#include "grid.h"
#include "movements.h"
#include <stdio.h>


bool onEnd;

	Grid::Grid(){}
	
	bool Grid::addBlock(){
		onEnd = false;
		bool ret = true;
		HardwareRng& random=HardwareRng::instance();
		Block b((int)(random.get()%7));
		if(!collision(b))
			blocks.push_back(b);
		else
			ret = false;
		return ret;
	}	
	
	vector<Block> Grid::getBlocks(){
		return blocks;
	}
	
	vector<Block> Grid::getGameOverBlocks(){
			
			Block g('G'), a('A'), m('M'), e('E'), o('O'), v('V'), r('R');
			blockss.push_back(g);
			blockss.push_back(a);
			blockss.push_back(m);
			blockss.push_back(e);
			blockss.push_back(o);
			blockss.push_back(v);
			blockss.push_back(e);
			blockss.push_back(r);
			return blockss;
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
			onEnd=true;
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
	
	bool Grid::deleteRow(){ // TO CHECK
		onEnd = true;
		int g[GRIDY];
		Block b(0,0);
		for(int y=0; y<GRIDY; y++){
			g[y]=0;
		}
		for(int y=0; y<GRIDY; y++){
			for(int x=0; x<GRIDX; x++){
				b=Block(x,y);
				if(collision(b)){
					g[y]++;
				}
			}
		}
		
		for(int j=12; j>=0; j--){
			if(g[j]==GRIDX){
				vector <Block> tempBlocks;
				for(Block curr : blocks){
					if(curr.getY()+curr.getBottom()>=j && curr.getY()<=j){
						curr.deleteRow(j-curr.getY());
					}else{
						if(curr.getY()+curr.getBottom()<j){
							curr.translate(TRANSLATEY);
						}
					}
					tempBlocks.push_back(curr);
				}
				blocks.clear();
				for(Block curr : tempBlocks){
					blocks.push_back(curr);
				}
				return true;
				
			}
		}
		return false;
		
		
	}
	

	bool Grid::collision(Block newBlock){
		vector<Block> myBlocks = getBlocks();
		if(newBlock.getBottom()+newBlock.getY()<GRIDY && newBlock.getSide()+newBlock.getX()<GRIDX && newBlock.getX()>=0){
			int checker[GRIDY][GRIDX]; //initialize test grid
			for(int i=0;i<GRIDY;i++){
				for(int j=0;j<GRIDX;j++){
					checker[i][j] = 0;
				}
			}
			int* temp = newBlock.getStructure();
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					checker[newBlock.getY()+i][newBlock.getX()+j] += *(temp+4*i+j); //add new block to test grid
				}
			}			
			
			for(Block curr : myBlocks){
				temp = curr.getStructure();
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						checker[curr.getY()+i][curr.getX()+j] += *(temp+4*i+j); //add currently iterating block
					}
				}
			}
			
			for(int i=0;i<GRIDY;i++){
				for(int j=0;j<GRIDX;j++){
					if(checker[i][j] > 1){ return true;}
				}
			}
			return false;
		}else{
			return true;
		}
	}