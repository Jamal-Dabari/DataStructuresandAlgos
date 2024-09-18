#include <iostream>
using namespace std;

int search(int first, int last, int n);
int mystery(int n);

int main() {
  int result;
  cout << "mystery(30) produces the following output: \n";
  result = mystery(30);
  cout << "mystery(30) = " << result << " : should be 5\n";
}

int search(int first, int last, int n) {
  int returnvalue = 0;
  cout << "Enter: first = " << first << ", last = " << last << endl;
  int mid = (first + last) / 2;

  if (((mid * mid) <= n) && (n < ((mid + 1) * (mid + 1))))
    returnvalue = mid;
  else if (mid * mid > n)
    returnvalue = search(first, mid - 1, n);
  else
    returnvalue = search(mid + 1, last, n);
  cout << "Leave: first = " << first << ", last = " << last << endl;
  return returnvalue;
}

int mystery(int n) { return search(1, n, n); }
