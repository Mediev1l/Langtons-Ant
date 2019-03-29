#include "Game.h"

Game::Game()
{
}

void Game::Start()
{
	init();

	while (1)
	{
		system("cls");
		Draw();
		Game::analize();
		Game::turn();
		Sleep(1000);
	}

}