
#include <cassert> //to use assert function
#include <iostream>
using namespace std;

unsigned int Iterative_factorial(int n);
unsigned int Recursive_factorial(int n);

int main() {
  // Part 1: Iterative factorial function
  cout << "Iterative Factorial Function\n";
  cout << "The value of 5! should be " << 5 * 4 * 3 * 2 * 1 << endl;
  assert(Iterative_factorial(5) == 120);
  cout << "The value of 5! is " << Iterative_factorial(5) << endl;

  cout << "The value of 0! should be 1 " << endl;
  assert(Iterative_factorial(0) == 1);
  cout << "The value of 0! is " << Iterative_factorial(0) << endl << endl;

  // Part 2: Recursive factorial function
  cout << "Recursive Factorial Function\n";
  cout << "The value of 5! should be " << 5 * 4 * 3 * 2 * 1 << endl;
  assert(Recursive_factorial(5) == 120);
  cout << "The value of 5! is " << Recursive_factorial(5) << endl;

  cout << "The value of 0! should be 1 " << endl;
  assert(Recursive_factorial(0) == 1);
  cout << "The value of 0! is " << Recursive_factorial(0) << endl;

  return 0;
}

unsigned int Iterative_factorial(int n) {
  int num = 1;
  for (int i = 0; i < n; i++) {

    num = num * (i + 1);
  }

  return num;
}

unsigned int Recursive_factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * Recursive_factorial(n - 1);
}
