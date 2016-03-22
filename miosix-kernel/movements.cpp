#include "movements.h"
#include "mxgui/display.h"

using namespace mxgui;
using namespace miosix;

MovementDraw::MovementDraw(){
}

void MovementDraw::drawGrid(Grid gr){
	DrawingContext dc(Display::instance());
	clearArea();
	vector<Block> blockSet = gr.getBlocks();
	for(Block curr : blockSet){
		for(int i=0;i<MATX;i++){
			for(int z=0; z<MATY; z++){
				if(curr.getStructure()[z][i]==1){
					int x1,x2,y1,y2;
					x1 = i*OFFSET+20*curr.getX();
					x2 = i*OFFSET+OFFSET+20*curr.getX()-1;
					y1 = z*OFFSET+20*curr.getY();
					y2 = z*OFFSET+OFFSET-1+20*curr.getY();
					dc.clear(Point(x1,y1), Point(x2,y2), WHITE);
					dc.drawRectangle(Point(x1,y1), Point(x2,y2), Color(BLACK));
				}
			}
		}
	}
}

	
void MovementDraw::drawInit(){
	DrawingContext dc(Display::instance());
	dc.clear(WHITE);
	
	//draw empty top bar in black
	dc.drawRectangle(Point(0,0), Point(DISPW,TOPH), Color(BLACK));
	
	//draw bottom left button
	dc.drawRectangle(Point(0,DISPH-BUTTONH), Point(DISPW/2,DISPH), Color(BLACK));
	
	//draw bottom right button
	dc.drawRectangle(Point(DISPW/2,DISPH-BUTTONH), Point(DISPW,DISPH), Color(BLACK));


}


void MovementDraw::clearArea(){

	DrawingContext dc(Display::instance());
	dc.clear(WHITE); //TODO AREA

}


void updateScore(int score){
	//TODO make text padded top right

}