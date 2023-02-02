write the c code for practical for my daa assignement 

Selection Sort: Implement the selection sort algorithm to sort an array in ascending or descending order.
 
```
#include <stdio.h>

void selectionSort(int arr[], int n, int ascending) {
  int i, j, min_idx;
  for (i = 0; i < n-1; i++) {
    min_idx = i;
    for (j = i+1; j < n; j++) {
      if (ascending) {
        if (arr[j] < arr[min_idx])
          min_idx = j;
      } else {
        if (arr[j] > arr[min_idx])
          min_idx = j;
      }
    }
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Original Array: \n");
  for (int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  selectionSort(arr, n, 1); // 1 for ascending, 0 for descending
  printf("Sorted Array in ascending order: \n");
  for (int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
```
