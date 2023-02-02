write the codes in c following practical for my daa assignement 

Quick Sort: Implement the quick sort algorithm to sort an array in ascending or descending order.

```
#include <stdio.h>
#include <stdlib.h>

// Function to swap values at two pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to divide the array into sub-arrays
int partition(int arr[], int low, int high, int order) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (order == 1) { // ascending order
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        } else { // descending order
            if (arr[j] >= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick sort function
void quickSort(int arr[], int low, int high, int order) {
    if (low < high) {
        int pi = partition(arr, low, high, order);

        quickSort(arr, low, pi - 1, order);
        quickSort(arr, pi + 1, high, order);
    }
}

// Main function to test the quick sort algorithm
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int order = 1; // 1 for ascending, 0 for descending

    quickSort(arr, 0, n - 1, order);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
```
/*


1. `#include <stdio.h>` and `#include <stdlib.h>` are preprocessor directives to include the standard input/output library and standard library in the program.

2. `void swap(int *a, int *b)` is a function to swap the values at two pointers. The function takes two pointer arguments `a` and `b`, and swaps their values using a temporary variable.

3. `int partition(int arr[], int low, int high, int order)` is the partition function that takes an array `arr`, two indices `low` and `high` and an integer `order` as arguments. The function divides the array into sub-arrays around a pivot element. The pivot is chosen as the last element of the array `arr[high]`. The function returns the index of the pivot element after dividing the array into sub-arrays.

4. `void quickSort(int arr[], int low, int high, int order)` is the quick sort function that takes an array `arr`, two indices `low` and `high` and an integer `order` as arguments. The function sorts the array `arr` in ascending or descending order based on the value of `order`. The function uses the partition function to divide the array into sub-arrays and recursively calls itself on the sub-arrays until the whole array is sorted.

5. `int main()` is the main function that tests the quick sort algorithm. It initializes an array `arr` with values `{10, 7, 8, 9, 1, 5}`, calculates its size `n`, and sets the sorting order as ascending (`order = 1`). The function then calls the quick sort function to sort the array and prints the sorted array.

6. The line `return 0;` at the end of the main function signifies the successful execution of the program.
*/
