write the codes in c following practical for my daa assignement 

Quick Sort Time Complexity Analysis: Implement the quick sort algorithm and analyze its time complexity for varying values of n (number of elements in the array). Plot a graph to show the relationship between the time taken and n.
 
```
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int arr[], int low, int high) {
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

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter elements: ");
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  clock_t t;
  t = clock();
  quickSort(arr, 0, n - 1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\nTime taken: %f", time_taken);

  return 0;
}
```

To analyze the time complexity, you can run the program multiple times with different values of n and record the time taken for each run. Then plot a graph of the time taken vs n to see the relationship. The time complexity of quick sort is O(n log n) on average, so you should see a graph that roughly follows this pattern.
/*
explain the following code 

 
```
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int arr[], int low, int high) {
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

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter elements: ");
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  clock_t t;
  t = clock();
  quickSort(arr, 0, n - 1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\nTime taken: %f", time_taken);

  return 0;
}
```

To analyze the time complexity, you can run the program multiple times with different values of n and record the time taken for each run. Then plot a graph of the time taken vs n to see the relationship. The time complexity of quick sort is O(n log n) on average, so you should see a graph that roughly follows this pattern.

The code is an implementation of the Quick Sort algorithm in C, with time complexity analysis. The program prompts the user to enter the number of elements in an array and the elements themselves. Then it sorts the array using the Quick Sort algorithm, records the time taken for the sorting process and displays the sorted array and the time taken. The time taken is calculated using the `clock()` function from the `time.h` library. The `swap()` function is used to swap two elements in the array. The `partition()` function is used to partition the array around a pivot element. The `quickSort()` function is the main sorting function, which uses recursion to sort the array. The time complexity of Quick Sort is O(n log n) on average.
*/
