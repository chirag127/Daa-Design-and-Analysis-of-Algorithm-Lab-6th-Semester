write the codes in c following practical for my daa assignement 

Insertion Sort: Implement the insertion sort algorithm to sort an array in ascending or descending order.
 
```
#include <stdio.h>

void insertionSort(int arr[], int n, int ascending) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    if (ascending == 1) {
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    } else {
      while (j >= 0 && arr[j] < key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int ascending = 1; // 1 for ascending, 0 for descending
  insertionSort(arr, n, ascending);
  printf("Sorted array in %s order: \n",
         ascending ? "ascending" : "descending");
  printArray(arr, n);
  return 0;
}
```
