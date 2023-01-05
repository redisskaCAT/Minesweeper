#ifndef SETTINGS
#define SETTINGS

#include <string>

using namespace std;

class Settings
{
public:
	string type;
	bool login;
	string username;
  Settings()
	{
	}
	Settings(string t)
	{
		type = t;
		login = false;
	}
	Settings(string t, string n)
	{
		type = t;
		login = true;
		username = n;
	}
  Settings operator=(Settings s)
  {
    username = s.username;
    login = s.login;
    type = s.type;
    return *this;
  }
};

#endif
