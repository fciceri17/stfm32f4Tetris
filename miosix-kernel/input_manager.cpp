#include "input_manager.h"

using namespace std;
using namespace mxgui;

InputManager::InputManager(){
	grid = NULL;
	exit = false;
}

InputManager::InputManager(Grid * g, MovementDraw move){
	grid = g;
	exit = false;
	md = move;
}

/*
* The Game class calls this method when the game is over: exit set to true ends the while
* cycle in the run and the thread of the game stops.
*/
void InputManager::gameOver(){
	exit = true;
	pthread_join(thread, NULL);
	//md.drawGameOver();
}

/*
* This method starts the thread execution.
*/
void InputManager::startListening(){
	pthread_create(&thread,NULL,InputManager::doRun,this);
}

/*
* Dummy method that actually performs the run call.
*/
void *InputManager::doRun(void *arg)
{
	reinterpret_cast<InputManager*>(arg)->run();
	return NULL;
}

/*
* This method represents the thread execution, where an event handled by an InputHandler is declared.
* Actions are done according to the area pressed in the touch screen:
* 	- translate right if right button is pressed
* 	- translate left if left button is pressed
*	- rotate the block if the rectangle is touched
*/
void InputManager::run(){
	while(!exit){
		Event e = InputHandler::instance().popEvent();
		switch(e.getEvent()){
			case EventType::Default:
			case EventType::TouchMove:
				break;
			case EventType::TouchDown:
				if(within(e.getPoint(), Point(0, md.getDispHeight()-md.getButtonHeight()), Point(md.getDispWidth()/2-1,md.getDispHeight()))){ 
					// in the left button
					md.drawButton(BUTTON1, BLUE);
				}else if (within(e.getPoint(), Point(md.getDispWidth()/2+1,md.getDispHeight()-md.getButtonHeight()), Point(md.getDispWidth(),md.getDispHeight()))){ 
					// in the right button
					md.drawButton(BUTTON2, RED);
				}
				break;
			case EventType::TouchUp:
				if(within(e.getPoint(), Point(0, md.getDispHeight()-md.getButtonHeight()), Point(md.getDispWidth()/2-1,md.getDispHeight()))){
					// in the left button
					md.drawButton(BUTTON1, BLACK);
					grid->translate(TRANSLATESX);
					md.drawGrid(*grid);
				}else if (within(e.getPoint(), Point(md.getDispWidth()/2+1,md.getDispHeight()-md.getButtonHeight()), Point(md.getDispWidth(),md.getDispHeight()))){
					// in the right button
					md.drawButton(BUTTON2, BLACK);
					grid->translate(TRANSLATEDX);
					md.drawGrid(*grid);
					
				}
				else if (within (e.getPoint(), Point(0,md.getTopbarHeight()), Point(md.getDispWidth(),md.getDispHeight()-md.getButtonHeight()))){
					// in the rectangle
					grid->rotate();
					md.drawGrid(*grid);
				}
				break;
			default:
				break;
		}
		
	}
}