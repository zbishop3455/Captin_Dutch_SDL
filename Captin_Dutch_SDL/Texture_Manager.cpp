#include "Texture_Manager.h"


SDL_Texture * Texture_Manager::load_texture(const char * path, SDL_Renderer * renderer)
{
	SDL_Surface * temp_surface = IMG_Load(path);
	SDL_Texture * loaded_texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	return loaded_texture;
}
