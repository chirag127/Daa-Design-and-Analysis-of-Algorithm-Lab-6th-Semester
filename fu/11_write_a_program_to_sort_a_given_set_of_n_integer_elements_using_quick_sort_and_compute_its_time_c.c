############################################################

(try to answer in C) 
Write a program to sort a given set of n integer elements using Quick Sort and compute its time complexity. The elements can be read from a file or generated using a random number generator. Demonstrate the divide and conquer method and analyze the time complexity for worst case, average case, and best case.

 Sure, here's a simple implementation of Quick Sort in C along with the time complexity analysis:

```
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  clock_t start, end;
  double time_taken;

  start = clock();
  quick_sort(arr, 0, n - 1);
  end = clock();

  time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\nTime taken by program is : %f\n", time_taken);
  return 0;
}
```

Time complexity analysis:

Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n^2)

In the best case scenario, the pivot is always the middle element, so the sub-arrays are roughly equal in size. This results in the fastest possible time complexity for Quick Sort.

In the average case scenario, the pivot is not always the middle element, but the sub-arrays are still roughly equal in size. This results in a time complexity of O(n log n).

In the worst case scenario, the pivot is always the smallest or largest element, so one sub-array is empty and the other is the entire array. This results in a time complexity of O(n^2).
