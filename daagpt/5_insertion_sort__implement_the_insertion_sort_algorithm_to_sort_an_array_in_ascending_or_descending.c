write the codes in c following practical for my daa assignement 

Insertion Sort: Implement the insertion sort algorithm to sort an array in ascending or descending order.

```
#include <stdio.h>

void insertionSort(int arr[], int n, int ascending) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && (ascending ? arr[j] > key : arr[j] < key)) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int ascending = 1; // 1 for ascending, 0 for descending
  insertionSort(arr, n, ascending);
  printf("Sorted array: \n");
  for (int i=0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}
```
/*
explain the following code 


```
#include <stdio.h>

void insertionSort(int arr[], int n, int ascending) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && (ascending ? arr[j] > key : arr[j] < key)) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int ascending = 1; // 1 for ascending, 0 for descending
  insertionSort(arr, n, ascending);
  printf("Sorted array: \n");
  for (int i=0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}
```
 The code is an implementation of the insertion sort algorithm in C. The `insertionSort` function takes an array `arr`, its size `n`, and a boolean `ascending` as input parameters. The function sorts the array in ascending order if `ascending` is `1` and in descending order if `ascending` is `0`. The `main` function initializes an array of integers, sets `ascending` to `1`, and calls the `insertionSort` function to sort the array. Finally, the sorted array is printed.
*/
