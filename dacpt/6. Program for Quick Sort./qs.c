#include <stdio.h>

// Function to partition the array using pivot element
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than or equal to pivot
    if (arr[j] <= pivot)
    {
      i++;
      // Swap arr[i] and arr[j]
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  // Swap arr[i + 1] and arr[high]
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    // pi is partitioning index, arr[p] is now at right place
    int pi = partition(arr, low, high);

    // Separately sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Function to print the array
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
/* Here is the explanation for the code above:
1. The partition function takes the last element as the pivot element.
2. Then it places the pivot element in its correct position in the array.
3. It places all the elements smaller than the pivot to the left of the pivot and all the elements greater than the pivot to the right of the pivot.
4. The quickSort function takes the last element as the pivot element.
5. Then it places the pivot element in its correct position in the array.
6. It places all the elements smaller than the pivot to the left of the pivot and all the elements greater than the pivot to the right of the pivot.
7. Then it calls quickSort function recursively for the elements before the pivot and after the pivot. */
