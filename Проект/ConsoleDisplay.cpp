#include "ConsoleDisplay.h"

int getDigits(int x, int d) {
  int n = 0;
  while (x > 0) {
    n++;
    x /= d;
  }
  return n;
}

ConsoleDisplay::ConsoleDisplay(Field* f, Coord _sizeField, int mines) {
  fputs("\e[?25l", stdout);
  field = f;
  inGame = true;
  
  centerConsole();

  totalMines = mines;
  shiftNum = getDigits(_sizeField.y, 10);
  shiftAlf = getDigits(_sizeField.x, 26);

  colsField = _sizeField.x;
  rowsField = _sizeField.y;

  sizeField.x = _sizeField.x * 2 + 1;
  sizeField.y = _sizeField.y;

  sizeScreen.x = sizeField.x + margin.x * 2;
  sizeScreen.y = sizeField.y + 4 + 2 * margin.y;

  cScreen = Coord(center.x - sizeScreen.x / 2, center.y - sizeScreen.y / 2);
  cField = Coord(cScreen.x + margin.x, cScreen.y + 2 * margin.y + 1);

  cur = Coord(sizeField.x / 4 - 1,  sizeField.y / 2 - 1);

  cTimer = Coord(cScreen.x + margin.x, cScreen.y + sizeScreen.y - margin.y - 1);
  cMines = Coord(cScreen.x + sizeScreen.x - margin.x - 7,
                 cScreen.y + sizeScreen.y - margin.y - 1);

}

void ConsoleDisplay::showGameDisplay() {
  clearConsole();

  string stringGame[3] = {"M I N E S W E E P E R", "00/00", "000"};

  // отрисовка белого экрана
  cout << "\033[30;47m";
  for (int i = cScreen.y; i < cScreen.y + sizeScreen.y; i++) {
    CUP(Coord(cScreen.x, i));
    for (int j = cScreen.x; j < cScreen.x + sizeScreen.x; j++)
      cout << ' ';
  }

  // вывод надписи "M I N E S W E E P E R"
  CUP(Coord(center.x - stringGame[0].size() / 2, cScreen.y + margin.y));
  cout << "\033[1;30m" << stringGame[0] << "\033[0m";

  // отрисовка черного прямоугльника под игровое поле
  cout << "\033[37;40m";
  for (int i = cField.y; i < cField.y + sizeField.y; i++) {
    CUP(Coord(cField.x, i));
    for (int j = cField.x; j < cField.x + sizeField.x; j++)
      cout << ' ';
  }

  // отрисовка поле под кол-во мин и таймер
  CUP(cTimer);
  cTimer.x++;
  cout << " 000 ";
  CUP(cMines);
  cMines.x++;
  cout << " 00/" << totalMines << ' ';
}

void ConsoleDisplay::showVal(Coord coord, Value val, bool active) {
  if (active)
    cout << "\033[46m";
  else
    cout << "\033[40m";

   CUP(Coord(cField.x + 2*coord.x + 1, cField.y + coord.y));

  if (val == ZERO)
    cout << " ";

  if (val == NUM1)
    cout << "1";

  if (val == NUM2)
    cout << "2";

  if (val == NUM3)
    cout << "3";

  if (val == NUM4)
    cout << "4";

  if (val == NUM5)
    cout << "5";

  if (val == NUM6)
    cout << "6";

  if (val == NUM7)
    cout << "7";

  if (val == NUM8)
    cout << "8";

  if (val == MINE)
    cout << "\033[31m"
         << "*"
         << "\033[39m";
         
  if (active)
    cout << "\033[40m";
}

void ConsoleDisplay::showState(Coord coord, State state, bool active) {
  if (active)
    cout << "\033[46m";
  else
    cout << "\033[40m";

  CUP(Coord(cField.x + 2*coord.x + 1, cField.y + coord.y));

  if (state == FLAG)
    cout << "\033[32m"
         << "X"
         << "\033[39m";

  if (state == CLOSE)
    cout << "\033[1;37m"
         << "·"
         << "\033[0m"
         << "\033[37;40m";

  if (state == EMPTY)
    cout << " ";
    
   if (active)
    cout << "\033[40m";
}

