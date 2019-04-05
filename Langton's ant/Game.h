#ifndef _Game_H
#define _Game_H

#include "Manager.h"
#include <Windows.h>

class Game : public Manager
{
protected:
	HANDLE hndl;
public:
	Game();

	void Start();

	HANDLE getHandle() { return hndl; };

	virtual void Draw() = 0;
};


#endif