#include "../include/Field.h"

Field::Field(Coord size, string type)
{
	cols = size.x;
	rows = size.y;
	field = (Cell**)malloc(rows*sizeof(Cell**));
	for(int i = 0; i < rows; i++)
	{
		field[i] = (Cell*)malloc(cols*sizeof(Cell*));
	}
	filling(type);
}

void Field::filling(string type)
{
	string str;

	ifstream file;
	file.open("../files/configFile.txt");

	while(str != type){ getline(file, str);}
	getline(file, str);

	for(int i = 0; i < rows; i++)
	{
		getline(file, str);

		for(int j = 0; j < cols; j++)
		{
			if(str[j] == '1')
			{
				field[i][j].state = CLOSE;
				field[i][j].val = ZERO;
			}
			if(str[j] == '0')
			{
				field[i][j].state = EMPTY;
				field[i][j].val = NOEXIT;
			}
		}
	}
	file.close();
}

int Field::checkCollisions(Coord coord)
{
	if(coord.x < 0 || coord.x >= cols || coord.y < 0 || coord.y >= rows)
		return 0;
	else
		return 1;
}


void Field::minning(int totalMines, Coord coord_0)
{
	Mines mines(field, Coord(cols, rows));
    mines.create(totalMines, coord_0);
}


void Field::setState(Coord coord, State state)
{
	field[coord.y][coord.x].state = state;
}


Value Field::getVal(Coord coord)
{
	return field[coord.y][coord.x].val;
}


State Field::getState(Coord coord)
{
	return field[coord.y][coord.x].state;
}


Field::~Field()
{
	for(int i = 0; i < rows; i++)
		delete [] field[i];
	delete []field;
}


