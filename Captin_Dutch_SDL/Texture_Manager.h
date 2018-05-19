#pragma once

#include "Game.h"

// Helper method to return texture object from an image path

class Texture_Manager
{

public:

	static SDL_Texture * load_texture(const char* path, SDL_Renderer* renderer);

};

