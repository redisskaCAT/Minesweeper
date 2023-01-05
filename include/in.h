#ifndef IN
#define IN

class In
{
public:
	Coord coord;
	State state;
	In(){}
	In(Coord _coord, State _state)
	{
		coord = _coord;
		state = _state;
	}
};
#endif
