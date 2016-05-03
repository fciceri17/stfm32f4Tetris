#ifndef UTILITY_H
#define UTILITY_H


#include <string>
#include <sstream>
#include "miosix/kernel/sync.h"
#include "miosix/arch/common/drivers/stm32_hardware_rng.h"

// translation indexes
#define TRANSLATEDX 0
#define TRANSLATESX 1
#define TRANSLATEY 2

// matrix dimensions
#define MATX 4
#define MATY 4

// grid dimensions
#define GRIDX 10
#define GRIDY 13

#define BUTTON1 1
#define BUTTON2 2

// colours
#define BLACK 0
#define BLUE 31
#define GREEN 2016
#define CYAN 2045
#define PURPLE 30730
#define LIGHT_GREY 50712
#define DARK_GREY 31727
#define MAGENTA 63519
#define RED 63488
#define ORANGE 64800
#define YELLOW 65504
#define WHITE 65535

/* ABSOLUTE display dimensions

#define DISPH 319
#define DISPW 239

// scorebar dimension
#define TOPH 20

// button dimension
#define BUTTONH 40

// offset
#define OFFSET 20

*/


// scorebar ratio
#define TOP_RATIO 16

// button ratio
#define BUTTON_RATIO 8

// game over offset ratio
#define OFFSET_GO 40

// offset ratio
#define OFFSET_RATIO 16

// score multiplier
#define MULTIPLIER 5

using namespace std;
using namespace miosix;

extern Mutex mtx, inputMtx;  
extern ConditionVariable cv;
extern bool onEnd;

class Utility{
	public:
		
		static string numberToString(int number){
			 ostringstream s;
			 s << number;
			 return s.str();
		}

		static void padTo(string &str, const size_t num){
			const char paddingChar = '0';
			if(num > str.size())
				str.insert(0, num - str.size(), paddingChar);
		}
		
		/*
		static bool getMtx(){
			return mtx;
		}
		
		static void setMtx(bool b){
			mtx = b;
		}
		*/
		
};
#endif //UTILITY_H