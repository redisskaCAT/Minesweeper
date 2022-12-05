#ifndef MENU
#define MENU

#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

using namespace std;

#include "settings.h"
#include "Record.h"
#include "Coord.h"

class Menu
{
private:
  Record record;
	string username;
	string type;
	bool login;
	Coord center;
	Coord cEnter;
	Coord sizeConsole;
	Coord sizeScreen;
	Coord margin = Coord (3, 1);
	void CUP(Coord coord);
	void clearConsole();
	void centerConsole();
	void showEnter();
	void w_main();
	void w_login();
  void w_field();
  void w_record();
public:
	Menu(bool l);
	Settings launch();
};

#endif
