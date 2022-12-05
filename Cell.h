#ifndef CELL
#define CELL

#include "State.h"
#include "Value.h"

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
