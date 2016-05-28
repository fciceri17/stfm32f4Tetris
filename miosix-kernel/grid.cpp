#include "grid.h"

bool onEnd;

/**
*	Empty contructor.
*/
Grid::Grid(){}

/**
*	This method adds a random block to the grid, returns true if it is possible, false otherwise.
*/
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

/**
*	Getter.
*/
vector<Block> Grid::getBlocks(){
	return blocks;
}

/**
*	This method contructs the vector of the "GAME OVER" blocks and returns it.
*/
vector<Block> Grid::getGameOverBlocks(){		
	Block g('G'), a('A'), m('M'), e('E'), o('O'), v('V'), r('R');
	gameOverBlocks.push_back(g);
	gameOverBlocks.push_back(a);
	gameOverBlocks.push_back(m);
	gameOverBlocks.push_back(e);
	gameOverBlocks.push_back(o);
	gameOverBlocks.push_back(v);
	gameOverBlocks.push_back(e);
	gameOverBlocks.push_back(r);
	return gameOverBlocks;
}

/**
*	This method checks whether the current block has encountered a collision or not and vertically translates the block by one position.
*/
bool Grid::canAddBlock(){
	bool ret=false;
	if(!blocks.empty()){
		Block last = blocks.back();
		Block tmp = last;
		blocks.pop_back();
		tmp.translate(TRANSLATEY);
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

/**
*	This method rotates the current block, if no collision is encountered.
*/
void  Grid::rotate(){
	Block last = blocks.back();
	blocks.pop_back();
	Block tmp=last;
	tmp.rotate();
	if(collision(tmp)){
		blocks.push_back(last);	
	}
	else{
		blocks.push_back(tmp);
	}		
}

/**
*	This method translates the current block according to the direction given, if no collision is encountered.
*/
void Grid::translate(int dir){
	Block last = blocks.back();
	blocks.pop_back();
	Block tmp = last;
	tmp.translate(dir);
	if(collision(tmp)){
		blocks.push_back(last);	
	}
	else{
		blocks.push_back(tmp);
	}		
}

/**
*	This method deletes the row, if the row is full, by using the 1x1 test block. If the row is contained in a block,
*	this is deleted from the interested block and every block above is translated down by one position. It returns false
*	when there are no more lines to be deleted, true otherwise.
*/
bool Grid::deleteRow(){
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
			while(deleteBlock());
			return true;
		}
	}
	return false;
}

/**
*	This method deletes the block from the vector of the grid if the block is empty. It returns true if a block has been
*	deleted, false otherwise.
*/
bool Grid::deleteBlock(){
	int z,i;
	for(int x=0; x<blocks.size(); x++){
		for(z=0, i=0; i<16 && z==0; i++)
			z = *(blocks.at(x).getStructure()+i);
		if(z==0){
			blocks.erase(blocks.begin()+x);
			return true;
		}
	}
	return false;
}

/**
*	This method checks if the block passed encounters a collision in the grid. It uses a test grid in order to find overlaps
*	between the block and the already placed blocks and return false if a collision is detected, false otherwise.
*/
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