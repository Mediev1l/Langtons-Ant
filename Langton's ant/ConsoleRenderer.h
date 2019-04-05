#ifndef _Console_Renderer_H
#define _Console_Renderer_H

#include "Game.h"


class ConsoleRenderer : public Game
{
public:

	ConsoleRenderer() : Game() {};

	void Draw() override;

};


#endif