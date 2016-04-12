#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#define MATX 4
#define MATY 4
#define BUTTON1 1
#define BUTTON2 2

#define BLACK 0
#define BLUE 31
#define GREEN 2016
#define CYAN 2045
#define PURPLE 30730
#define MAGENTA 30751
#define RED 63488
#define YELLOW 65504
#define WHITE 65535

#define DISPH 319
#define DISPW 239
#define TOPH 20
#define BUTTONH 40

#define OFFSET 20

#include "mxgui/entry.h"
#include "mxgui/display.h"
#include "grid.h"

using namespace mxgui;

class MovementDraw
{
	private:
	void clearArea();
	string NumberToString(int number);
	void padTo(std::string &str, const size_t num);
	
	public:
	MovementDraw();
	void drawGrid(Grid gr);
	void drawInit();
	void buttonPress(int ID);
	void updateScore(int score);
	
};

#endif