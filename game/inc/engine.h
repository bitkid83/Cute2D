//
// engine.h
//

#ifndef _ENGINE_H
#define _ENGINE_H

extern SDL_Surface *gScreenSurface;
extern SDL_Renderer *gRenderer;
extern SDL_Window *gWindow;

extern const int gMaxSpeed;
extern const int gVelocityScale;
extern const int gFriction;



class Game
{
private:
	const int WINDOW_POS_X = 50;
	const int WINDOW_POS_Y = 50;
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

public:
	bool Init();
	void Refresh();
	void Shutdown();
};

#endif