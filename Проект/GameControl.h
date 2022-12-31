#ifndef GAMECONTROL
#define GAMECONTROL

#include <fstream>
#include <string>

using namespace std;

#include "Coord.h"
#include "State.h"
#include "Value.h"
#include "in.h"
#include "settings.h"
#include "Menu.h"
#include "Field.h"
#include "Timer.h"
#include "ConsoleDisplay.h"
#include "Minesweeper.h"

class GameControl
{
private:
	int totalMines;
	int clearedMines;
	int cols;
	int rows;
	bool login;
	Minesweeper* game;
	Field* field;
	ConsoleDisplay* display;
	int play();
	void openEmptyCell(Coord coord);
	void assemblyGame(Settings settings);
public:
	GameControl();
	void go();
};

#endif
