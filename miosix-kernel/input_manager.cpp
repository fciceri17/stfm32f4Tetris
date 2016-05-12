#include "input_manager.h"

using namespace std;
using namespace mxgui;

/**
*	Empty contructor.
*/
InputManager::InputManager(){
	grid = NULL;
	exit = false;
}

/**
*	Constructor that initialize the grid and the movement draw elements.
*/
InputManager::InputManager(Grid * g, MovementDraw move){
	grid = g;
	exit = false;
	md = move;
}

/**
*	This method sets exit to true, stops the thread execution and calls the movement draw game over function.
*/
void InputManager::gameOver(){
	exit = true;
	pthread_join(thread, NULL);
	md.drawGameOver();
}

/**
*	This method creates the thread that waits on the starting screen.
*/
void InputManager::waitTouch(){
	pthread_create(&startThread,NULL,InputManager::doRunStartThread,this);
}

/**
*	This method is used for running the function of the start thread.
*/
void *InputManager::doRunStartThread(void *arg){
	reinterpret_cast<InputManager*>(arg)->runStartThread();
	return NULL;
}

/**
*	This method represents the start thread execution. It waits for a touch event and, when it is received, it signals the condition variable cv.
*/
void InputManager::runStartThread(){
	bool touchReceived=false;
	while(!touchReceived){
		Event e = InputHandler::instance().popEvent();
		switch(e.getEvent()){
			case EventType::Default:
			case EventType::TouchMove:
				break;
			case EventType::TouchDown:
			case EventType::TouchUp:
				if(within(e.getPoint(), Point(0,0), Point(md.getDispWidth(),md.getDispHeight()))){
					{
						Lock<Mutex> lck(inputMtx);
						cv.signal();
					}
					touchReceived=true;
				}
				break;
			default:
				break;
		}
	}
}

/**
*	This method starts the thread execution and joins the start thread, not needed anymore.
*/
void InputManager::startListening(){
	pthread_join(startThread, NULL);
	pthread_create(&thread,NULL,InputManager::doRun,this);
}

/**
*	This method is used for running the function of the game thread.
*/
void *InputManager::doRun(void *arg)
{
	reinterpret_cast<InputManager*>(arg)->run();
	return NULL;
}

/**
* This method represents the game thread execution. It waits for an event and performs different actions, according to the area
* of the screen pressed:
* 	- translate right if the touch is within the right button
* 	- translate left if the touch is within the left button
*	- rotate the block if the touch is within the rectangular area
*/
void InputManager::run(){
	while(!exit){
		Event e = InputHandler::instance().popEvent();
		if(!onEnd){
			switch(e.getEvent()){
				case EventType::Default:
				case EventType::TouchMove:
					break;
				case EventType::TouchDown:
					if(within(e.getPoint(), Point(0, md.getDispHeight()-md.getButtonHeight()), Point(md.getDispWidth()/2-1,md.getDispHeight()))){ 
						// in the left button
						md.drawButton(BUTTON1, LIGHT_GREY);
					}else if (within(e.getPoint(), Point(md.getDispWidth()/2+1,md.getDispHeight()-md.getButtonHeight()), Point(md.getDispWidth(),md.getDispHeight()))){ 
						// in the right button
						md.drawButton(BUTTON2, LIGHT_GREY);
					}
					break;
				case EventType::TouchUp:
					if(within(e.getPoint(), Point(0, md.getDispHeight()-md.getButtonHeight()), Point(md.getDispWidth()/2-1,md.getDispHeight()))){
						// in the left button
						md.drawButton(BUTTON1, DARK_GREY);
						grid->translate(TRANSLATESX);
						md.drawGrid();
					}else if (within(e.getPoint(), Point(md.getDispWidth()/2+1,md.getDispHeight()-md.getButtonHeight()), Point(md.getDispWidth(),md.getDispHeight()))){
						// in the right button
						md.drawButton(BUTTON2, DARK_GREY);
						grid->translate(TRANSLATEDX);
						md.drawGrid();
						
					}
					else if (within (e.getPoint(), Point(0,md.getTopbarHeight()), Point(md.getDispWidth(),md.getDispHeight()-md.getButtonHeight()))){
						// in the rectangle
						grid->rotate();
						md.drawGrid();
					}
					break;
				default:
					break;
			}
		}
	}
}