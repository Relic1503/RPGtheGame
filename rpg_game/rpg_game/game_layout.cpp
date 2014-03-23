#include "Game.h"

void cGame::updateScreens(){
	switch (getGameState()){
		case __eGS_SPLASH1:
			if (!mIsLoaded())
				mSplashLoad("Images/Splash/splash1.png");
			else
				mSplashUpdate();
			break;
		case __eGS_SPLASH2:
			if (!mIsLoaded())
				mSplashLoad("Images/Splash/splash2.png");
			else
				mSplashUpdate();
			break;
		case __eGS_STARTMENU:
			if (!mIsLoaded())
				mMenuLoad("Images/Menu/main_menu.png");
			else
				mMenuUpdate();
			break;
		case __eGS_WORLDMAP:
			if (!mIsLoaded())
				mWorldMapLoad("Images/Maps/world_map.png");
			else
				mWorldMapUpdate();
			break;
		case __eGS_COMBATMAP:
			if (!mIsLoaded())
				mMenuLoad("Images/Menu/main_menu.png");
			else
				mMenuUpdate();
			break;
		case __eGS_CUTSCENE:
			break;
		case __eGS_LOADING:
			break;
		case __eGS_FAILEDLOAD:
			break;
		case __eGS_SHOPMENU:
			break;
		case __eGS_NONE:
			break;
	}
	
}

void cGame::drawScreens(){

	//Update Screen
	SDL_RenderPresent(mRenderer);
}

void cGame::inputHandler(){
	while (SDL_PollEvent(&mEvent) != 0){
		if (mEvent.type == SDL_QUIT) {
			quit = true;
		}
		if (mEvent.type == SDL_KEYDOWN){
			SDL_Keycode keyPressed = mEvent.key.keysym.sym;
			switch (getGameState()){
			case __eGS_SPLASH1:
			case __eGS_SPLASH2:
				switch (keyPressed){
				case SDLK_ESCAPE:
					quit = true;
					break;
				}
				break;
			case __eGS_STARTMENU:
				switch (keyPressed){
				case SDLK_ESCAPE:
					quit = true;
					break;
				case SDLK_SPACE:
					mMenuUnload();
					setGameState(__eGS_WORLDMAP);
				}
				break;
			case __eGS_WORLDMAP:
				switch (keyPressed){
				case SDLK_ESCAPE:
					quit = true;
					break;
				case SDLK_LEFT:
					player1.setPlayerParams(player1.getPlayerX() - player1.getPlayerSpeed(), player1.getPlayerY(), player1.getPlayerWidth(), player1.getPlayerHeight());
					player1.mPlayerSteps++;
					break;
				case SDLK_RIGHT:
					player1.setPlayerParams(player1.getPlayerX() + player1.getPlayerSpeed(), player1.getPlayerY(), player1.getPlayerWidth(), player1.getPlayerHeight());
					player1.mPlayerSteps++;
					break;
				case SDLK_UP:
					player1.setPlayerParams(player1.getPlayerX(), player1.getPlayerY() - player1.getPlayerSpeed(), player1.getPlayerWidth(), player1.getPlayerHeight());
					player1.mPlayerSteps++;
					break;
				case SDLK_DOWN:
					player1.setPlayerParams(player1.getPlayerX(), player1.getPlayerY() + player1.getPlayerSpeed(), player1.getPlayerWidth(), player1.getPlayerHeight());
					player1.mPlayerSteps++;
					break;
				}
				break;
			case __eGS_COMBATMAP:
				break;
			case __eGS_CUTSCENE:
				break;
			case __eGS_LOADING:
				break;
			case __eGS_FAILEDLOAD:
				break;
			case __eGS_SHOPMENU:
				break;
			case __eGS_NONE:
				break;
			}	//End gamestate switch
		}	//end keydown if
		
	}	//end while poll event
	
}