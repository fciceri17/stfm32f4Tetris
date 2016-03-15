
#include "mxgui/entry.h"
#include "mxgui/display.h"
#define RED 63488
#define WHITE 65535
#define BLACK 0
#define GREEN 2016
#define BLUE 31
#define OFFSET 20
 

using namespace mxgui;
using namespace miosix;


void draw(int [][3], Color, int, int);
void g();

ENTRY()
{
	Display& disp=Display::instance();
	
	{
		 
		int piece1[3][3]={
			1, 0, 0,
			1, 0, 0,
			1, 1, 0
		};
		int piece2[3][3]={
			1, 1, 1,
			0, 1, 0,
			0, 0, 0
		};
		int piece3[3][3]={
			0, 1, 0,
			0, 1, 0,
			0, 1, 0
		};
		int piece4[3][3]={
			1, 1, 0,
			0, 1, 1,
			0, 0, 0
		};
		int piece5[3][3]={
			1, 1, 0,
			1, 1, 0,
			0, 0, 0
		};
		
		
		for(int x=0;x<=300; x+=20){
			draw(disp,piece4, Color(RED), 0,x);
			Thread::sleep(300);
		}
	}
}


void draw(Display& disp, int piece[][3], Color c, int x, int y){
	
		DrawingContext dc(disp);
		dc.clear(WHITE);
		//g();
	for(int i=0; i<3; i++){
		for(int z=0; z<3; z++){
			if(piece[z][i]==1){
				dc.clear(Point(i*OFFSET+x,z*OFFSET+y), Point(i*OFFSET+OFFSET+x-1,z*OFFSET+OFFSET-1+y), c);
				dc.drawRectangle(Point(i*OFFSET+x,z*OFFSET+y), Point(i*OFFSET+OFFSET+x-1,z*OFFSET+OFFSET-1+y), Color(BLACK));
			}
		}
	}
}


void g(){
	DrawingContext dc(Display::instance());
	for(int i=0; i<12; i++)	
		for(int z=0; z<16; z++)
			dc.drawRectangle(Point(i*OFFSET,z*OFFSET), Point(i*OFFSET+OFFSET-1,z*OFFSET+OFFSET-1), Color(BLACK));
}