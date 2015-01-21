//
// player.cpp
//

#include "main.h"

//Player base constructor
Player::Player()
{
	mSpriteSheet.LoadTexture("G:\\code\\SDLtest\\Win32\\Debug\\skelly.png");
	mSpriteSheet.SetClips(5);
	mVelocityX = 0;
	mVelocityY = 0;
};

//Create a new Player at coordinates X, Y
Player::Player(int x, int y)
{
	mSpriteSheet.LoadTexture("G:\\code\\SDLtest\\Win32\\Debug\\skelly.png");
	mSpriteSheet.SetClips(5);
	mPosition.x = x;
	mPosition.y = y;
	mVelocityX = 0;
	mVelocityY = 0;
	//DEBUG PRINT
	std::cout << "New player created at position (" << mPosition.x << ", " << mPosition.y << ")" << std::endl;
};

//Player base destructor
Player::~Player()
{
	mSpriteSheet.FreeTexture();
};

void Player::HandleInput(const Uint8 *ks) //(SDL_Event *evt)
{
	if (ks[SDL_SCANCODE_A]) {
		if (abs(mVelocityX) <= (gMaxSpeed - gVelocityScale)) {
			mVelocityX -= gVelocityScale;
		}
	}
	else if (ks[SDL_SCANCODE_D]) {
		if (mVelocityX <= (gMaxSpeed - gVelocityScale))
		mVelocityX += gVelocityScale;
	}
	else if (ks[SDL_SCANCODE_W]) {
		if (abs(mVelocityY) <= (gMaxSpeed - gVelocityScale)) {
			mVelocityY -= gVelocityScale;
		}
	}
	else if (ks[SDL_SCANCODE_S]) {
		if (mVelocityY <= (gMaxSpeed - gVelocityScale)) {
			mVelocityY += gVelocityScale;
		}
	}
	else {
		mVelocityX = 0;
		mVelocityY = 0;
	}

	//Handling keyboard input via SDL_KEYDOWN and SDL_KEYUP
	//switch (evt->type) {
	//	//KEY PRESSED
	//	case SDL_KEYDOWN:
	//		switch (evt->key.keysym.scancode) {

	//			//LEFT PRESSED
	//			case SDL_SCANCODE_A:
	//				mVelocityX -= gVelocityScale;
	//				std::cout << "kd.left" << std::endl;
	//				break;
	//			
	//			//RIGHT PRESSED
	//			case SDL_SCANCODE_D:
	//				mVelocityX += gVelocityScale;
	//				std::cout << "kd.right" << std::endl;
	//				break;
	//		
	//			//UP PRESSED
	//			case SDL_SCANCODE_W:
	//				mVelocityY -= gVelocityScale;
	//				std::cout << "kd.up" << std::endl;
	//				break;

	//			//DOWN PRESSED
	//			case SDL_SCANCODE_S:
	//				mVelocityY += gVelocityScale;
	//				std::cout << "kd.down" << std::endl;
	//				break;
	//			
	//			//default
	//			default:
	//				break;
	//		}
	//		break;

	//	//KEY RELEASED
	//	case SDL_KEYUP:
	//		switch (evt->key.keysym.sym) {

	//			//LEFT RELEASED
	//			case SDLK_LEFT:
	//				if (mVelocityX < 0) {
	//					mVelocityX = 0;
	//				}
	//				std::cout << "ku.left" << std::endl;
	//				break;
	//			//RIGHT RELEASED
	//			case SDLK_RIGHT:
	//				if (mVelocityX > 0) {
	//					mVelocityX = 0;
	//				}
	//				std::cout << "ku.right" << std::endl;
	//				break;
	//			//UP RELEASED
	//			case SDLK_UP:
	//				if (mVelocityY < 0) {
	//					mVelocityY = 0;
	//				}
	//				std::cout << "ku.up" << std::endl;
	//				break;
	//			//DOWN RELEASED
	//			case SDLK_DOWN:
	//				if (mVelocityY > 0) {
	//					mVelocityY = 0;
	//				}
	//				std::cout << "ku.down" << std::endl;
	//				break;
	//			//default
	//			default:
	//				break;
	//		}
	//		break;
	//}
	if (   mPosition.x >= 0
		|| mPosition.y >= 0
		|| mPosition.x > (640 - this->mSpriteSheet.getWidth()) 
		|| mPosition.y > (480 - this->mSpriteSheet.getHeight())) {

		if (mPosition.x < 0) { mPosition.x = 0; }
		if (mPosition.y < 0) { mPosition.y = 0; }
		if (mPosition.x > 640) { mPosition.x = (640 - this->mSpriteSheet.getWidth()); }
		if (mPosition.y > 480) { mPosition.y = (480 - this->mSpriteSheet.getHeight()); }
	}
	mPosition.x += mVelocityX;
	mPosition.y += mVelocityY;

	//std::cout << "Velocity X: " << mVelocityX << std::endl;
	//std::cout << "Velocity Y: " << mVelocityY << std::endl;
	//std::cout << "Pos X: " << this->mPosition.x << std::endl;
	//std::cout << "Pos Y: " << this->mPosition.y << std::endl;
}