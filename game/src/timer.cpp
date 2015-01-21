//
// timer.cpp
//

#include "main.h"

Timer::Timer()
{
	mTicks = 0;
	mPausedTicks = 0;

	mPaused = false;
	mStarted = false;
};

Timer::~Timer() { };

void Timer::Start()
{
	//Start timer
	mStarted = true;
	//Unpause timer
	mPaused = false;

	mTicks = SDL_GetTicks();
	mPausedTicks = 0;
};

void Timer::Stop()
{
	mStarted = false;
	mPaused = false;
	mTicks = 0;
	mPausedTicks = 0;
};

void Timer::Pause()
{
	if (mStarted && !mPaused) {
		mPaused = true;
		mPausedTicks = SDL_GetTicks() - mTicks;
		mTicks = 0;
	}
}

void Timer::Unpause()
{
	if (mStarted && mPaused) {
		mPaused = false;
		mTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
};

Uint32 Timer::GetTicks()
{
	Uint32 time = 0;

	if (mStarted) {
		if (mPaused) {
			time = mPausedTicks;
		}
		else {
			time = SDL_GetTicks() - mTicks;
		}
	}

	return time;
};

bool Timer::GetStartStatus()
{
	return mStarted;
};

bool Timer::GetPauseStatus()
{
	return mPaused;
};

