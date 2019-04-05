#ifndef _Console_Renderer_H
#define _Console_Renderer_H

#include "Game.h"
#include <Windows.h>


class ConsoleRenderer : public Game
{
protected:
	HANDLE hndl;
public:

	ConsoleRenderer() : Game() { hndl = GetStdHandle(STD_OUTPUT_HANDLE); };

	void Draw() override;

};


#endif