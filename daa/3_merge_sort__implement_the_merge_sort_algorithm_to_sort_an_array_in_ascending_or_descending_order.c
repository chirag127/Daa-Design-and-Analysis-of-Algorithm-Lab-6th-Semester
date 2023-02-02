write the codes in c following practical for my daa assignement 

Merge Sort: Implement the merge sort algorithm to sort an array in ascending or descending order.

```
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
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
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
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

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("Given array is \n");
  for (int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);

  mergeSort(arr, 0, arr_size - 1);

  printf("\nSorted array is \n");
  for (int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);
  return 0;
}
```
/*
 

1. `#include <stdio.h>` - This line includes the standard I/O library in the code.

2. `void merge(int arr[], int l, int m, int r)` - This function takes an array of integers `arr`, and the indices `l`, `m`, and `r` as input. It performs the merge operation of the merge sort algorithm.

3. `int i, j, k;` - These are variables used in the function to traverse through the arrays.

4. `int n1 = m - l + 1; int n2 = r - m;` - `n1` is the size of the left sub-array and `n2` is the size of the right sub-array.

5. `int L[n1], R[n2];` - These are the arrays that store the left and right sub-arrays, respectively.

6. `for (i = 0; i < n1; i++) L[i] = arr[l + i];` - This loop copies the elements from the original array `arr` to the left sub-array `L`.

7. `for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];` - This loop copies the elements from the original array `arr` to the right sub-array `R`.

8. `i = 0; j = 0; k = l;` - These lines initialize the variables `i`, `j`, and `k` to 0, 0, and `l`, respectively.

9. `while (i < n1 && j < n2) {` - This loop continues until either `i` becomes greater than or equal to `n1` or `j` becomes greater than or equal to `n2`.

10. `if (L[i] <= R[j]) { arr[k] = L[i]; i++; } else { arr[k] = R[j]; j++; } k++;` - This line compares the elements of the left and right sub-arrays and places the smaller element in the original array `arr`.

11. `while (i < n1) { arr[k] = L[i]; i++; k++; }` - This loop copies the remaining elements of the left sub-array to the original array `arr` if there are any.

12. `while (j < n2) { arr[k] = R[j]; j++; k++; }` - This loop copies the remaining elements of the right sub-array to the original array `arr` if there are any.

13. `void mergeSort(int arr[], int l, int r)` - This function takes an array of integers `arr`, and the indices `l` and `r` as input. It performs the merge sort algorithm.

14. `if (l < r) {` - This line checks if `l` is less than `r`. If it is, the function continues to sort the array, otherwise it returns.

15. `int m = l + (r - l) / 2;` - This line calculates the mid-point of the array.

16. `mergeSort(arr, l, m); mergeSort(arr, m + 1, r);` - These lines recursively call the `mergeSort` function on the left and right sub-arrays.

17. `merge(arr, l, m, r);` - This line calls the `merge` function to merge the two sorted sub-arrays.

18. `int main()` - This is the main function of the program.

19. `int arr[] = {12, 11, 13, 5, 6, 7}; int arr_size = sizeof(arr) / sizeof(arr[0]);` - This line initializes an array of integers `arr` and calculates its size.

20. `printf("Given array is \n");` - This line prints the message "Given array is".

21. `for (int i = 0; i < arr_size; i++) printf("%d ", arr[i]);` - This loop prints the elements of the original array `arr`.

22. `mergeSort(arr, 0, arr_size - 1);` - This line calls the `mergeSort` function to sort the original array `arr`.

23. `printf("\nSorted array is \n");` - This line prints the message "Sorted array is".

24. `for (int i = 0; i < arr_size; i++) printf("%d ", arr[i]);` - This loop prints the elements of the sorted array `arr`.

25. `return 0;` - This line returns 0 to indicate that the program has executed successfully.
*/
