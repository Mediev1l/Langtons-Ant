#include "Manager.h"

Manager::Manager()
	: _Cells(nullptr), _width(0), _height(0), _dir(Direction::RIGHT), _antX(2), _antY(2)
{
}

Manager::~Manager()
{
	for (size_t i = 0; i < _width; i++)
		delete[] _Cells[i];
	delete[] _Cells;
}

void Manager::setParameters(size_t width, size_t height)
{
	_width = width;
	_height = height;

	_Cells = new Cell*[_width];

	for (size_t i = 0; i < _width; i++)
		_Cells[i] = new Cell[_height];
}

void Manager::addAnt(size_t x, size_t y)
{
	if (x > 1 && x < _width - 1 && y > 1 && y < _height - 1)
	{
		_antX = x;
		_antY = y;
	}	
}

void Manager::init()
{
	enum setter { Default = -1, Width = 0, Height = 1, Ant_X = 2, Ant_Y = 3};
	std::stringstream stream[4];
	std::fstream file;
	std::string line;
	setter mode = Default;

	file.open("Init.init");

	if (!file.good())
		std::cerr << "[ERROR] Couldn't load the \"Init.init\" file" << std::endl;

	while (std::getline(file, line))
	{
		if (line.find("#Settings:") != std::string::npos)
		{
			if (line.find("Init_X") != std::string::npos)
				mode = Width;
			else if (line.find("Init_Y") != std::string::npos)
				mode = Height;
			else if (line.find("Ant_X") != std::string::npos)
				mode = Ant_X;
			else if (line.find("Ant_Y") != std::string::npos)
				mode = Ant_Y;
		}
		else if (line != "")
			stream[(int)mode] << line;
	}

	setParameters(stoi(stream[0].str()), stoi(stream[1].str()));
	addAnt(stoi(stream[2].str()), stoi(stream[3].str()));
}

void Manager::turn()
{
	switch (_dir)
	{
		case UP:
		{
			move(_antX += 1, _antY);
			_dir = RIGHT;
			break;
		}
		case RIGHT:
		{
			move(_antX, _antY += 1);
			_dir = DOWN;
			break;
		}
		case DOWN:
		{
			move(_antX -= 1, _antY);
			_dir = LEFT;
			break;
		}
		case LEFT:
		{
			move(_antX, _antY -= 1);
			_dir = RIGHT;
			break;
		}
	}
}

void Manager::move(size_t x, size_t y)
{
	x > _width - 1 ? _antX = 1 : x;
	x < 1 ? _antX = _width - 2 : x;

	y > _height - 1 ? _antY = 1 : y;
	y < 1 ? _antY = _height - 2 : y;

}

Cell Manager::getCell(size_t x, size_t y)
{
	return _Cells[x][y];
}

size_t Manager::getWidth()
{
	return _width;
}

size_t Manager::getHeight()
{
	return _height;
}

void Manager::analize()
{
	if (_Cells[_antX][_antY].getVisit() == false)
	{
		_Cells[_antX][_antY].setVisit(true);
		_dir = static_cast<Direction>((_dir + 1) % LAST);
	}
	else
	{
		_Cells[_antX][_antY].setVisit(false);
		_dir = static_cast<Direction>((_dir + 2) % LAST);
	}
}



