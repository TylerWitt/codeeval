//Tyler Witt
//CodeEval
//SumDigits.cpp

#include <iostream>
#include <fstream>

using namespace std;

int addDigits(int num);

int main(int argc, char *argv[]) {
    ifstream infile;
    int temp;
    infile.open(argv[1]);
    while (infile >> temp) {
        cout << addDigits(temp) << endl;
    }
    infile.close();
    return 0;
}

int addDigits(int num){
  int sum = 0;
  while (num > 10){
    sum += num % 10;
    num /= 10;
  }
  sum += num;
  return sum;
}
