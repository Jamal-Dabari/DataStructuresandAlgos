// Jamal Dabari
#include <iostream> // needed to perform C++ I/O
#include <time.h>
using namespace std;

double Ex1(int m[], int n);
double Ex2(int m[], int n);
double Ex3(int m[], int n);
double Ex4(int m[], int n);
int Ex5(int m[], int m2[], int n);

const int MAX = 10000;

int main() {
  clock_t start, stop;
  double res;

  int A[MAX];
  int B[MAX];

  int sum = 0;
  for (int i = 0; i < MAX; i++) {
    A[i] = i + 1;

    for (int j = 0; j <= i; j++) {

      sum = sum + A[j];
    }
    B[i] = sum;
  }

  int m2[] = {10, 12, 14};

  //======== Ext1
  start = clock();
  res = Ex1(A, MAX);
  stop = clock();

  cout << "The sum of the elements in A is " << res << endl;
  cout << "Running time for Ex1 is " << static_cast<double>(stop - start)
       << endl; // in miliseconds

  cout << endl;

  start = clock();
  res = Ex2(A, MAX);
  stop = clock();

  cout << "The sum of the elements in A is " << res << endl;
  cout << "Running time for Ex2 is " << static_cast<double>(stop - start)
       << endl; // in miliseconds

  cout << endl;

  start = clock();
  res = Ex3(A, MAX);
  stop = clock();

  cout << "The sum of the elements in A is " << res << endl;
  cout << "Running time for Ex3 is " << static_cast<double>(stop - start)
       << endl; // in miliseconds

  cout << endl;

  start = clock();
  res = Ex4(A, MAX);
  stop = clock();

  cout << "The sum of the elements in A is " << res << endl;
  cout << "Running time for Ex4 is " << static_cast<double>(stop - start)
       << endl; // in miliseconds

  cout << endl;

  start = clock();
  res = Ex5(A, m2, MAX);
  stop = clock();

  cout << "The number of elements in B equal to the sum of prefix sums in A is "
       << res << endl;
  cout << "Running time for Ex1 is " << static_cast<double>(stop - start)
       << endl; // in miliseconds

  cout << endl;
}

double Ex1(int m[], int n) {
  double S = m[0];
  for (int i = 1; i <= n - 1; i++) {
    S = S + m[i];
  }

  return S;
}

double Ex2(int m[], int n) {
  double S = m[0];
  for (int i = 2; i <= n - 1; i += 2) {
    S = S + m[i];
  }

  return S;
}

double Ex3(int m[], int n) {
  double S = 0;
  for (int i = 0; i <= n - 1; i++) {
    S = S + m[0];
    for (int j = 1; j <= i; j++) {
      S = S + m[j];
    }
  }

  return S;
}

double Ex4(int m[], int n) {
  double S = m[0];
  double t = S;
  for (int i = 1; i <= n - 1; i++) {
    S = S + m[i];
    t = t + S;
  }

  return t;
}

int Ex5(int m[], int m2[], int n) {
  int c = 0;
  int s;
  for (int i = 0; i <= n - 1; i++) {
    s = 0;
    for (int j = 0; j < i; j++) {
      for (int k = 1; k < j; k++) {
        s = s + m[k];
      }
    }
    if (m2[i] == s) {
      c = c + 1;
    }
  }
  return c;
}
