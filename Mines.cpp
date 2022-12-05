#include "Mines.h"

Mines::Mines(Cell** _field, Coord size)
{
	field = _field;
	cols = size.x;
	rows = size.y;
	
}
    
void Mines::addNum(Coord coord)
{
	for(int i = coord.y - 1; i <= coord.y + 1; i++)
		for(int j = coord.x - 1; j <= coord.x + 1; j++)
		{
			if(j >= 0 && j < cols && i >= 0 && i < rows)
				if(field[i][j].val != MINE && field[i][j].val != NOEXIT)
				{
					field[i][j].val = static_cast<Value>(static_cast<int>(field[i][j].val) + 1);
				}
		}
}
    
void Mines::create(int totalMines, Coord coord_0)
{
	Coord coord;
	srand(time(0));

	int i = 0;
	while(i < totalMines)
	{
		coord.x = rand() % cols;
		coord.y = rand() % rows;
		if( (coord.x < coord_0.x - 1) || (coord.x > coord_0.x + 1) || (coord.y < coord_0.y - 1) || (coord.y > coord_0.y + 1))
		{
			if(field[coord.y][coord.x].val != MINE && field[coord.y][coord.x].val != NOEXIT)
			{
				field[coord.y][coord.x].val = MINE;
				addNum(coord);
				i++;
			}
		}
	}
}
