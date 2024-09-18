#include <iostream>
using namespace std;

void Insert(int data[], int item, int &length);
bool isEmpty(int[], int size);
bool isPresent(int data[], int item, int length);
void Delete(int data[], int item, int &length);
void printList(int data[], int length);

int main() {
  int length = 0;
  int data[4];
  int item;

  cout << "1. Insert 15, 39, -90, 64 into a list" << endl;
  Insert(data, 15, length);
  Insert(data, 39, length);
  Insert(data, -90, length);
  Insert(data, 64, length);
  printList(data, length);

  cout << endl;
  cout << "2. The current length of the list is " << length << endl;
  cout << endl;

  cout << "3. Check whether 39 is in the list" << endl;
  isPresent(data, 39, length);

  cout << "Delete 39" << endl;
  Delete(data, 39, length);
  printList(data, length);

  cout << "delete -90, 15, 64 sequentially" << endl;
  Delete(data, -90, length);
  Delete(data, 15, length);
  Delete(data, 64, length);

  isEmpty(data, length);
}

void Insert(int data[], int item, int &length) {
  data[length] = item;
  length++;
}

bool isEmpty(int[], int size) {
  for (int i = 0; i <= size; i++) {
    if (size <= 0) {
      cout << "The list is empty" << endl;
      return true;
    }
  }
  cout << "not empty" << endl;
  return false;
}

bool isPresent(int data[], int item, int length) {
  for (int i = 0; i < length; i++) {
    if (data[i] == item) {
      cout << "The number is in the list" << endl;
      return true;
    }
  }
  return false;
}

void Delete(int data[], int item, int &length) {
  int index = 0;
  while (index < length && item != data[index]) {
    index++;
  }

  if (index < length) {
    data[index] = data[length - 1];
    length--;
  }
}

void printList(int data[], int length) {
  cout << "now, ";

  for (int i = 0; i < length; i++) {
    cout << data[i] << ", ";
  }
  cout << "are in the list" << endl;
}
