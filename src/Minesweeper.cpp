#include "../include/Minesweeper.h"

Minesweeper::Minesweeper(Field* _field)
{
	field = _field;
}


int Minesweeper::open(Coord coord)
{
	if(field->getState(coord) == CLOSE)
	{
		if(field->getVal(coord) == MINE)
			return 1;
		else
			field->setState(coord, OPEN);
	}
	return 0;
}


int Minesweeper::flag(Coord coord)
{
	if(field->getState(coord) == CLOSE)
	{
		field->setState(coord, FLAG);
		return 1;
	}
	if(field->getState(coord) == FLAG)
	{
		field->setState(coord, CLOSE);
		return -1;
	}
	return 0;
}
