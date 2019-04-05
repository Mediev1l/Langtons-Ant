#include "Game.h"

Game::Game()
{}

void Game::Start()
{
	init();

	while (1)
	{
		Draw();
		Game::analize();
		Game::turn();
	}

}