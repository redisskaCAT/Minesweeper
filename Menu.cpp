#include "Menu.h"

Menu::Menu(bool l)
{
	login = l;
}

Settings Menu::launch()
{
  /*
	w_main();

  bool main = true;
	
	char in = '0';
	
	while(in != 'p')
	{
		cin >> in;
		switch(in)
		{
			case 'l':
				if(login)
				{
					login = false;
					username = "";
				}
				else
				{
					w_login();
				}
				w_main();
        main = true;
				break;	
      case 'r':
        main = false;
        w_record();
				break;	
			case 'u':
				break;	
      
			case 'E':
        if(main)
        {
          clearConsole();
          exit(1);
        }
        else
        {
          w_main();
        }
				break;
      
			default :
				showEnter();
				;
		}
	}

  w_field();
  cin >> type;
  if(login)
    return Settings(type, username);
	return Settings(type);
  */
  return Settings("c");
}



void Menu::w_main()
{
	clearConsole();
	
	centerConsole();
	
	if(login)
	{
		sizeScreen = Coord(23, 11);
	}
	else
	{
		sizeScreen = Coord(23, 10);
	}
	
	string stringMenuNoLogin[5] = {"M E N U",
								   "l - log in",
							       "p - play",
							       "u - rule",
							       "E - exit"};
	
	string stringMenuLogin[6] = {"M E N U",
								 "l - log out",
							     "p - play",
							     "r - show record",
							     "u - rule",
							     "E - exit"};
				
	Coord cScreen = Coord(center.x - sizeScreen.x / 2, center.y - sizeScreen.y / 2);
	
	CUP(cScreen);
		
	// отрисовка белого экрана
	cout << "\033[30;47m";
	for(int i = cScreen.y; i < cScreen.y + sizeScreen.y; i++)
	{
		CUP(Coord(cScreen.x, i));
		for(int j = cScreen.x; j < cScreen.x + sizeScreen.x; j++)
			cout << ' ';
	}
	
	// вывод надписи "M E N U"
	CUP(Coord(center.x - stringMenuLogin[0].size()/2,  cScreen.y + margin.y ));
	cout << "\033[1;30m" << stringMenuLogin[0] << "\033[0m" << "\033[30;47m";
	
	Coord c = cScreen;
	c.x += margin.x;
	c.y += 2*margin.y;
	
	if(login)
	{
		for(int i = 1; i < 6; i++)
		{
			c.y += margin.y;
			CUP(c);
			cout << stringMenuLogin[i];
		}
	}
	else
	{
		for(int i = 1; i < 5; i++)
		{
			c.y += margin.y;
			CUP(c);
			cout << stringMenuNoLogin[i];
		}
	}
	
	cEnter = Coord(c.x, c.y + 2*margin.y);
	showEnter();
	
}

void Menu::w_login()
{
	clearConsole();
	
	string stringLogin[2] = {"L O G   I N",
							 "Enter the user name."};
							 
	sizeScreen = Coord(26, 7);
							 
	Coord cScreen = Coord(center.x - sizeScreen.x / 2, center.y - sizeScreen.y / 2);
	
	CUP(cScreen);
		
	// отрисовка белого экрана
	cout << "\033[30;47m";
	for(int i = cScreen.y; i < cScreen.y + sizeScreen.y; i++)
	{
		CUP(Coord(cScreen.x, i));
		for(int j = cScreen.x; j < cScreen.x + sizeScreen.x; j++)
			cout << ' ';
	}
	
	CUP(Coord(center.x - stringLogin[0].size()/2,  cScreen.y + margin.y ));
	cout << "\033[1;30m" << stringLogin[0] << "\033[0m" << "\033[30;47m";
	
	CUP(Coord(cScreen.x + margin.x, cScreen.y + 3*margin.y));
	cout << stringLogin[1];
	
	cEnter = Coord(cScreen.x + margin.x, cScreen.y + 5*margin.y);
	
	showEnter();
	
	cin >> username;
  
	if(username != "E")
  {
	  login = true;
    record.login(username);
  }
}

