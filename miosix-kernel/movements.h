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
	int dispWidth;
	int dispHeight;
	int topBar;
	int buttonHeight;
	int offset;
	void clearArea();
	string NumberToString(int number);
	void padTo(std::string &str, const size_t num);
	
	public:
	MovementDraw();
	void drawGrid(Grid gr);
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

#endif