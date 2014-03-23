#include <SDL.h>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include "Timer.h"

using namespace std;

#ifndef __GAME_H_
#define __GAME_H_

class cPlayer{
public:
	enum eHero{											//enum to keep track of heros
		__eH_JIMMY,
		__eH_ALEX,
		__eH_BETH
	};
public:
	cPlayer();

	bool isPlayerAlive();
	int mPlayerSteps;
	//getters and setters for player
	void setPlayerSpeed(int);
	void setPlayerParams(int, int, int, int);
	int getPlayerX(){ return mPlayerX; }
	int getPlayerY(){ return mPlayerY; }
	int getPlayerWidth(){ return mPlayerWidth; }
	int getPlayerHeight(){ return mPlayerHeight; }
	int getPlayerSpeed(){ return mPlayerSpeed; }

	//Texture stuff
	SDL_Surface* mPlayerSurface = NULL;
	SDL_Texture* mPlayerTexture = NULL;
	SDL_Rect mPlayerQuad;

private:
	string mName;										//Character name
	int mHitPoints;										//Character base Hitpoints
	int mExp;											//Character exp total
	int mStr, mDex, mCon, mMagP, mMagD;					//Character attributes

	bool mIsPlayerAlive;
	int mPlayerSpeed;
	int mPlayerWidth;
	int mPlayerHeight;
	int mPlayerX, mPlayerY;
	int mPlayerZ;
};

class cGame{
public:
	enum eGameState{
		__eGS_NONE = 0,								//no gamestate
		__eGS_SPLASH1,								//Logo screen 1
		__eGS_SPLASH2,								//Logo screen 2
		__eGS_LOADING,								//Loading screen
		__eGS_STARTMENU,							//Start Menu
		__eGS_WORLDMAP,								//Main world map
		__eGS_COMBATMAP,							//Combat screen
		__eGS_TOWNMAP,								//Entered town
		__eGS_CUTSCENE,								//Cutscene playing
		__eGS_SHOPMENU,								//Entered Shop Menu
		__eGS_FAILEDLOAD							//Failed to load
	};
	enum eKeyPress{
		__eKP_DEFAULT,
		__eKP_UP,
		__eKP_DOWN,
		__eKP_LEFT,
		__eKP_RIGHT,
		__eKP_TOTAL
	};
public:
	cGame();
	~cGame();

	bool quit;
	bool init();									//Starts SDL and creates window
	bool loadMedia(string path);					//Loads media
	void close();									//Frees media and shuts down SDL
	SDL_Surface* loadSurface(string path);
	SDL_Texture* loadTexture(string path);			//Loads image as texture

	void gameLoop();								//the game loop
	void updateScreens();							//controls the gamestates
	void inputHandler();							//handles all the input
	void drawScreens();								//Does the final draw stuff

	//FPS restriction stuff
	const int FRAME_RATE = 30;
	cTimer fpsTimer;

	//Screen stuff
	int SCREEN_WIDTH = 1280;
	int SCREEN_HEIGHT = 720;

	SDL_Window* mWindow = NULL;						//Render window
	SDL_Renderer* mRenderer = NULL;					//Window Renderer
	SDL_Texture* mTexture = NULL;					//Current Displayed Texture
	SDL_Surface* screenSurface = NULL;				//Surface contained by window
	SDL_Surface* splashWindow = NULL;				//Image loading
	SDL_Event mEvent;								//Event handler
	SDL_Surface* mKeyPressSurfaces[__eKP_TOTAL];
	SDL_Surface* mCurrentSurface = NULL;

	bool mIsLoaded(){ return mLoaded; }
	void mSetLoaded(bool loaded){ mLoaded = loaded; }

	//GameState stuff
public:
	void setGameState(Uint32 state);
	void setPrevGS(Uint32 state);
private:
	Uint32 getGameState(){ return mGameState; }
	Uint32 getPreviousGS(){ return mPreviousGS; }
	

	Uint32 mGameState;								//Tracks game state
	Uint32 mPreviousGS;								//tracks previous game state

	bool mLoaded = false;

	//Splash Screen Members
public:
	void mSplashLoad(string path);
	void mSplashUpdate();
	void mSplashUnload();
	void mSplashDraw();

	cTimer mTimer1;

	//Main Menu
public:
	void mMenuLoad(string path);
	void mMenuUpdate();
	void mMenuUnload();
	void mMenuDraw();


	//World map members
public:
	void mWorldMapLoad(string path);
	void mWorldMapUpdate();
	void mWorldMapUnload();
	void mWorldMapDraw();

	int mRandomEncounter;

	//Hero Class
	cPlayer player1;

private:
	int mWorldWidth;
	int mWorldHeight;

};


class Enemy{
public:
	enum eEnemyType{										//Types of enemies
		__eET_FIGHTER,										//Standard Melee attacks
		__eET_MAGE,											//Standard magic attacks
		__eET_MIX											//Mix of standard magic and melee
	};
public:
	bool isEnemyAlive();
	void setPlayerParams(int, int, int);
private:
	string mName;											//Name of monster
	int mHitPoints;											//HP of monster
	int mExp;												//base XP monster is worth
	int mAttackPower;										//base attack power of monster
	int mDefense;											//base defense of monster
	int mLevel;												//Level of monster, used to adjust base attributes

	bool mIsEnemyAlive;
	int mEnemyWidth;
	int mEnemyHeight;
	int mEnemyZ;

};

class World{
public:
	enum eLocations{										//Town and dungeons located on the world map.
		
	};
public:
	bool isWorld();
	void setWorldParams(int, int, int);
private:
	bool mIsWorld();
	int mWorldWidth;
	int mWorldHeight;
	int mWorldZ;											//Only thing that should be lower than this is collision walls.

};


#endif