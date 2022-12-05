#include "Timer.h"

Timer::Timer()
{
	playTime = 0;
}

Timer::Timer(ConsoleDisplay* _display)
{
	display = _display;
	playTime = 0;
}

void CUP(Coord coord)
{
  cout << "\033[" << coord.y << ";" << coord.x << "H";
}


void Timer::start()
{
	work = true;
	
	while(work)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		display->showTimer(playTime);
		this_thread::sleep_for(chrono::milliseconds(500));
		playTime++;
	}
}

void Timer::stop()
{
	work = false;
}

int Timer::getTime()
{
	return playTime;
}
