#include "Game.h"

void cGame::mMenuLoad(string path){
	bool loaded = false;

	if (!mIsLoaded()){
		//Do loading stuff
		if (!loadMedia(path.c_str())){
			printf("Failed to load media!\n");
		}
		else{

			//Block out loading stuff
			loaded = true;
			mSetLoaded(loaded);
			mMenuUpdate();
		}
	}
}

void cGame::mMenuUpdate(){
	mMenuDraw();
}

void cGame::mMenuDraw(){
	
	//Clear screen
	SDL_RenderClear(mRenderer);
	//render background
	SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
}

void cGame::mMenuUnload(){
	setPrevGS(__eGS_STARTMENU);
	mSetLoaded(false);
}