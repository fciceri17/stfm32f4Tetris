#ifndef GAME
#define	GAME
#define MULTIPLIER 5
namespace std{
	class Game{
		public:		
			/**
			*	Constructor, create a new game initializing input and graphic reference
			*/
			Game(Input in, Graphic gr);		
			/**
			*	Start the game session
			*/
			run();			
	}
}
#endif //GAME