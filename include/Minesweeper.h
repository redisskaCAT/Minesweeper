#ifndef MINESWEEPER
#define MINESWEEPER


#include "../include/Coord.h"
#include "../include/State.h"
#include "../include/Value.h"
#include "../include/Field.h"

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
