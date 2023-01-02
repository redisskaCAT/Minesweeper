#ifndef GAMECONTROL
#define GAMECONTROL

#include <fstream>
#include <string>

using namespace std;

#include "../include/Coord.h"
#include "../include/State.h"
#include "../include/Value.h"
#include "../include/in.h"
#include "../include/settings.h"
#include "../include/Menu.h"
#include "../include/Field.h"
#include "../include/Timer.h"
#include "../include/ConsoleDisplay.h"
#include "../include/Minesweeper.h"

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
