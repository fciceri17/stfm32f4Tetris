#include "movements.h"
#include "mxgui/display.h"
#include <string>
#include <sstream>

using namespace mxgui;
using namespace miosix;
using namespace std;

MovementDraw::MovementDraw(){
	DrawingContext dc(Display::instance());
	dispWidth = dc.getWidth()-1;
	dispHeight = dc.getHeight()-1;
	topBar = (dispHeight+1) / TOP_RATIO;
	buttonHeight = (dispHeight+1) / BUTTON_RATIO;
	offset = (dispHeight+1) /OFFSET_RATIO;
	
}

void MovementDraw::drawGrid(Grid gr){
	DrawingContext dc(Display::instance());
	clearArea();
	vector<Block> blockSet = gr.getBlocks();
	for(Block curr : blockSet){
		for(int i=0;i<MATX;i++){
			for(int z=0; z<MATY; z++){
				int *memloc = (curr.getStructure()+4*z+i);
				if(*memloc){
					int x1,x2,y1,y2;
					x1 = i*offset+20*curr.getX()+1;
					x2 = i*offset+offset+20*curr.getX()+1;
					if(x2>239)
						x2=239;
					y1 = (z-1)*offset+20*curr.getY()+topBar;
					y2 = (z-1)*offset+offset-1+20*curr.getY()+topBar+1;
					dc.clear(Point(x1,y1), Point(x2,y2), curr.getColour());
					dc.drawRectangle(Point(x1,y1), Point(x2,y2), Color(BLACK));
				}
			}
		}
	}
}

	
void MovementDraw::drawInit(){
	DrawingContext dc(Display::instance());
	Point pSx, pDx;
	dc.clear(BLACK);
	
	//draw empty top bar in black
	
	dc.clear(Point(0,0), Point(dispWidth,topBar), Color(WHITE));
	dc.drawRectangle(Point(0,0), Point(dispWidth,topBar), Color(BLACK));
	
	//draw bottom left button
	dc.clear(Point(0,dispHeight-buttonHeight+1), Point(dispWidth/2-1,dispHeight), Color(WHITE));
	dc.drawRectangle(Point(0,dispHeight-buttonHeight+1), Point(dispWidth/2-1,dispHeight), Color(BLACK));
	
	
	//draw left button arrow
	//horizontal bar
	pSx = Point(dispWidth/2*3/8,dispHeight-buttonHeight/2-1);
	pDx = Point(dispWidth/2*5/8,dispHeight-buttonHeight/2+1);
	dc.clear(pSx, pDx, Color(BLACK));
	dc.drawRectangle(pSx, pDx, Color(BLACK));
	//up right diagonal 
	dc.line(Point(dispWidth/2*3/8,dispHeight-buttonHeight/2-1), Point(dispWidth/2*3/8+7,dispHeight-buttonHeight/2-7), Color(BLACK));
	dc.line(Point(dispWidth/2*3/8+1,dispHeight-buttonHeight/2-1), Point(dispWidth/2*3/8+1+7,dispHeight-buttonHeight/2-7), Color(BLACK));
	dc.line(Point(dispWidth/2*3/8+2,dispHeight-buttonHeight/2-1), Point(dispWidth/2*3/8+2+7,dispHeight-buttonHeight/2-7), Color(BLACK));
	//down right diagonal
	dc.line(Point(dispWidth/2*3/8,dispHeight-buttonHeight/2+1), Point(dispWidth/2*3/8+7,dispHeight-buttonHeight/2+7), Color(BLACK));
	dc.line(Point(dispWidth/2*3/8+1,dispHeight-buttonHeight/2+1), Point(dispWidth/2*3/8+1+7,dispHeight-buttonHeight/2+7), Color(BLACK));
	dc.line(Point(dispWidth/2*3/8+2,dispHeight-buttonHeight/2+1), Point(dispWidth/2*3/8+2+7,dispHeight-buttonHeight/2+7), Color(BLACK));
	
	//draw bottom right button
	dc.clear(Point(dispWidth/2+1,dispHeight-buttonHeight+1), Point(dispWidth,dispHeight), Color(WHITE));
	dc.drawRectangle(Point(dispWidth/2+1,dispHeight-buttonHeight+1), Point(dispWidth,dispHeight), Color(BLACK));
	
	
	//draw right button arrow
	//horizontal bar
	pSx = Point(dispWidth/2*3/8+dispWidth/2,dispHeight-buttonHeight/2-1);
	pDx = Point(dispWidth/2*5/8+dispWidth/2,dispHeight-buttonHeight/2+1);
	dc.clear(pSx,pDx, Color(BLACK));
	dc.drawRectangle(pSx, pDx, Color(BLACK));
	//up left diagonal 
	dc.line(Point(dispWidth/2*5/8+dispWidth/2,dispHeight-buttonHeight/2-1), Point(dispWidth/2*5/8+dispWidth/2-7,dispHeight-buttonHeight/2-7), Color(BLACK));
	dc.line(Point(dispWidth/2*5/8+dispWidth/2-1,dispHeight-buttonHeight/2-1), Point(dispWidth/2*5/8+dispWidth/2-1-7,dispHeight-buttonHeight/2-7), Color(BLACK));
	dc.line(Point(dispWidth/2*5/8+dispWidth/2-2,dispHeight-buttonHeight/2-1), Point(dispWidth/2*5/8+dispWidth/2-2-7,dispHeight-buttonHeight/2-7), Color(BLACK));
	//down left diagonal
	dc.line(Point(dispWidth/2*5/8+dispWidth/2,dispHeight-buttonHeight/2+1), Point(dispWidth/2*5/8+dispWidth/2-7,dispHeight-buttonHeight/2+7), Color(BLACK));
	dc.line(Point(dispWidth/2*5/8+dispWidth/2-1,dispHeight-buttonHeight/2+1), Point(dispWidth/2*5/8+dispWidth/2-1-7,dispHeight-buttonHeight/2+7), Color(BLACK));
	dc.line(Point(dispWidth/2*5/8+dispWidth/2-2,dispHeight-buttonHeight/2+1), Point(dispWidth/2*5/8+dispWidth/2-2-7,dispHeight-buttonHeight/2+7), Color(BLACK));

}


void MovementDraw::clearArea(){

	DrawingContext dc(Display::instance());
	dc.clear(Point(1,topBar+1),Point(dispWidth-1,dispHeight-buttonHeight),WHITE);

}


void MovementDraw::updateScore(int score){
	DrawingContext dc(Display::instance());
	string str = Utility::numberToString(score);
	Utility::padTo(str, 8);
	const char * c = str.c_str();
	dc.setTextColor	(BLACK, WHITE);	 
	dc.write(Point(dispWidth - dispWidth/4, 5), c);
}




void MovementDraw::drawButton(int num){
	DrawingContext dc(Display::instance());
	if(num == 1){
		//dc.clear(Point(0,dispHeight-buttonHeight), Point(dispWidth/2-1,dispHeight), Color(RED));
		dc.drawRectangle(Point(0,dispHeight-buttonHeight), Point(dispWidth/2-1,dispHeight), Color(RED));
	}else if(num == 2){
		//dc.clear(Point(dispWidth/2+1,dispHeight-buttonHeight), Point(dispWidth,dispHeight), Color(BLUE));
		dc.drawRectangle(Point(dispWidth/2+1,dispHeight-buttonHeight), Point(dispWidth,dispHeight), Color(BLUE));
	}
}

/* Getters */
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



