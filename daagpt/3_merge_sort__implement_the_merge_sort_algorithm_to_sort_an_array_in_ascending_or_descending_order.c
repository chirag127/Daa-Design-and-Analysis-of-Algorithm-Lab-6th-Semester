write the codes in c following practical for my daa assignement 

Merge Sort: Implement the merge sort algorithm to sort an array in ascending or descending order.
 Here's a sample implementation of Merge Sort in C:

```
#include <stdio.h>

void merge(int arr[], int l, int m, int r, int order) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (order == 0) {
      if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
    } else {
      if (L[i] >= R[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r, int order) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, order);
    mergeSort(arr, m + 1, r, order);
    merge(arr, l, m, r, order);
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  int order = 0; // 0 for ascending, 1 for descending

  printf("Given array is \n");
  for (int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);

  mergeSort(arr, 0, arr_size - 1, order);

  printf("\nSorted array is \n");
  for (int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);
  return 0;
}
```
