//Tyler Witt
//CodeEval
//Bubble.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int getLimit(string& line);

vector<int> setvector(string line);

void bubble(vector<int>& myVec, int limit);

int main(int argc, char *argv[]) {
  ifstream stream(argv[1]);
  string line;
  vector<int> myVec;
  int limit;
  while (getline(stream, line)) {
    limit = getLimit(line);
    myVec = setvector(line);
    if (myVec.size() > 1)
      bubble(myVec, limit);
    for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++){
      cout << *it;
      if (it != myVec.end() - 1)
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}

int getLimit(string& line){
  int limit = 0;
  if (line.find('|') >= 0){
    limit = atoi(line.substr(line.find('|') + 2, line.length()).c_str());
    line = line.substr(0, line.find('|') - 1);
  }
  return limit;
}

vector<int> setvector(string line){
  vector<int> myVec;
  while (!line.empty()){
    myVec.push_back(atoi(line.substr(0, line.find(' ')).c_str()));
    if (line.find(' ') < line.length())
      line = line.substr(line.find(' ') + 1);
    else
      line = "";
  }
  return myVec;
}

void bubble(vector<int>& myVec, int limit){
  int temp;
  for (int i = 0; i < limit; i++){
    for (int j = 0; j < myVec.size() - i - 1; j++){
      if (myVec[j] > myVec[j+1]){
        temp = myVec[j];
        myVec[j] = myVec[j+1];
        myVec[j+1] = temp;
      }
    }
  }
}
