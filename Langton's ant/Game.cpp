#include "Game.h"

Game::Game()
{
	hndl = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Game::Start()
{
	init();

	while (1)
	{
		Draw();
		Game::analize();
		Game::turn();
		Sleep(500);
	}

}