void ConsoleDisplay::showValue() {
  for (int i = 0; i < rowsField; i++)
  {
    for (int j = 0; j < colsField; j++)
    {
      if (field->getVal(Coord(j, i)) == MINE)
          if(field->getState(Coord(j, i)) != FLAG)
        	showVal(Coord(j, i), MINE, false);
    }
  }
  CUP(Coord(0, sizeConsole.y - 1));
}

char input()
{
   char ch;
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

void ConsoleDisplay::movingCur(bool active)
{
  CUP(cur);
  if(field->getState(cur) == OPEN)
    showVal(cur, field->getVal(cur), active);
  else
    showState(cur, field->getState(cur), active);
}

In ConsoleDisplay::move() {
  char ch;

  movingCur(true);

  while ((ch != 'f') && (ch != 'o'))
  {
    ch = input();
    switch(ch)
    {
      case 'w':
        if(field->checkCollisions(Coord(cur.x, cur.y - 1)))
        {
          movingCur(false);
          cur.y--;
          movingCur(true);
        }
        break;
      case 'a':
        if(field->checkCollisions(Coord(cur.x, cur.x - 1)))
        {
          movingCur(false);
          cur.x--;
          movingCur(true);
        }
        break;
      case 's':
        if(field->checkCollisions(Coord(cur.x, cur.y + 1)))
        {
          movingCur(false);
          cur.y++;
          movingCur(true);
        }
        break;
      case 'd':
        if(field->checkCollisions(Coord(cur.x, cur.x + 1)))
        {
          movingCur(false);
          cur.x++;
          movingCur(true);
        }
        break;
    }
  }
  if(ch == 'o')
    return In(cur, OPEN);
  return In(cur, FLAG);
}

bool ConsoleDisplay::showTimer(int time) {
  CUP(cTimer);
  cout.width(3);
  cout.fill('0');
  cout << time << endl;
  return inGame;
}

void ConsoleDisplay::showCountMines(int mines) {
  	CUP(cMines);
  	cout.width(2);
  	cout.fill('0');
  	cout << mines;
}

void ConsoleDisplay::showField() {
  for (int i = 0; i < rowsField; i++) {
    CUP(Coord(cField.x, cField.y + i + 1));
    for (int j = 0; j < colsField; j++) {
      //if (i < 0 || j < 0)
      //  showFrame(Coord(j, i));
      //else
      //{
        if((j == cur.x) && (i == cur.y))
          showState(Coord(j, i), field->getState(Coord(j, i)), true);
        else
          showState(Coord(j, i), field->getState(Coord(j, i)), false);
      //}
    }
    cout << endl;
  }
}

void ConsoleDisplay::showFrame(Coord coord) {

  if (coord.y == -1 && coord.x >= 0) {
    if (coord.x > 25)
      cout << char('a' + (coord.x / 25) - 1) << char('a' + (coord.x % 25) - 1)
           << ' ';
    else
      printf("%-*c ", shiftAlf, char('a' + coord.x));
  }

  if (coord.x == -1 && coord.y >= 0)
    printf("%*d ", shiftNum, coord.y + 1);

  if (coord.y == -1 && coord.x == -1)
    printf("%*c ", shiftNum, ' ');
}

void ConsoleDisplay::showEndGameMessange(bool win) {
  inGame = false;
  CUP(Coord(cTimer.x + 4, cTimer.y));
  for (int j = 0; j < sizeField.x - 12; j++) {
    cout << ' ';
  }
  if (win) {
    CUP(Coord(center.x - 4, cTimer.y));
    cout << "\033[32m"
         << "YOU WIN!"
         << "\033[39m";
  } else {
    CUP(Coord(center.x - 4, cTimer.y));
    cout << "\033[31m"
         << "YOU LOSE!"
         << "\033[39m";
  }
  CUP(Coord(0, sizeConsole.y - 1));
}

void ConsoleDisplay::centerConsole() {
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  sizeConsole = Coord(w.ws_col, w.ws_row);
  center.x = w.ws_col / 2;
  center.y = w.ws_row / 2;
}

void ConsoleDisplay::CUP(Coord coord) {
  cout << "\033[" << coord.y << ";" << coord.x << "H";
}

void ConsoleDisplay::clearConsole() {
  cout << "\033[0m";
  printf("\e[1;1H\e[2J");
}
