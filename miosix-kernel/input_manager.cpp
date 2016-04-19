#include "input_manager.h"
#include "movements.h"
//#include <thread>

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
}

/*
* This method starts the thread execution.
*/
void InputManager::startListening(){
	pthread_create(&thread,NULL,InputManager::doRun,this);
}

void *InputManager::doRun(void *arg)
{
	reinterpret_cast<InputManager*>(arg)->run();
	return NULL;
}

/*
* This method is the thread execution, where an event handled by an InputHandler is declared.
* Actions are done according to the area pressed in the touch screen.
* NEED TO DEFINE THE BUTTON COORDINATES! (buttonDX and buttonSX are dummy buttons)
*/
void InputManager::run(){
	while(!exit){
		Event e = InputHandler::instance().popEvent();
		switch(e.getEvent()){
			case EventType::Default:
			case EventType::TouchMove:
				break;
			case EventType::TouchDown:
				if(within(e.getPoint(), Point(0, DISPH-BUTTONH), Point(DISPW/2-1,DISPH))){ //im in the left button
					md.drawButton(1);
				}else if (within(e.getPoint(), Point(DISPW/2+1,DISPH-BUTTONH), Point(DISPW,DISPH))){ //im in the right button
					md.drawButton(2);
				}
				
				//TODO MOVE AND TRIGGER
				break;
			case EventType::TouchUp:
				if(within(e.getPoint(), Point(0, DISPH-BUTTONH), Point(DISPW/2-1,DISPH))){
					grid->translate(TRANSLATESX);
					md.drawGrid(*grid);
				}else if (within(e.getPoint(), Point(DISPW/2+1,DISPH-BUTTONH), Point(DISPW,DISPH))){
					grid->translate(TRANSLATEDX);
					md.drawGrid(*grid);
					
				}
				else if (within (e.getPoint(), Point(0,TOPH), Point(DISPW,DISPH-BUTTONH))){
					grid->rotate();
				}
				break;
			default:
				break;
		}
		
	}
}