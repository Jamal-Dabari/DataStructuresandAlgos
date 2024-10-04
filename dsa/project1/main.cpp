#include <ctime>
#include <iostream>
using namespace std;

void selectionSort(int[], int);
void bubbleSort(int[], int);
void insertionSort(int[], int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void radixSort(int[], int);
void quickSort(int[], int, int);

const int size = 8;

int main() {
  clock_t start, stop;

  int arr[size];

  for (int i = size - 1; i >= 0; i--) {
    arr[i] = i;
  }

  start = clock();
  selectionSort(arr, size);
  stop = clock();

  cout << "Running time for Selection Sort with array size of " << size
       << " is " << static_cast<double>(stop - start) << endl;

  start = clock();
  bubbleSort(arr, size);
  stop = clock();

  cout << "Running time for Bubble Sort with array size of " << size << " is "
       << static_cast<double>(stop - start) << endl;

  start = clock();
  insertionSort(arr, size);
  stop = clock();

  cout << "Running time for Insertion Sort with array size of " << size
       << " is " << static_cast<double>(stop - start) << endl;

  start = clock();
  mergeSort(arr, 0, size - 1);
  stop = clock();

  cout << "Running time for Merge Sort with array size of " << size << " is "
       << static_cast<double>(stop - start) << endl;

  start = clock();
  quickSort(arr, 0, size - 1);
  stop = clock();

  cout << "Running time for Quick Sort with array size of " << size << " is "
       << static_cast<double>(stop - start) << endl;

  start = clock();
  radixSort(arr, size);
  stop = clock();

  cout << "Running time for Radix Sort with array size of " << size << " is "
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

int sortFirstMiddleLast(int arr[], int low, int high) {
  int mid = low + (high - low) / 2;
  int temp;
  int temp1;
  int temp2;
  int temp3;

  // Sort the first, middle, and last elements
  if (arr[mid] < arr[low]) {
    temp = arr[low];
    arr[low] = arr[mid];
    arr[mid] = temp;
  }

  if (arr[high] < arr[low]) {
    temp1 = arr[low];
    arr[low] = arr[high];
    arr[high] = temp1;
  }

  if (arr[high] < arr[mid]) {
    temp2 = arr[mid];
    arr[mid] = arr[high];
    arr[high] = temp2;
  }

  // Use the median as the pivot
  temp3 = arr[mid];
  arr[mid] = arr[high - 1];
  arr[high - 1] = temp;
  return arr[high - 1];
}

void merge(int arr[], int first, int mid, int last) {
  int tempArr[size];
  int first1 = first;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = last;

  int index = first1;
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

  for (index = first; index <= last; index++) {
    arr[index] = tempArr[index];
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

int partition(int arr[], int low, int high) {
  int pivot = sortFirstMiddleLast(arr, low, high);
  int i = low;
  int j = high - 2;
  int temp;
  int temp2;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp2 = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp2;
  return (i + 1);
}

void quickSort(int arr[], int first, int last) {

  if (first < last) {
    int pi = partition(arr, first, last);
    quickSort(arr, first, pi - 1);
    quickSort(arr, pi + 1, last);
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
  int maxVal = getMax(arr, size);
  for (int exp = 1; maxVal / exp > 0; exp *= 10) {
    Sort(arr, size, exp);
  }
}
