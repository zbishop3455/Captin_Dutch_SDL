#pragma once
#include "Entity.h"
#include "Game.h"
class Game_Entity : public Entity
{

public:
	Game_Entity(const char * texture_path, SDL_Renderer * ren, int xpos, int ypos);
	~Game_Entity();

	void update();
	void render();

private:
	void load_texture(const char * path);

};

