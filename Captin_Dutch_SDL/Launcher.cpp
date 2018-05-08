#include "Game.h"


int main(int argc, char *argv[])
{

	// window variables
	const int window_width = 900;
	const int window_height = 600;
	bool fullscreen = false;

	// loop variables
	const int FPS = 60;
	const int frame_delay = 1000 / FPS;
	Uint32 frame_start;
	int frame_time;

	// game setup
	Game * game = new Game();
	game->init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, fullscreen);


	// game loop
	while (game->is_running)
	{
		frame_start = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		// handle frame delay if needed
		frame_time = SDL_GetTicks() - frame_start;
		if (frame_delay > frame_time)
		{
			SDL_Delay(frame_delay - frame_time);
		}

	}

	game->clean();

	return 0;

}