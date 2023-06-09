#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() { return isRunning; }
	
	static SDL_Renderer* renderer;

private:
	int cnt = 0; 
	bool isRunning;
	SDL_Window* window;

};