void Menu::w_field()
{
  clearConsole();
				
	string stringField[6] = {"M E N U",
							"r1 = rectangle 10x10 - 10",
							"r2 = rectangle 16x16 - 40",
							"r3 = rectangle 30x16 - 99",
							"c  = cyrcle    15x15 - 25",
							"tr = triangle  19x19 - 30"};
	
  sizeScreen = Coord(31, 11);
							 
	Coord cScreen = Coord(center.x - sizeScreen.x / 2, center.y - sizeScreen.y / 2);
	
	CUP(cScreen);
		
	// отрисовка белого экрана
	cout << "\033[30;47m";
	for(int i = cScreen.y; i < cScreen.y + sizeScreen.y; i++)
	{
		CUP(Coord(cScreen.x, i));
		for(int j = cScreen.x; j < cScreen.x + sizeScreen.x; j++)
			cout << ' ';
	}
	
	CUP(Coord(center.x - stringField[0].size()/2,  cScreen.y + margin.y ));
	cout << "\033[1;30m" << stringField[0] << "\033[0m" << "\033[30;47m";
	
	CUP(Coord(cScreen.x + margin.x, cScreen.y + 3*margin.y));
	cout << stringField[1];

  Coord c = cScreen;
	c.x += margin.x;
	c.y += 2*margin.y;
	
	for(int i = 1; i < 6; i++)
	{
		c.y += margin.y;
		CUP(c);
		cout << stringField[i];
	}
  
	cEnter = Coord(cScreen.x + margin.x, c.y + 2*margin.y);
	
	showEnter();
  
}

void Menu::w_record()
{
  clearConsole();
				
	string stringField[6] = {"R E C O R D",
							"rectangle 10x10 - 10  =  ",
							"rectangle 16x16 - 40  =  ",
							"rectangle 30x16 - 99  =  ",
							"cyrcle    15x15 - 25  =  ",
							"triangle  19x19 - 30  =  "};

  string strType[5] = {"r1", "r2", "r3", "c", "tr"};
	
  sizeScreen = Coord(35, 11);
							 
	Coord cScreen = Coord(center.x - sizeScreen.x / 2, center.y - sizeScreen.y / 2);
	
	CUP(cScreen);
		
	// отрисовка белого экрана
	cout << "\033[30;47m";
	for(int i = cScreen.y; i < cScreen.y + sizeScreen.y; i++)
	{
		CUP(Coord(cScreen.x, i));
		for(int j = cScreen.x; j < cScreen.x + sizeScreen.x; j++)
			cout << ' ';
	}
	
	CUP(Coord(center.x - stringField[0].size()/2,  cScreen.y + margin.y ));
	cout << "\033[1;30m" << stringField[0] << "\033[0m" << "\033[30;47m";

  Coord c = cScreen;
	c.x += margin.x;
	c.y += 2*margin.y;

	for(int i = 0; i < 5; i++)
  {
		c.y += margin.y;
		CUP(c);
    cout << stringField[i+1];
    int www;
    www = record.getRecord(username, "r1");
    printf("%3d\n", record.getRecord(username, strType[i]) );
	}

	cEnter = Coord(cScreen.x + margin.x, c.y + 2*margin.y);
	
	showEnter();
  
}

void Menu::showEnter()
{
	CUP(cEnter);
	cout << "\033[37;40m";
	cout << " Enter : ";
	for(int i = 0; i < sizeScreen.x - 2*margin.x - 9; i++) { cout << ' '; }
	CUP(Coord(cEnter.x + 9, cEnter.y));
}

void Menu::CUP(Coord coord)
{
  cout << "\033[" << coord.y << ";" << coord.x << "H";
} 

void Menu::centerConsole()
{
	struct winsize w;
  	ioctl(0, TIOCGWINSZ, &w);
  	sizeConsole = Coord(w.ws_col, w.ws_row);
	center.x = w.ws_col / 2;
	center.y = w.ws_row / 2;
}

void Menu::clearConsole()
{
	cout << "\033[0m";
	printf("\e[1;1H\e[2J");
}
