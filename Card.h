#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <iostream>
#include <ctime>
using namespace std; // This is needed for the game to work.

class Card
{
	private:
		int value;
		
	public:
		Card()
		{
			setValue(0);
		}
		void setValue(int x){value = x;}
		int getValue(){return value;}
		string toString()
		{
			return to_string(getValue());
		}
}card;