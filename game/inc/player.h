//
// player.h
//

#ifndef _H_PLAYER
#define _H_PLAYER

class Player
{

friend class SpriteSheet;

public:
	Player();
	Player(int x, int y);
	~Player();
	
	vec2 mPosition;
	int mVelocityX, mVelocityY;

	void HandleInput(const Uint8 *ks); //(SDL_Event *evt);

	//Player's Sprite Sheet object
	SpriteSheet mSpriteSheet;

private:
	//Player health
	int mHealth;
};

#endif