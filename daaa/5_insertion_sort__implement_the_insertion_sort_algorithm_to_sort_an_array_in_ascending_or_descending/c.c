write the c code for practical for my daa assignement 

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

  printf("Given array is \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  insertionSort(arr, n, 1);

  printf("\nSorted array in ascending order is \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}
```
