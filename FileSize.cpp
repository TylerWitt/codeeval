//Tyler Witt
//CodeEval
//FileSize.cpp

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream infile;
  infile.open(argv[1]);
  infile.seekg(0, ios::end);
  cout << infile.tellg() << endl;
  return 0;
}
