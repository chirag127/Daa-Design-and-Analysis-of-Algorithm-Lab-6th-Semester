write the codes in c following practical for my daa assignement 

Merge Sort: Implement the merge sort algorithm to sort an array in ascending or descending order.

```
#include<stdio.h>
#include<stdlib.h>

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
```
/*


This code implements the Merge Sort algorithm to sort an array in ascending order. 

1. `#include<stdio.h>` and `#include<stdlib.h>` are header files required for input/output operations and memory allocation respectively.
2. `void merge(int arr[], int l, int m, int r)` is the function that merges two sub-arrays of the given array `arr[]` into a single sorted sub-array. `l` and `r` are the indices of the first and last elements of the sub-array and `m` is the middle index.
3. `int n1 = m - l + 1` and `int n2 = r - m` calculate the size of the two sub-arrays, `L[]` and `R[]`.
4. `int L[n1], R[n2];` are the two temporary arrays used to store the elements of the two sub-arrays.
5. The for-loops copy the elements of the two sub-arrays into `L[]` and `R[]`.
6. The while-loop merges the elements of `L[]` and `R[]` back into the original array `arr[]` in a sorted manner.
7. The two while-loops copy the remaining elements of `L[]` and `R[]` into `arr[]` if there are any.
8. `void mergeSort(int arr[], int l, int r)` is the function that sorts the given array `arr[]` using the Merge Sort algorithm. `l` and `r` are the indices of the first and last elements of the sub-array to be sorted.
9. The `if` statement checks if `l` is less than `r`, and if so, it calculates the middle index `m` and sorts the two halves of the sub-array using recursive calls to `mergeSort()`.
10. The `merge()` function is then called to merge the two sorted sub-arrays.
11. `void printArray(int A[], int size)` is the function that prints the elements of an array `A[]` of size `size`.
12. `int main()` is the driver function that tests the above functions. It declares an array `arr[]` of integers, calculates its size, prints the original array, sorts the array using `mergeSort()`, and finally, prints the sorted array.
13. The program returns 0, indicating successful execution.
*/
