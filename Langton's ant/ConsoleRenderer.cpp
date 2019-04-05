#include "ConsoleRenderer.h"

void ConsoleRenderer::Draw()
{

	SetConsoleCursorPosition(hndl, COORD{ 0,0 });

	for (size_t i = 0; i < Game::_height; i++)
	{
		for (size_t j = 0; j < Game::_width; j++)
		{
			if (j == Game::_antX && i == Game::_antY)
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

	Sleep(500);
}