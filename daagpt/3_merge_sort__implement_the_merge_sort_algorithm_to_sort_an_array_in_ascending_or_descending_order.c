write the codes in c following practical for my daa assignement 

Merge Sort: Implement the merge sort algorithm to sort an array in ascending or descending order.

```
#include<stdio.h>
#include<stdlib.h>

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
    if (order == 1) {
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

  int order;
  printf("Enter 1 for ascending order, 0 for descending order: ");
  scanf("%d", &order);

  mergeSort(arr, 0, arr_size - 1, order);

  printf("Sorted array is \n");
  for (int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);

  return 0;
}
```
/*
explain the following code 


```
#include<stdio.h>
#include<stdlib.h>

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
    if (order == 1) {
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

  int order;
  printf("Enter 1 for ascending order, 0 for descending order: ");
  scanf("%d", &order);

  mergeSort(arr, 0, arr_size - 1, order);

  printf("Sorted array is \n");
  for (int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);

  return 0;
}
```

This code is an implementation of the merge sort algorithm in C. It sorts an array of integers in either ascending or descending order. The `mergeSort` function takes four arguments: the array, the left index, the right index, and the order (ascending or descending). The `merge` function takes five arguments: the array, the left index, the middle index, the right index, and the order. The `merge` function splits the array into two halves, sorts them, and then merges them back together in the desired order. The `main` function prompts the user to enter the desired order and then calls the `mergeSort` function to sort the array. Finally, the sorted array is printed to the console.
*/
