#include "Game_Entity.h"


Game_Entity::Game_Entity(const char * texture_path, SDL_Renderer * ren, int xpos, int ypos)
{
	// initalize texture
	renderer = ren;
	load_texture(texture_path);

	// initalize position
	x = xpos;
	y = ypos;

	// use entire image for texture
	srcRect = new SDL_Rect();
	srcRect->w = image_width;
	srcRect->h = image_height;

	destRect = new SDL_Rect();
	destRect->w = image_width;
	destRect->h = image_height;

}


Game_Entity::~Game_Entity()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);

	if (srcRect)
	{
		delete this->srcRect;
	}
	
	if (destRect)
	{
		delete this->destRect;
	}
}


void Game_Entity::update()
{
	destRect->x = x;
	destRect->y = y;
}


void Game_Entity::render()
{
	SDL_RenderCopy(renderer, texture, srcRect, destRect);
}


void Game_Entity::load_texture(const char * path)
{
	// load image into surface
	SDL_Surface * temp_surface = IMG_Load(path);

	// store original texture sizes
	if (temp_surface->w && temp_surface->h)
	{
		image_width = temp_surface->w;
		image_height = temp_surface->h;
	}
	
	// store texture
	texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
}
