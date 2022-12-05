#ifndef TIMER
#define TIMER

#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <mutex>

using namespace std;


#include "ConsoleDisplay.h"

class Timer
{
private:
	int playTime;
	bool work;
	ConsoleDisplay* display;
public:
	Timer();
	Timer(ConsoleDisplay* _display);
	void start();
	void stop();
	int getTime();
};

#endif
