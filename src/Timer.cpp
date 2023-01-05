#include "../include/Timer.h"

Timer::Timer()
{
	playTime = 0;
}

Timer::Timer(ConsoleDisplay* _display)
{
	work = true;
	display = _display;
	playTime = 0;
}

void CUP(Coord coord)
{
  cout << "\033[" << coord.y << ";" << coord.x << "H";
}


void Timer::start()
{
	while(work)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		work = display->showTimer(playTime);
		this_thread::sleep_for(chrono::milliseconds(500));
		playTime++;
	}
	//cout << "Timer stop";
}

int Timer::getTime()
{
	return playTime;
}
