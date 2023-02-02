write the codes in c following practical for my daa assignement 

Insertion Sort: Implement the insertion sort algorithm to sort an array in ascending or descending order.

```
#include <stdio.h>
#include <stdbool.h>

void insertionSort(int arr[], int n, bool ascending) {
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
  insertionSort(arr, n, true);
  printf("Sorted array in ascending order: \n");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
  insertionSort(arr, n, false);
  printf("Sorted array in descending order: \n");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  return 0;
}
```
