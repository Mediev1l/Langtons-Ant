#include "ConsoleRenderer.h"

void ConsoleRenderer::Draw()
{
	for (int i = 0; i < Game::_height; i++)
	{
		for (int j = 0; j < Game::_width; j++)
		{
			if (i == Game::_antX && j == Game::_antY)
				std::cout << "x";
			else if (i == 0 || i == Game::_height - 1 || j == 0 || j == Game::_width - 1)
				std::cout << "#";
			else if (Game::_Cells[j][i].getVisit() == true)
				std::cout << "@";
			else
				std::cout << " ";
				
		}
		std::cout << std::endl;
	}
}