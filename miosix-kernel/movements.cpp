#include "movements.h"
#include "mxgui/display.h"
#include <string>
#include <sstream>

using namespace mxgui;
using namespace miosix;
using namespace std;

MovementDraw::MovementDraw(){
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
					x1 = i*OFFSET+20*curr.getX()+1;
					x2 = i*OFFSET+OFFSET+20*curr.getX()+1;
					if(x2>239)
						x2=239;
					updateScore(x2);
					y1 = (z-1)*OFFSET+20*curr.getY()+TOPH;
					y2 = (z-1)*OFFSET+OFFSET-1+20*curr.getY()+TOPH+1;
					HardwareRng& random=HardwareRng::instance(); // to implement the randomization of colours. (sbatti)
					dc.clear(Point(x1,y1), Point(x2,y2), MAGENTA);
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
	
	dc.clear(Point(0,0), Point(DISPW,TOPH), Color(CYAN));
	dc.drawRectangle(Point(0,0), Point(DISPW,TOPH), Color(BLACK));
	
	//draw bottom left button
	dc.clear(Point(0,DISPH-BUTTONH+1), Point(DISPW/2-1,DISPH), Color(CYAN));
	dc.drawRectangle(Point(0,DISPH-BUTTONH+1), Point(DISPW/2-1,DISPH), Color(BLACK));
	
	
	//draw left button arrow
	//horizontal bar
	pSx = Point(DISPW/2*3/8,DISPH-BUTTONH/2-1);
	pDx = Point(DISPW/2*5/8,DISPH-BUTTONH/2+1);
	dc.clear(pSx, pDx, Color(BLACK));
	dc.drawRectangle(pSx, pDx, Color(BLACK));
	//up right diagonal 
	dc.line(Point(DISPW/2*3/8,DISPH-BUTTONH/2-1), Point(DISPW/2*3/8+7,DISPH-BUTTONH/2-7), Color(BLACK));
	dc.line(Point(DISPW/2*3/8+1,DISPH-BUTTONH/2-1), Point(DISPW/2*3/8+1+7,DISPH-BUTTONH/2-7), Color(BLACK));
	dc.line(Point(DISPW/2*3/8+2,DISPH-BUTTONH/2-1), Point(DISPW/2*3/8+2+7,DISPH-BUTTONH/2-7), Color(BLACK));
	//down right diagonal
	dc.line(Point(DISPW/2*3/8,DISPH-BUTTONH/2+1), Point(DISPW/2*3/8+7,DISPH-BUTTONH/2+7), Color(BLACK));
	dc.line(Point(DISPW/2*3/8+1,DISPH-BUTTONH/2+1), Point(DISPW/2*3/8+1+7,DISPH-BUTTONH/2+7), Color(BLACK));
	dc.line(Point(DISPW/2*3/8+2,DISPH-BUTTONH/2+1), Point(DISPW/2*3/8+2+7,DISPH-BUTTONH/2+7), Color(BLACK));
	
	//draw bottom right button
	dc.clear(Point(DISPW/2+1,DISPH-BUTTONH+1), Point(DISPW,DISPH), Color(CYAN));
	dc.drawRectangle(Point(DISPW/2+1,DISPH-BUTTONH+1), Point(DISPW,DISPH), Color(BLACK));
	
	
	//draw right button arrow
	//horizontal bar
	pSx = Point(DISPW/2*3/8+DISPW/2,DISPH-BUTTONH/2-1);
	pDx = Point(DISPW/2*5/8+DISPW/2,DISPH-BUTTONH/2+1);
	dc.clear(pSx,pDx, Color(BLACK));
	dc.drawRectangle(pSx, pDx, Color(BLACK));
	//up left diagonal 
	dc.line(Point(DISPW/2*5/8+DISPW/2,DISPH-BUTTONH/2-1), Point(DISPW/2*5/8+DISPW/2-7,DISPH-BUTTONH/2-7), Color(BLACK));
	dc.line(Point(DISPW/2*5/8+DISPW/2-1,DISPH-BUTTONH/2-1), Point(DISPW/2*5/8+DISPW/2-1-7,DISPH-BUTTONH/2-7), Color(BLACK));
	dc.line(Point(DISPW/2*5/8+DISPW/2-2,DISPH-BUTTONH/2-1), Point(DISPW/2*5/8+DISPW/2-2-7,DISPH-BUTTONH/2-7), Color(BLACK));
	//down left diagonal
	dc.line(Point(DISPW/2*5/8+DISPW/2,DISPH-BUTTONH/2+1), Point(DISPW/2*5/8+DISPW/2-7,DISPH-BUTTONH/2+7), Color(BLACK));
	dc.line(Point(DISPW/2*5/8+DISPW/2-1,DISPH-BUTTONH/2+1), Point(DISPW/2*5/8+DISPW/2-1-7,DISPH-BUTTONH/2+7), Color(BLACK));
	dc.line(Point(DISPW/2*5/8+DISPW/2-2,DISPH-BUTTONH/2+1), Point(DISPW/2*5/8+DISPW/2-2-7,DISPH-BUTTONH/2+7), Color(BLACK));

}


void MovementDraw::clearArea(){

	DrawingContext dc(Display::instance());
	dc.clear(Point(1,TOPH+1),Point(DISPW-1,DISPH-BUTTONH),WHITE);

}


void MovementDraw::updateScore(int score){
	DrawingContext dc(Display::instance());
	string str = NumberToString(score);
	padTo(str, 8);
	const char * c = str.c_str();
	dc.setTextColor	(BLACK, CYAN);	 
	dc.write(Point(DISPW - DISPW/4, 5), c);
}


string MovementDraw::NumberToString(int number){
	 ostringstream s;
	 s << number;
	 return s.str();
}

void MovementDraw::padTo(std::string &str, const size_t num){
	const char paddingChar = '0';
    if(num > str.size())
    	str.insert(0, num - str.size(), paddingChar);
}

void MovementDraw::drawButton(int num){
	DrawingContext dc(Display::instance());
	if(num == 1){
		//dc.clear(Point(0,DISPH-BUTTONH), Point(DISPW/2-1,DISPH), Color(RED));
		dc.drawRectangle(Point(0,DISPH-BUTTONH), Point(DISPW/2-1,DISPH), Color(RED));
	}else if(num == 2){
		//dc.clear(Point(DISPW/2+1,DISPH-BUTTONH), Point(DISPW,DISPH), Color(BLUE));
		dc.drawRectangle(Point(DISPW/2+1,DISPH-BUTTONH), Point(DISPW,DISPH), Color(BLUE));
	}
}