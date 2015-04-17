//Tyler Witt
//CodeEval
//FizzBuzz.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void fizzbuzz(string line);

int main(int argc, char *argv[]) {
  ifstream stream(argv[1]);
  string line;
  while (getline(stream, line)) {
    fizzbuzz(line);
    cout << endl;
  }
return 0;
}

void fizzbuzz(string line){
  int limit;
  int values[2];
  bool flag;
  for (int i = 0; i < 2; i++){
    values[i] = atoi(line.substr(0, line.find(' ')).c_str());
    line = line.substr(line.find(' ') + 1);
  }
  limit = atoi(line.c_str());

  for (int i = 1; i <= limit; i++){
    flag = false;
    if (i % values[0] == 0){
      cout << "F";
      flag = true;
    }
    if (i % values[1] == 0){
      cout << "B";
      flag = true;
    }
    if (flag == false)
      cout << i;
    if (i < limit)
      cout << ' ';
  }
}
