#include "../include/GameControl.h"

#include <iostream>
#include <string>

using namespace std;

GameControl::GameControl()
{
	login = false;
}

void GameControl::go()
{
  int time;
  Settings set;
  
	Menu menu(login);
  	set = menu.launch();
  	login = set.login;
	assemblyGame(set);
	
	display->showGameDisplay();
	
	display->showField();

	time = play();

  if(login && (time > 0))
  {
    //cout << time;
    Record record;
    record.recording(set.username, set.type, time);
  }

  sleep(3);

	field->~Field();
}

int GameControl::play()
{	
	In in;
	
	int time_0;
	clearedMines = 0;

	while((in = display->move()).state == FLAG)
	{
		clearedMines += game->flag(in.coord);
		display->showCountMines(clearedMines);
		display->showState(in.coord, field->getState(in.coord), false);
	}

	field->minning(totalMines, in.coord);
	
	openEmptyCell(in.coord);
	
	Timer timer(display);
	thread th1(&Timer::start, timer);

	while(clearedMines < totalMines)
	{		
		in = display->move();
		if(in.state == FLAG)
		{
			clearedMines += game->flag(in.coord);
			display->showCountMines(clearedMines);
			display->showState(in.coord, field->getState(in.coord), false);
		}
		if(in.state == OPEN)
		{
			if(field->getVal(in.coord) == ZERO)
			{	
				openEmptyCell(in.coord);
			}
			else
			{
				if(game->open(in.coord))
				{
					display->showVal(in.coord, MINE, false);
					break;
				}
				else if (field->getState(in.coord) == OPEN)
					display->showVal(in.coord, field->getVal(in.coord), false);
			}
		}
	}
  if(clearedMines == totalMines)
  {
    display->showEndGameMessange(true);
    th1.join();
    return timer.getTime();
  }
  display->showEndGameMessange(false);
  display->showValue();
  th1.join();
  return -1;
}



void GameControl::openEmptyCell(Coord coord)
{
	Coord c;
	for(int i = coord.y - 1; i <= coord.y + 1; i++)
		for(int j = coord.x - 1; j <= coord.x + 1; j++)
		{
			if(i != coord.y || j != coord.x)
			{
				c = Coord(j, i);
				if(field->checkCollisions(c))
				{
					if(field->getState(c) == CLOSE)
					{
						if(field->getVal(c) == ZERO)
						{	
							game->open(c);
							display->showVal(c, field->getVal(c), false);
							openEmptyCell(c);
						}
						else
						{
							game->open(c);
							display->showVal(c, field->getVal(c), false);
						}
					}
				}
			}
		}
		
}



void GameControl::assemblyGame(Settings settings)
{
	string str;
	int pos = 1;

	ifstream file;
	file.open("../files/configFile.txt");
	
	while(str != settings.type){ getline(file, str); pos++; }
	file >> cols >> rows >> totalMines;
	
	field = new Field(Coord(cols, rows), settings.type);
	
	game = new Minesweeper(field);
	
	display = new ConsoleDisplay(field, Coord(cols, rows), totalMines);

	file.close();
}

