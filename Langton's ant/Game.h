#ifndef _Game_H
#define _Game_H

#include "Manager.h"
#include <Windows.h>

class Game : public Manager
{
public:
	Game();

	void Start();

	virtual void Draw() = 0;
};


#endif