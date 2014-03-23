#include "Game.h"

//Constructor
cGame::cGame(){
	setGameState(__eGS_NONE);
}

cGame::~cGame(){
	close();
}

void cGame::close(){
	//Destroy Texture
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;

	//Destroy window
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	mRenderer = NULL;

	//Quit SDL
	IMG_Quit();
	SDL_Quit();
}

bool cGame::loadMedia(string path){
	bool success = true;

	//load png
	mTexture = loadTexture(path.c_str());
	if (mTexture == NULL){
		printf("Failed to load texture image!\n");
		success = false;
	}

	return success;
}

SDL_Surface* cGame::loadSurface(string path){
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	else{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);
		if (optimizedSurface == NULL)
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

SDL_Texture* cGame::loadTexture(string path){
	//final texture
	SDL_Texture* newTexture = NULL;

	//loadimage
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL){
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else{
		//create texture
		newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
		if (newTexture == NULL){
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//get rid of old surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void cGame::gameLoop(){
	inputHandler();
	updateScreens();
	drawScreens();
}

void cGame::setGameState(Uint32 state){
	mGameState = state;
}

void cGame::setPrevGS(Uint32 state){
	mPreviousGS = state;
}