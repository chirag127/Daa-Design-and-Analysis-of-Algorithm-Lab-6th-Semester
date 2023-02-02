write the codes in c following practical for my daa assignement 

Quick Sort Time Complexity Analysis: Implement the quick sort algorithm and analyze its time complexity for varying values of n (number of elements in the array). Plot a graph to show the relationship between the time taken and n.
 Here's an example of quick sort in C:

```
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}
```

For time complexity analysis, you can use `clock()` function from `time.h` library to measure the time taken for sorting the array. You can then plot the results using any plotting library. The time complexity of quick sort is O(nlog(n)) on average, but it can be O(n^2) in the worst case when the pivot is always the largest or smallest element.
