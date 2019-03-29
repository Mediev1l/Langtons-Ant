#ifndef _Cell_H
#define _Cell_H

class Cell
{
protected:
	bool _visit;
public:
	Cell() : _visit(false) {};

	void setVisit(bool visit) {	_visit = visit;	};

	bool getVisit() { return _visit; };

	Cell& operator = (const Cell& c)
	{
		if (this != &c)
			_visit = c._visit;

		return *this;
	}
};


#endif