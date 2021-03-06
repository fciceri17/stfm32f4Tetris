#include "movements.h"
#include <string>

using namespace mxgui;
using namespace miosix;
using namespace std;

/**
*	Empty contructor.
*/
MovementDraw::MovementDraw(){}

/**
*	Contructor that initializes the grid and drawing context and sets the dimensions of the screen of the board.
*/
MovementDraw::MovementDraw(Grid* grid){
	DrawingContext dc(Display::instance());
	dispWidth = dc.getWidth()-1;
	dispHeight = dc.getHeight()-1;
	topBar = (dispHeight+1) / TOP_RATIO;
	buttonHeight = (dispHeight+1) / BUTTON_RATIO;
	offset = (dispHeight+1) /OFFSET_RATIO;
	gr = grid;
}

/**
*	This method draws the initial screen: a black screen with a text in the middle.
*/
void MovementDraw::drawStartingScreen(){
	DrawingContext dc(Display::instance());
	dc.clear(Point(0,0), Point(dispWidth, dispHeight), BLACK);
	dc.setTextColor	(LIGHT_GREY, BLACK);	 
	dc.write(Point(dispWidth/14, dispHeight/2), "TAP ON THE SCREEN TO START THE GAME!"); // a mutex is locked until the game is started
}

/**
* This method colours the rectangle inside the screen and the blocks contained in the blockSet.
*/
void MovementDraw::drawGrid(){
	DrawingContext dc(Display::instance());
	clearArea();
	vector<Block> blockSet = gr->getBlocks();
	for(Block curr : blockSet){
		for(int i=0;i<MATX;i++){
			for(int z=0; z<MATY; z++){
				int *memloc = (curr.getStructure()+4*z+i);
				if(*memloc){
					int x1,x2,y1,y2;
					x1 = (i+1)*offset+offset*curr.getX()+1;
					x2 = (i+1)*offset+offset+offset*curr.getX()+1;
					if(x2>dispWidth)
						x2=dispWidth; 
					y1 = (z)*offset+offset*curr.getY()+topBar;
					y2 = (z)*offset+offset-1+offset*curr.getY()+topBar+1;
					dc.clear(Point(x1,y1), Point(x2,y2), curr.getColour());
					dc.drawRectangle(Point(x1,y1), Point(x2,y2), Color(BLACK));
				}
			}
		}
	}
}

/**
*	This method draws all the screen components: top bar, vertical bars and button.
*/
void MovementDraw::drawInit(){
	DrawingContext dc(Display::instance());
	Point pSx, pDx;
	dc.clear(BLACK);
	
	//draw top bar
	dc.clear(Point(0,0), Point(dispWidth,topBar), Color(LIGHT_GREY));
	dc.drawRectangle(Point(0,0), Point(dispWidth,topBar), Color(BLACK));

	// draw left vertical bar
	dc.clear(Point(0, topBar), Point(offset, dispHeight-buttonHeight+1), Color(LIGHT_GREY));
	dc.drawRectangle(Point(0, topBar), Point(offset, dispHeight-buttonHeight+1), Color(BLACK));
	
	// draw right vertical bar
	dc.clear(Point(dispWidth-offset+2, topBar), Point(dispWidth, dispHeight-buttonHeight+1), Color(LIGHT_GREY));
	dc.drawRectangle(Point(dispWidth-offset+2, topBar), Point(dispWidth, dispHeight-buttonHeight+1), Color(BLACK));

	//draw bottom left button
	dc.clear(Point(0,dispHeight-buttonHeight+1), Point(dispWidth/2-1,dispHeight), Color(LIGHT_GREY));
	dc.drawRectangle(Point(0,dispHeight-buttonHeight+1), Point(dispWidth/2-1,dispHeight), Color(BLACK));
	drawButton(BUTTON1, DARK_GREY);
	
	//draw left button arrow
	//horizontal bar
	pSx = Point(dispWidth/2*3/8,dispHeight-buttonHeight/2-1);
	pDx = Point(dispWidth/2*5/8,dispHeight-buttonHeight/2+1);
	dc.clear(pSx, pDx, Color(BLACK));
	dc.drawRectangle(pSx, pDx, Color(BLACK));
	//up right diagonal
	for(int i=0; i<3; i++)
		dc.line(Point(dispWidth/2*3/8+i,dispHeight-buttonHeight/2-1),
								Point(dispWidth/2*3/8+i+7,dispHeight-buttonHeight/2-7), Color(BLACK));
	//down right diagonal
	for(int i=0; i<3; i++)
		dc.line(Point(dispWidth/2*3/8+i,dispHeight-buttonHeight/2+1),
								Point(dispWidth/2*3/8+7+i,dispHeight-buttonHeight/2+7), Color(BLACK));
	
	//draw bottom right button
	dc.clear(Point(dispWidth/2+1,dispHeight-buttonHeight+1), Point(dispWidth,dispHeight), Color(LIGHT_GREY));
	dc.drawRectangle(Point(dispWidth/2+1,dispHeight-buttonHeight+1), Point(dispWidth,dispHeight), Color(BLACK));
	drawButton(BUTTON2, DARK_GREY);
	
	//draw right button arrow
	//horizontal bar
	pSx = Point(dispWidth/2*3/8+dispWidth/2,dispHeight-buttonHeight/2-1);
	pDx = Point(dispWidth/2*5/8+dispWidth/2,dispHeight-buttonHeight/2+1);
	dc.clear(pSx,pDx, Color(BLACK));
	dc.drawRectangle(pSx, pDx, Color(BLACK));
	//up left diagonal
	for(int i=0; i<3; i++)
		dc.line(Point(dispWidth/2*5/8-i+dispWidth/2,dispHeight-buttonHeight/2-1),
								Point(dispWidth/2*5/8-i+dispWidth/2-7,dispHeight-buttonHeight/2-7), Color(BLACK));
	//down left diagonal
	for(int i=0; i<3; i++)
		dc.line(Point(dispWidth/2*5/8-i+dispWidth/2,dispHeight-buttonHeight/2+1),
								Point(dispWidth/2*5/8-i+dispWidth/2-7,dispHeight-buttonHeight/2+7), Color(BLACK));
}

