#include "Record.h"

#include <iostream>
using namespace std;

void Record::login(string username)
{
  string str;
  bool findUser = false;

  in.open("record.txt");
  
  while(!in.eof())
	{
		getline(in, str);
		if(str == username)
		{
			findUser = true;
		}
	}

  if(!findUser)
    newUser(username);

  in.close();
  
}

void Record::newUser(string username)
{
  out.open("record.txt", std::ios::app);
  out << endl << username  << "\n0 0 0 0 0";
  out.close();
}

void Record::recording(string _username, string _type, int _time)
{
  username = _username;
  type = _type;
  time = _time;

  int r1 = 0, r2 = 0, r3 = 0, c = 0, tr = 0;
  
	if ( rename( "record.txt", "oldrecord.txt" ) == 0 )
	{
		in.open("oldrecord.txt");
		out.open("record.txt");
	}

	string str;
	
	while(!in.eof())
	{
		getline(in, str);
		if(str == username)
		{
			out << str << endl;
			changeRecord();
		}
		else if(str != "")
			out << str << endl;
	}
	
	in.close();
	out.close();
	
	if( remove("oldrecord.txt") != 0 )
      return;
        
}
	
void Record::changeRecord()
{
	int r1 = 0, r2 = 0, r3 = 0, c = 0, tr = 0;
	
	in >> r1 >> r2 >> r3 >> c >> tr;
	
	if(type =="r1")
		if(r1 == 0 || r1 > time)
			r1 = time;
	if(type =="r2")
			if(r2 == 0 || r2 > time)
				r2 = time;
	if(type =="r3")
			if(r3 == 0 || r3 > time)
				r3 = time;
	if(type =="c")
			if(c == 0 || c > time)
				c = time;
	 if(type =="tr")
			if(tr == 0 || tr > time)
				tr = time;

	out << r1 << " " << r2 << " " << r3 << " " << c << " " << tr << endl;

}


int Record::getRecord(string username, string type)
{
  int r1, r2, r3, c, tr;
  int rec = 0;
  
  in.open("record.txt");

	string str;
	
	while(!in.eof())
	{
		getline(in, str);
		if(str == username)
    {
      in >> r1 >> r2 >> r3 >> c >> tr;
      if(type == "r1")
    			rec = r1;
    	if(type == "r2")
    			rec = r2;
    	if(type == "r3")
    			rec = r3;
    	if(type == "c")
    			rec = c;
    	 if(type == "tr")
    			rec = tr;
    }
	}
  
  in.close();

  return rec;
}