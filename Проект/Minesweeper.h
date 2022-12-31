#ifndef MINESWEEPER
#define MINESWEEPER


#include "Coord.h"
#include "State.h"
#include "Value.h"
#include "Field.h"

class Minesweeper
{
private:
	Field* field;
public:
	Minesweeper(Field* field);
	int open(Coord coord);
	int flag(Coord coord);;
};

#endif
