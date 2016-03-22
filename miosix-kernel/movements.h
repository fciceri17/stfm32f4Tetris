#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#define MATX 4
#define MATY 4
#define BUTTON1 1
#define BUTTON2 2

#define BLACK 0
#define WHITE 65535

#define DISPH 319
#define DISPW 239
#define TOPH 20
#define BUTTONH 40

#define OFFSET 20

#include "mxgui/entry.h"
#include "mxgui/display.h"

using namespace mxgui;

class MovementDraw
{
	private:
	void clearArea();
	//mxgui::DrawingContext dc;
	
	public:
	MovementDraw();
	//void drawGrid(Grid gr);
	void drawInit();
	void buttonPress(int ID);
	void updateScore(int score);
	
	
};

#endif