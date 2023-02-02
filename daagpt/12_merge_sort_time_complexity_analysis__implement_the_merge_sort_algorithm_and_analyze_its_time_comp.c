write the codes in c following practical for my daa assignement 

Merge Sort Time Complexity Analysis: Implement the merge sort algorithm and analyze its time complexity for varying values of n (number of elements in the array). Plot a graph to show the relationship between the time taken and n.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 

int main() 
{ 
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    clock_t t;
    t = clock();
    mergeSort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Sorted array: \n"); 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0; 
} 
```

To plot the graph, you can modify the code to store the time taken for each value of n in an array and then use a plotting library such as matplotlib in Python to plot the graph.
/*


```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
```
These are header files required for the implementation of the program. `<stdio.h>` is for input/output functions, `<stdlib.h>` for general purpose functions and `<time.h>` for time-related functions.

```
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
```
This is the implementation of the merge function which is a part of the merge sort algorithm. It takes a given array `arr` and its indices `l`, `m`, and `r` as inputs. `n1` and `n2` are the sizes of the two sub-arrays `L` and `R` that will be created from `arr`. The first `for` loop copies the elements from `arr` to `L` and the second `for` loop copies the elements from `arr` to `R`.

```
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
```
The `while` loop merges the elements from `L` and `R` back to `arr`. The loop continues until either `L` or `R` is completely merged. If the current element in `L` is smaller or equal to the current element in `R`, it is copied to `arr` and the index `i` of `L` is incremented. If the current element in `R` is smaller, it is copied to `arr` and the index `j` of `R` is incremented. The index `k` of `arr` is incremented in either case.

```
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
```
The two `while` loops copy the remaining elements from `L` and `R` to `arr` if either `L` or `R` has not been completely merged.

```
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 
```
This is the implementation of the merge sort algorithm. The function takes an array `arr` and its indices `l` and `r` as inputs. The function recursively divides the array into two halves until each sub-array has only one element. Then, the merge function is called to merge the sub-arrays back to `arr` in sorted order.

```
int main() 
{ 
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
```
In the `main` function, the user is prompted to enter the number of elements in the array `arr`. The elements of `arr` are then initialized to random values less than 100.

```
    clock_t t;
    t = clock();
    mergeSort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
```
The time taken by the merge sort algorithm is measured using the `clock` function from the `<time.h>` header file. The time taken is stored in the `time_taken` variable.

```
    printf("Sorted array: \n"); 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0; 
} 
```
The sorted array and the time taken by the algorithm are printed. The program returns 0, indicating successful execution.
*/
