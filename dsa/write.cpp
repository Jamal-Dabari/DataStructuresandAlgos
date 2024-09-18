#include <iostream>
using namespace std;

void writeLine(char ch, int n);
void writeBlock(char ch, int m, int n);

int main() {

  writeLine('*', 5);
  cout << endl << endl;

  writeBlock('*', 3, 2);
  cout << endl;

  return 0;
}

void writeLine(char ch, int n) {
  if (n == 0)
    ;
  else {
    cout << ch;
    writeLine(ch, n - 1);
  }
}

void writeBlock(char ch, int m, int n) {
  if (n == 0)
    ;
  else {
    cout << endl;

    cout << ch;
    writeLine(ch, m - 1);
    writeBlock(ch, m, n - 1);
  }
}
