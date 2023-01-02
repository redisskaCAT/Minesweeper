#ifndef CELL
#define CELL

#include "../include/State.h"
#include "../include/Value.h"

class Cell
{
public:
    State state;
    Value val;
    Cell(){}
    Cell(State _state, Value _val)
    {
    	state = _state;
    	val = _val;
    }
};

#endif
