#pragma once

struct SDL_Texture;
struct SDL_Rect;
struct SDL_Renderer;


// base interface for all game objects
class Entity
{

public:

	virtual ~Entity()
	{
		
	}

	virtual void update(void) = 0;
	virtual void render(void) = 0;

	// position
	int x;
	int y;

protected:
	SDL_Texture * texture;
	int image_width;
	int image_height;
	SDL_Rect * srcRect;
	SDL_Rect * destRect;
	SDL_Renderer * renderer;
};

