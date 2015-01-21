//
// timer.h
//

#ifndef _H_TIMER
#define _H_TIMER

class Timer
{
public:
	Timer();
	~Timer();

	void Start();
	void Stop();
	void Pause();
	void Unpause();

	Uint32 GetTicks();

	bool GetStartStatus();
	bool GetPauseStatus();

private:
	Uint32 mTicks = SDL_GetTicks();

	Uint32 mPausedTicks;

	bool mStarted;
	bool mPaused;
};

#endif