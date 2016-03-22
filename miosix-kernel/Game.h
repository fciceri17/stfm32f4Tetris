#ifndef GAME
#define	GAME
#define MULTIPLIER 5
using namespace std;
	public class Game{
		private:
			Input in;
			Graphics g;
			Grid grid;
			int score;
		
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

#endif //GAME