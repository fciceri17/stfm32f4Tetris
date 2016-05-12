#include "game.h"

using namespace mxgui;
using namespace miosix;

ENTRY()
{
	Game g = Game();
	g.startGame();
}