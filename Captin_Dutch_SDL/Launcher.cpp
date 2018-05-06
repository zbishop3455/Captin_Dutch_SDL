#include "Game.h"


int main(int argc, char *argv[])
{

	int window_width = 900;
	int window_height = 600;

	Game * game = new Game();

	game->init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, false);

	while (game->is_running)
	{
		game->handle_events();
		game->update();
		game->render();
	}

	game->clean();

	return 0;

}