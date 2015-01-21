//
// engine.cpp
//

#include "main.h"

SDL_Surface *gScreenSurface;
SDL_Renderer *gRenderer;
SDL_Window *gWindow;

const int gMaxSpeed = 30;
const int gVelocityScale = 5;
const int gFriction = 5;

Player *self;
Timer gTimer;

bool Game::Init()
{
	gWindow = nullptr;
	gScreenSurface = nullptr;

	//Initialize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialize SDL_VIDEO.\nSDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else {
		//Create pointer to the game window
		gWindow = SDL_CreateWindow("Game Test", WINDOW_POS_X, WINDOW_POS_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == nullptr) {
			std::cout << "Could not initialize main window.\nSDL_Error: " << SDL_GetError() << std::endl;
			return false;
		}
		//Success!
		else {
			//Create pointer to the window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			//Create rendering context from the window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			
			//Initialize SDL2_image
			if (!IMG_Init(IMG_INIT_PNG)) {
				std::cout << "Could not initialize SDL_Image : IMG_INIT_PNG!\nIMG_Error: " << IMG_GetError() << std::endl;
				return false;
			}
		}
		
		//Create new Player
		self = new Player(0, 0);
		gTimer.Start();
	}
	return true;
};

void Game::Refresh()
{
	bool quit = false;
	SDL_Event evt;	
	int count = 0;

	while (!quit) {
		const Uint8 *keyStates = SDL_GetKeyboardState(nullptr);

		while (SDL_PollEvent(&evt) != 0) {
			switch (evt.type) {
				case SDL_QUIT:
					quit = true;
					break;
			}
		}

		//Get Player's input
		self->HandleInput(keyStates);

		SDL_RenderClear(gRenderer);
		
		//Render Player's sprite
		self->mSpriteSheet.RenderTexture(self->mPosition.x, self->mPosition.y);
		
		SDL_Delay(50);
		SDL_RenderPresent(gRenderer);
	}
	
};

void Game::Shutdown()
{
	SDL_DestroyWindow(gWindow);

	gWindow = nullptr;
	gScreenSurface = nullptr;
	gRenderer = nullptr;

	IMG_Quit();
	SDL_Quit();
};
