#include "movements.h"
#include "mxgui/display.h"

using namespace mxgui;
using namespace miosix;

MovementDraw::MovementDraw(){
}

void MovementDraw::drawGrid(Grid gr){
	DrawingContext dc(Display::instance());
	clearArea();
	List pieceSet = gr.getPieces;
	for(piece curr : pieceSet){
		for(int i=0;i<MATX;i++){
			for(int z=0; z<MATY; z++){
				if(curr[z][i]==1){
					dc.clear(Point(i*OFFSET+x,z*OFFSET+y), Point(i*OFFSET+OFFSET+x-1,z*OFFSET+OFFSET-1+y), c);
					dc.drawRectangle(Point(i*OFFSET+x,z*OFFSET+y), Point(i*OFFSET+OFFSET+x-1,z*OFFSET+OFFSET-1+y), Color(BLACK));
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