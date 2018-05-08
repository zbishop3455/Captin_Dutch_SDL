#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Texture_Manager.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(int xpos, int ypos, int width, int height, bool fullscreen);

	void handle_events(void);
	void update(void);
	void render(void);
	void clean(void);

	bool is_running;

private:
	const char * title = "Captin Dutch Adventures";
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Texture * test;
};

