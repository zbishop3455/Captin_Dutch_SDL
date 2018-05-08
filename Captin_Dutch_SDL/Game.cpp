#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}


// Initalizes SDL and game components
void Game::init(int xpos, int ypos, int width, int height, bool fullscreen)
{

	// flags for window
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initalized" << std::endl;

		// create window and renderer
		this->window = SDL_CreateWindow(this->title, xpos, ypos, width, height, flags);
		this->renderer = SDL_CreateRenderer(window, -1, 0);

		if (window && renderer)
		{
			this->is_running = true;
		}
		else 
		{
			this->is_running = false;
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		test = Texture_Manager::load_texture("assets/BOAR.BMP", this->renderer);

	}
}


void Game::handle_events(void)
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		this->is_running = false;
		break;
	}
	
}


void Game::update(void)
{

}


void Game::render(void)
{
	
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->test, NULL, NULL);
	SDL_RenderPresent(this->renderer);

}

void Game::clean(void)
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
	std::cout << "Cleaned Up!" << std::endl;
}

