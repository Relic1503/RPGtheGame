#include "Game.h"


void cTimer::mSetTimer(){
	mTimerStart = SDL_GetTicks();
}

Uint32 cTimer::mGetTimeElapsed(){
	return mElapsedTime = (Uint32)(SDL_GetTicks() - mTimerStart);
}