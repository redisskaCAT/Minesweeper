#ifndef RECORD
#define RECORD

#include <string>
#include <fstream>

using namespace std;

class Record
{
private:
	string username;
	string type;
	int time;
	ifstream in;
	ofstream out;
	void changeRecord();
  void newUser(string username);
public:
	Record(){}
  void login(string username);
	void recording(string _username, string _type, int _time);
  int getRecord(string username, string type);
};

#endif
