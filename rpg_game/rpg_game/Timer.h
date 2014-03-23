#include <SDL.h>

class cTimer{
public:
	cTimer(){}
	//timer stuff
	void mSetTimer();
	Uint32 mGetTimeElapsed();
	Uint32 mTimerStart;
	Uint32 mElapsedTime;
private:
};