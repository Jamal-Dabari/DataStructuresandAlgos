// Hands-on Exericse 3 (Recursions 2)
// Jamal Dabari
#include <cstdlib>  //use absolute function
#include <iostream> // needed to perform C++ I/O
#include <string>
#include <time.h> //use clock_t start, stop;

using namespace std;

long double rabbit(int n);
long double IterativeRabbit(int n);
void writeBackward(string s);
void IterativewriteBackward(string s);

int binarySearch(const int anArray[], int first, int last, int target);
int IterativeBinarySearch(int array[], int size, int target);
void cheers(int n);
void verticalDigits(int num2);

const int SIZE = 40, SIZE2 = 10000;

int main() {
  cout << "#4 - a: \n";
  int res, array[SIZE] = {}, array2[SIZE2] = {};

  for (int i = 0; i < SIZE; i++) {
    array[i] = 2 * i + 1;
  }

  for (int i = 0; i < SIZE2; i++) {
    array2[i] = 2 * i + 1;
  }

  string s = "think";

  clock_t start, stop;

  // Rabbit functions
  start = clock();
  res = rabbit(SIZE);
  stop = clock();
  cout << "The return value of the rabbit function is " << res << endl;
  cout << "Running time for the function is "
       << static_cast<double>(stop - start) << endl; // in miliseconds
  cout << endl;

  start = clock();
  res = IterativeRabbit(SIZE);
  stop = clock();
  cout << "The return value of the IterativeRabbit function is " << res << endl;
  cout << "Running time for the function is  "
       << static_cast<double>(stop - start) << endl; // in miliseconds
  cout << endl;
  cout << "------------------------------------------------------------------"
          "\n\n";

  // writeBackward functions

  cout << "The return value of the writeBackward function is ";
  start = clock();
  writeBackward(s);
  stop = clock();
  cout << "\n Running time for the function is "
       << static_cast<double>(stop - start) << endl; // in miliseconds
  cout << endl;

  cout << "The return value of the IterativewriteBackward function is ";
  start = clock();
  IterativewriteBackward(s);
  stop = clock();
  cout << "\n Running time for the function is "
       << static_cast<double>(stop - start) << endl; // in miliseconds
  cout << endl;

  cout << "------------------------------------------------------------------"
          "\n\n";

  // binary search functions
  start = clock();
  res = binarySearch(array2, 0, SIZE2 - 1, 3261);
  stop = clock();
  cout << "The return value of the binarySearch function is " << res << endl;
  cout << "Running time for Ex1 is " << static_cast<double>(stop - start)
       << endl; // in miliseconds
  cout << endl;

  start = clock();
  res = IterativeBinarySearch(array2, SIZE2, 3261);
  stop = clock();
  cout << "The return value of the IterativeBinarySearch function is " << res
       << endl;
  cout << "Running time for Ex1 is " << static_cast<double>(stop - start)
       << endl; // in miliseconds
  cout << endl;
  cout << "------------------------------------------------------------------"
          "\n\n";

  //# 4- b
  cout << "# 4 - b: \n";
  cout << "cheers(3) displays: \n";
  cheers(3);
  cout << "\ncheers(5) displays: \n";
  cheers(5);

  cout << endl;

  int num2 = -1234;
  cout << "Let's print " << num2 << " stacked vertically: " << endl;
  verticalDigits(num2);

  system("pause");
  return 0;
}

long double rabbit(int n) {
  if (n <= 2) {
    return 1;
  } else {
    return rabbit(n - 1) + rabbit(n - 2);
  }
}

long double IterativeRabbit(int n) {
  long double beginning, fn1, fn2 = 1;

  for (int i = 0; i <= n; i++) {
    beginning = fn1;
    fn1 = fn2 + fn1;
    fn2 = beginning;
  }

  return fn2;
}

void writeBackward(string s) {
  int length = s.size();
  if (length > 0) {
    cout << s.substr(length - 1, 1);
    writeBackward(s.substr(0, length - 1));
  }
}

void IterativewriteBackward(string s) {
  int length = s.size();

  while (length > 0) {
    cout << s.substr(length - 1, 1);
    length--;
  }
}

int binarySearch(const int anArray[], int first, int last, int target) {
  if (first > last) {
    return -1;
  }

  int mid = (first + last) / 2;

  if (target == anArray[mid]) {
    return mid;
  } else if (target < anArray[mid]) {
    return binarySearch(anArray, first, mid - 1, target);
  } else {
    return binarySearch(anArray, mid + 1, last, target);
  }
}
int IterativeBinarySearch(int array[], int size, int target) {
  int first = 0;
  int last = size - 1;

  while (first <= last) {
    int mid = (first + last) / 2;
    if (array[mid] == target) {
      return mid;
    } else if (target > array[mid]) {
      first = mid + 1;
    } else {
      last = mid - 1;
    }
  }
  return -1;
}

void cheers(int n) {
  if (n > 1) {
    cheers(n - 1);
    cout << "hip" << endl;
  } else {
    cout << "hurrah" << endl;
  }
}

void verticalDigits(int num2) {
  if (num2 < 0) {
    cout << '-' << endl;
    num2 = -num2;
  }

  if (num2 > 10)
    verticalDigits(num2 / 10);
  cout << num2 % 10 << endl;
}
