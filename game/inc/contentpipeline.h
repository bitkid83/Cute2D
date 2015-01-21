//
// contentpipeline.h
//

#ifndef _CONTENT_PIPELINE_H
#define _CONTENT_PIPELINE_H

//TODO(PaulH): Move to a new mathutil.h
struct vec2
{
	int x, y;
};

class Texture
{
public:
	Texture();
	~Texture();
	
	bool LoadTexture(const char *filename);	
	void FreeTexture();
	virtual void RenderTexture(int x, int y);
	
	int getWidth();
	int getHeight();

protected:
	SDL_Texture *mTexture;
	int mWidth, mHeight;
};

class SpriteSheet : public Texture
{
public:
	SDL_Rect *SetClips(const int framecount);
	SDL_Rect *mClips;
	void RenderTexture(int x, int y);

private:
	int mCurrentFrame = 0;
	int mFrameCount;
};

#endif