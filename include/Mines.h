#ifndef MINES
#define MINES

#include <ctime>
#include <stdlib.h>

#include "../include/Coord.h"
#include "../include/Value.h"
#include "../include/State.h"
#include "../include/Cell.h"

class Mines
{
private:
    int rows;
    int cols;
    Cell** field;
    void addNum(Coord coord);
public:
    Mines(Cell** _field, Coord size);
    void create(int totalMines, Coord coord_0);
};

#endif
