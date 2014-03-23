#include "Game.h"

void cGame::mSplashLoad(string path){
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
			mTimer1.mSetTimer();
			mSplashUpdate();
		}
	}
}

void cGame::mSplashUpdate(){
	
	if (mTimer1.mGetTimeElapsed() > 2000)
		mSplashUnload();
	else
		mSplashDraw();
	/*else{
		mSplashDraw();
		updateScreens();
	}*/
	/*mSplashDraw();
	SDL_Delay(2000);
	mSplashUnload();*/
}

void cGame::mSplashDraw(){
	//Clear screen
	SDL_RenderClear(mRenderer);
	//render background
	SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
}

void cGame::mSplashUnload(){
	if (getPreviousGS() == __eGS_SPLASH1){
		setGameState(__eGS_STARTMENU);
		setPrevGS(__eGS_SPLASH2);
	}
	else{
		setGameState(__eGS_SPLASH2);
		setPrevGS(__eGS_SPLASH1);
	}
	//Destroy Texture
	//delete mTexture;
	//mTexture = NULL;

	

	mSetLoaded(false);

	updateScreens();
}