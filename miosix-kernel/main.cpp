#include "mxgui/entry.h"
#include "mxgui/display.h"
#include "movements.h"
#include "game.h"
#include "block.h"
#include "grid.h"
#include "input_manager.h"

using namespace mxgui;
using namespace miosix;

ENTRY(){
	Game g = Game();
	
	g.startGame();
}