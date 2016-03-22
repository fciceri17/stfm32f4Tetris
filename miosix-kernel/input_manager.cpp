#include "input.h"

InputManager::InputManager(Grid * g){
	grid = g;
	exit = false;
	
}

/*
* The Game class calls this method when the game is over: exit set to true ends the while
* cycle in the run and the thread of the game stops.
*/
void InputManager::gameOver(){
	exit = true;
	t.join();
}

/*
* This method starts the thread execution.
*/
void InputManager::startListening(){
	t(run);
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
				if(within(e.getPoint(), buttonDX)){
					DrawingContext dc(Display::instance());
					drawButton(dc, buttonDX, true); // draws the shadow around the button to show it is pressed
				}else if (whithin(e.getPoint(), buttonSX)){
					DrawingContext dc(Display::instance());
					drawButton(dc, buttonSX, true); // draws the shadow around the button to show it is pressed
				}
			
				break;
			case EventType::TouchUp:
				if(within(e.getPoint(), buttonDX)){
					grid.translate(DIRECTIONDX);
				}else if (whithin(e.getPoint(), buttonSX)){
					grid.translate(DIRECTIONSX);
				}else if (within e.getPoint(), rotationRectangle)){
					grid.rotate();
				}
				break;
			default:
				break;
		}
		
	}
}