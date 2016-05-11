#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#include "mxgui/entry.h"
#include "mxgui/display.h"
#include "grid.h"
#include "utility.h"

using namespace mxgui;

class MovementDraw
{
	private:
		Grid* gr;
		int dispWidth;
		int dispHeight;
		int topBar;
		int buttonHeight;
		int offset;
		void clearArea();
	
	public:
		MovementDraw();	
		MovementDraw(Grid* gr);
		void drawGrid();
		void drawInit();
		void buttonPress(int ID);
		void updateScore(int score);
		void drawButton(int num, int colour);
		void drawStartingScreen();
		int getDispWidth();
		int getDispHeight();
		int getButtonHeight();
		int getTopbarHeight();
		void drawGameOver();
};

#endif //MOVEMENTS_H