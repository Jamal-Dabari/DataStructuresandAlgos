#include <iostream>
using namespace std;

const int n = 3;
int main() {
  int array[n] = {1, 2, 3};
  int s = 0;

  for (int i = 0; i < n; i++) {
    s = s + array[0];
    for (int j = 0; j < i; j++) {
      s = s + array[j];
    }
  }

  cout << s << endl;
}
