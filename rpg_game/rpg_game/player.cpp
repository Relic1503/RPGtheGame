#include "Game.h";

cPlayer::cPlayer(){
	mIsPlayerAlive = true;
	setPlayerParams(500, 50, 64, 64);						//Sets player width, height, x, y
	setPlayerSpeed(5);
}

void cPlayer::setPlayerSpeed(int speed){
	mPlayerSpeed = speed;
}

void cPlayer::setPlayerParams(int x, int y, int width, int height){
	mPlayerX = x;
	mPlayerY = y;
	mPlayerWidth = width;
	mPlayerHeight = height;
}