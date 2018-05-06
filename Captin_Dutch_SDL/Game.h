#pragma once
#include "SDL.h"
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
	SDL_Window * window;
	SDL_Renderer * renderer;
};

