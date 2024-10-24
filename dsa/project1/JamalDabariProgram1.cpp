#include <ctime>
#include <iostream>
using namespace std;

void selectionSort(int[], int);
void bubbleSort(int[], int);
void insertionSort(int[], int, int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void radixSort(int[], int);
void quickSort(int[], int, int);

const int SIZE = 8;

int main() {
  clock_t start, stop;

  int arr[SIZE];

  for (int i = 0; i < SIZE; i++) {
    arr[i] = SIZE - 1 - i;
  }

  start = clock();
  selectionSort(arr, SIZE);
  stop = clock();

  cout << "Running time for Selection Sort with array size of " << SIZE
       << " is " << static_cast<double>(stop - start) << endl;

  for (int i = SIZE - 1; i >= 0; i--) {
    arr[i] = i;
  }

  start = clock();
  bubbleSort(arr, SIZE);
  stop = clock();

  cout << "Running time for Bubble Sort with array size of " << SIZE << " is "
       << static_cast<double>(stop - start) << endl;

  for (int i = SIZE - 1; i >= 0; i--) {
    arr[i] = i;
  }

  start = clock();
  insertionSort(arr, 0, SIZE - 1);
  stop = clock();

  cout << "Running time for Insertion Sort with array size of " << SIZE
       << " is " << static_cast<double>(stop - start) << endl;

  for (int i = SIZE - 1; i >= 0; i--) {
    arr[i] = i;
  }

  start = clock();
  mergeSort(arr, 0, SIZE - 1);
  stop = clock();

  cout << "Running time for Merge Sort with array size of " << SIZE << " is "
       << static_cast<double>(stop - start) << endl;

  for (int i = SIZE - 1; i >= 0; i--) {
    arr[i] = i;
  }

  start = clock();
  quickSort(arr, 0, SIZE - 1);
  stop = clock();

  cout << "Running time for Quick Sort with array size of " << SIZE << " is "
       << static_cast<double>(stop - start) << endl;

  for (int i = SIZE - 1; i >= 0; i--) {
    arr[i] = i;
  }

  start = clock();
  radixSort(arr, SIZE);
  stop = clock();

  cout << "Running time for Radix Sort with array size of " << SIZE << " is "
       << static_cast<double>(stop - start) << endl;
}

void selectionSort(int arr[], int size) {
  int largestIndex;
  int temp;
  for (int i = 0; i < size - 1; i++) {
    largestIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[largestIndex]) {
        largestIndex = j;
      }
    }
    if (largestIndex != i) {
      temp = arr[largestIndex];
      arr[largestIndex] = arr[i];
      arr[i] = temp;
    }
  }
}

void bubbleSort(int arr[], int size) {
  bool isSorted = false;
  int passes = 1;
  int temp;
  while (!isSorted && (passes < size)) {
    isSorted = true;
    for (int i = 0; i < (size - passes); i++) {
      int nextIndex = i + 1;
      if (arr[i] > arr[nextIndex]) {
        temp = arr[i];
        arr[i] = arr[nextIndex];
        arr[nextIndex] = temp;
        isSorted = false;
      }
    }
    passes++;
  }
}

void insertionSort(int arr[], int first, int last) {
  for (int i = first; i < last; i++) {
    int nextItem = arr[i];
    int location = i - 1;
    while (location >= first && arr[location] > nextItem) {
      arr[location + 1] = arr[location];
      location--;
    }
    arr[location + 1] = nextItem;
  }
}

void sortFirstMiddleLast(int arr[], int first, int mid, int last) {
  int temp;
  if (arr[first] > arr[mid]) {
    temp = arr[first];
    arr[first] = arr[mid];
    arr[mid] = temp;
  }

  if (arr[mid] > arr[last]) {
    temp = arr[mid];
    arr[mid] = arr[last];
    arr[last] = temp;
  }

  if (arr[first] > arr[mid]) {
    temp = arr[first];
    arr[first] = arr[mid];
    arr[mid] = temp;
  }
}

void merge(int arr[], int first, int mid, int last) {
  int tempArr[last - first + 1];
  int first1 = first;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = last;

  int index = 0;
  while ((first1 <= last1) && (first2 <= last2)) {
    if (arr[first1] <= arr[first2]) {
      tempArr[index] = arr[first1];
      first1++;
    } else {
      tempArr[index] = arr[first2];
      first2++;
    }
    index++;
  }

  while (first1 <= last1) {
    tempArr[index] = arr[first1];
    first1++;
    index++;
  }

  while (first2 <= last2) {
    tempArr[index] = arr[first2];
    first2++;
    index++;
  }

  for (index = 0; index < last - first + 1; index++) {
    arr[first + index] = tempArr[index];
  }
}

void mergeSort(int arr[], int first, int last) {
  if (first < last) {
    int mid = first + (last - first) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    merge(arr, first, mid, last);
  }
}

int partition(int arr[], int first, int last) {
  int temp;
  int pivotIndex;
  int mid = first + (last - first) / 2;
  sortFirstMiddleLast(arr, first, mid, last);
  temp = arr[mid];
  arr[mid] = arr[last - 1];
  pivotIndex = last - 1;
  int pivot = arr[pivotIndex];

  int indexFromLeft = first + 1;
  int indexFromRight = last - 2;

  bool done = false;

  while (!done) {
    while (arr[indexFromLeft] < pivot) {
      indexFromLeft++;
    }

    while (arr[indexFromRight] > pivot) {
      indexFromRight--;
    }

    if (indexFromLeft < indexFromRight) {
      temp = arr[indexFromLeft];
      arr[indexFromLeft] = arr[indexFromRight];
      arr[indexFromRight] = temp;

      indexFromLeft += 1;
      indexFromRight -= 1;
    } else {
      done = true;
    }
  }
  temp = arr[pivotIndex];
  arr[pivotIndex] = arr[indexFromLeft];
  arr[indexFromLeft] = temp;
  pivotIndex = indexFromLeft;
  return pivotIndex;
}

void quickSort(int arr[], int first, int last) {
  if ((last - first + 1) < 10) {
    insertionSort(arr, first, last);
  } else {
    int pivotIndex = partition(arr, first, last);

    quickSort(arr, first, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, last);
  }
}

int getMax(int arr[], int size) {
  int maxVal = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }
  return maxVal;
}

void Sort(int arr[], int size, int exp) {
  int output[size];
  int count[10] = {0};

  for (int i = 0; i < size; i++) {
    int digit = (arr[i] / exp) % 10;
    count[digit]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
}

void radixSort(int arr[], int size) {
  int max = getMax(arr, size);
  for (int i = 1; max / i > 0; max *= 10) {
    Sort(arr, size, i);
  }
}
