#include "Game.h"

void cGame::mWorldMapLoad(string path){
	if (!mIsLoaded()){
		if (!loadMedia(path.c_str())){
			printf("Failed to load media!\n");
		}
		else{
			mSetLoaded(true);
			//Set up player quad
			player1.mPlayerQuad.x = player1.getPlayerX();
			player1.mPlayerQuad.y = player1.getPlayerY();
			player1.mPlayerQuad.w = player1.getPlayerWidth();
			player1.mPlayerQuad.h = player1.getPlayerHeight();

			player1.mPlayerSurface = IMG_Load("Images/Character/hero_jimmy.png");
			player1.mPlayerTexture = SDL_CreateTextureFromSurface(mRenderer, player1.mPlayerSurface);

			player1.mPlayerSteps = 0;
			mRandomEncounter = rand() % 500;
			if (mRandomEncounter < 30)
				mRandomEncounter = rand() % 500;
		}
			mWorldMapUpdate();
	}
}

void cGame::mWorldMapUpdate(){

	if (player1.getPlayerX() > 0 && player1.getPlayerX() < (SCREEN_WIDTH - player1.getPlayerWidth())){
		player1.mPlayerQuad.x = player1.getPlayerX();
	}
	if (player1.getPlayerY() > 0 && player1.getPlayerY() < (SCREEN_HEIGHT - player1.getPlayerHeight()))
		player1.mPlayerQuad.y = player1.getPlayerY();

	if (player1.mPlayerSteps >= mRandomEncounter){
		setGameState(__eGS_STARTMENU);
		mWorldMapUnload();
	}


	mWorldMapDraw();
}

void cGame::mWorldMapDraw(){
	//Clear screen
	SDL_RenderClear(mRenderer);
	//render background
	SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
	//apply texture
	SDL_RenderCopy(mRenderer, player1.mPlayerTexture, NULL, &player1.mPlayerQuad);
}

void cGame::mWorldMapUnload(){
	//Destroy player texture
	SDL_DestroyTexture(player1.mPlayerTexture);
	player1.mPlayerTexture = NULL;
	mSetLoaded(false);
}