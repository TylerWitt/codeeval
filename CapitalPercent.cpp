//Tyler Witt
//CodeEval
//CapitalPercent.cpp

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void analyze(string line);

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        analyze(line);
    }
    return 0;
}

void analyze(string line){
  int upper = 0;
  int lower = 0;
  for (int i = 0; i < line.length(); i++){
    if(isupper(line[i]))
      upper++;
    if(islower(line[i]))
      lower++;
  }
  cout << "lowercase: " << fixed << setprecision(2) << (double)lower/(upper+lower) * 100 << " "
       << "uppercase: " << fixed << setprecision(2) << (double)upper/(upper+lower) * 100 << endl;
}
