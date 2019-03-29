#ifndef Manager_H
#define Manager_H

#include <sstream>
#include <fstream>
#include <iostream>

#include "Cell.h"

class Manager
{
public:
	enum Direction
	{
		UP = 0,
		RIGHT = 1,
		DOWN = 2,
		LEFT = 3,
		LAST = 4
	};
protected:
	Cell** _Cells;

	Direction _dir;

	size_t _width;
	size_t _height;

	size_t _antX;
	size_t _antY;
public:
	Manager();
	virtual ~Manager();

	void setParameters(size_t width, size_t height);

	void addAnt(size_t x, size_t y);

	void init();
	void turn();
	void move(size_t x, size_t y);
	void analize();

	size_t getWidth();
	size_t getHeight();

	Cell getCell(size_t x, size_t y);
};


#endif