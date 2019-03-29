#include "Game.h"

Game::Game()
{
}

void Game::Start()
{
	init();

	//for (int i = 0; i < Game::_width; i++)
	//{
	//	for (int j = 0; j < Game::_height; j++)
	//		if (Game::_Cells[i][j].getVisit() == true)
	//			std::cout << i << " "<< j << ": true\n";
	//		else 
	//			std::cout << i << " " << j << ": false\n";
	//}

	while (1)
	{
		
	
		system("cls");
		Draw();
		Game::analize();
		Game::turn();
		Sleep(100);
	}


}