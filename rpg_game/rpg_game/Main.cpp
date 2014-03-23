#include "Game.h"
//chris git test
int main(int argc, char* args[]){
	cGame game;
	double delta;

	game.quit = false;
	
	if (!game.init())
		printf("Failed to initialize\n");
	else{
		game.setGameState(game.__eGS_SPLASH1);
		game.setPrevGS(game.__eGS_NONE);
		//Game Loop
		while (!game.quit){
			//Start timer to restrict FPS
			game.fpsTimer.mSetTimer();
			delta = (1000 / game.FRAME_RATE) - game.fpsTimer.mGetTimeElapsed();
			/*if (game.fpsTimer.mGetTimeElapsed() < (1000 / game.FRAME_RATE))
				SDL_Delay(delta);
			else*/
				game.gameLoop();
		}
		/*
		if (!game.loadMedia()) 
			printf("Failed to load media!\n");
		else{
			game.mCurrentSurface = game.mKeyPressSurfaces[game.__eKP_DEFAULT];
			while (!quit){
				while (SDL_PollEvent(&game.mEvent) != 0){
					if (game.mEvent.type == SDL_QUIT) {
						quit = true;
					}
				}
				//Clear screen
				SDL_RenderClear(game.mRenderer);

				//render texture
				SDL_RenderCopy(game.mRenderer, game.mTexture, NULL, NULL);

				//Update Screen
				SDL_RenderPresent(game.mRenderer);
			}
		}
		*/
	}
	game.close();

	return 0;
}

bool cGame::init(){
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0){
		printf("SDL could not Initialize! SDL_Error: %s/n", SDL_GetError());
		success = false;
	}
	else{
		mWindow = SDL_CreateWindow("RPG the GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (mWindow == NULL){
			printf("Window could not be created! SDL_Error: %s/n", SDL_GetError());
			success = false;
		}
		else{
			//Create Renderer
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mRenderer == NULL){
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else{
				//init Renerer Color
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0XFF);

				//initialize PNG Loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)){
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
			/*
			else{
				screenSurface = SDL_GetWindowSurface(window);
			}
			*/
		}
	}
	SDL_ShowCursor(0);
	return success;
}