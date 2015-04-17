//Tyler Witt
//CodeEval
//DataRecovery.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

string translate(string line);

int main(int argc, char *argv[]) {
  ifstream stream("input.txt");
  string line;
  while (getline(stream, line)) {
    cout << translate(line) << endl;
  }
  cin.get();
  return 0;
}

string translate(string line){
  int ploc = 0;
  int wloc = 0;
  string positions = line.substr(line.find(';') + 1);
  string result = "";
  map<int, string> dict;
  int missing = 0;

  line = line.substr(0, line.find(';'));

  while (!positions.empty()){
    ploc = positions.find(' ');
    wloc = line.find(' ');
    if (ploc > positions.length())
      ploc = positions.length();
    if (wloc > line.length())
      wloc = line.length();
    dict[atoi(positions.substr(0, ploc).c_str())] = line.substr(0, wloc);
    if (ploc < positions.length())
      positions = positions.substr(ploc + 1);
    else
      positions = "";
    line = line.substr(wloc + 1);
  }

  for (int i = 1; i <= dict.size(); i++){
	  if (dict.find(i) == dict.end())
		  missing = i;
	  else if (missing == 0)
		  missing = dict.size() + 1;
  }

  dict[missing] = line;

  for (int i = 1; i <= dict.size(); i++)
    result = result + dict[i] + " ";

  dict.erase(dict.begin(), dict.end());

  return result;
}
