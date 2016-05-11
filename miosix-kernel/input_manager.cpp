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
	md.drawGameOver();
}

void InputManager::waitTouch(){
	pthread_create(&tmp,NULL,InputManager::doRun2,this);
}

void *InputManager::doRun2(void *arg){
	reinterpret_cast<InputManager*>(arg)->run2();
	return NULL;
}

void InputManager::run2(){
	bool cc=false;
	while(!cc){
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
					cc=true;
				}
				break;
			default:
				break;
		}
	}
}

/*
* This method starts the thread execution and joins the tmp thread, not needed anymore.
*/
void InputManager::startListening(){
	pthread_join(tmp, NULL);
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