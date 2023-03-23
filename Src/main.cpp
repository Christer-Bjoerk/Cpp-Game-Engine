#include "SDL.h"
#include "Game.h"

int main(int argc, char* argv[]) 
{
	const Uint32 width = 800;
	const Uint32 height = 640;

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game* game = nullptr;

	game = new Game();

	game->init("Salty Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);

	while (game->Running())
	{
		frameStart = SDL_GetTicks64();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks64() - frameStart;

		// Capping the frame rate
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->Clean();

	return 0;
}