/**
*	This method colours the rectangle inside the screen.
*/
void MovementDraw::clearArea(){
	DrawingContext dc(Display::instance());
	dc.clear(Point(offset+1,topBar+1),Point(dispWidth-offset+1,dispHeight-buttonHeight),WHITE);
}

/**
*	This method updates the value of the score, displaying it in the top bar.
*/
void MovementDraw::updateScore(int score){
	DrawingContext dc(Display::instance());
	string str = Utility::numberToString(score);
	Utility::padTo(str, 8);
	const char * c = str.c_str();
	dc.setTextColor	(BLACK, LIGHT_GREY);	 
	dc.write(Point(dispWidth - dispWidth/4, 5), c);
}

/**
*	This method draws the shadow of the button according to the colour passed.
*/
void MovementDraw::drawButton(int num, int colour){
	DrawingContext dc(Display::instance());
	if(num == BUTTON1){
		dc.clear(Point(dispWidth/2-4,dispHeight-buttonHeight+2), Point(dispWidth/2-2,dispHeight-1), Color(colour));
		dc.clear(Point(1, dispHeight-3), Point(dispWidth/2-2,dispHeight-1), Color(colour));
	}else if(num == BUTTON2){
		dc.clear(Point(dispWidth-4,dispHeight-buttonHeight+2), Point(dispWidth-1,dispHeight-1), Color(colour));
		dc.clear(Point(dispWidth/2+2,dispHeight-3), Point(dispWidth-1,dispHeight-1), Color(colour));
	}
}

/**
*	This method draws the game over screen with the game over blocks taken from the grid.
*/
void MovementDraw::drawGameOver(){
	int x1,x2,y1,y2,j=0;
	int *memloc;
	DrawingContext dc(Display::instance());
	clearArea();
	vector<Block> blockSet = gr->getGameOverBlocks();
	
	for(Block curr : blockSet){
		for(int i=0;i<5;i++){
			for(int z=0; z<4; z++){
				memloc = (curr.getStructure2())+4*i+z;
				if(*memloc){
					x1 = z*dispWidth/OFFSET_GO+((j%4)+1)*dispWidth/6+dispWidth/OFFSET_GO;
					x2 = (z+1)*dispWidth/OFFSET_GO+((j%4)+1)*dispWidth/6+dispWidth/OFFSET_GO;
					if(j<blockSet.size()/2){
						y1 = dispHeight*2/6 +dispWidth/OFFSET_GO*i;
					}else{
						y1 = dispHeight*3/6 +dispWidth/OFFSET_GO*i;
					}
					y2 = y1+dispWidth/OFFSET_GO;
					dc.clear(Point(x1,y1), Point(x2,y2), curr.getColour());
					dc.drawRectangle(Point(x1,y1), Point(x2,y2), Color(BLACK));
				}
			}
		}
		j++;
	}
}

/**
*	Getters
*/
int MovementDraw::getDispWidth(){
	return dispWidth;
}

int MovementDraw::getDispHeight(){
	return dispHeight;
}

int MovementDraw::getButtonHeight(){
	return buttonHeight;
}

int MovementDraw::getTopbarHeight(){
	return topBar;
}