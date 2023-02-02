write the codes in c following practical for my daa assignement 

Selection Sort: Implement the selection sort algorithm to sort an array in ascending or descending order.

```
#include <stdio.h>

void selectionSort(int arr[], int n, int ascending) {
  int i, j, minIndex, temp;
  for (i = 0; i < n-1; i++) {
    minIndex = i;
    for (j = i+1; j < n; j++) {
      if (ascending) {
        if (arr[j] < arr[minIndex]) {
          minIndex = j;
        }
      } else {
        if (arr[j] > arr[minIndex]) {
          minIndex = j;
        }
      }
    }
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr, n, 1);
  printf("Sorted array in ascending order: \n");
  for (int i=0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
```
