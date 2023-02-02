write the c code for practical for my daa assignement 

Merge Sort Time Complexity Analysis: Implement the merge sort algorithm and analyze its time complexity for varying values of n (number of elements in the array). Plot a graph to show the relationship between the time taken and n.
 
```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; j = 0; k = l;
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
 
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
```

To analyze the time complexity, you can use the `clock()` function from the `time.h` library. For example, you can add the following code to measure the time taken for sorting an array of size `n`:
```
clock_t t;
t = clock();
mergeSort(arr, 0, n-1);
t = clock() - t;
double time_taken = ((double)t)/CLOCKS_PER_SEC;
printf("Merge sort took %f seconds to execute \n", time_taken);
```
Repeat the above steps for different values of `n` and plot the relationship between `n` and `time_taken` to show the time complexity of the merge sort algorithm.
/*


```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
```
This line includes the standard input/output library, standard library, and time library in the code.

```
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
```
This function `merge` takes an array `arr`, and three integer values `l`, `m`, and `r` as input. It declares three variables `i`, `j`, and `k` and two variables `n1` and `n2` which store the sizes of two sub-arrays to be merged. 

```
    int L[n1], R[n2];
```
Two arrays `L` and `R` are declared with sizes `n1` and `n2` respectively.

```
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
```
These two `for` loops copy the elements from the original array `arr` to the arrays `L` and `R`.

```
    i = 0; j = 0; k = l;
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
This `while` loop merges the two arrays `L` and `R` back into the original array `arr` in a sorted order.

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
These two `while` loops copy the remaining elements of arrays `L` and `R` back into the original array `arr`.

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
The function `mergeSort` implements the merge sort algorithm. It takes an array `arr` and two integer values `l` and `r` as input. If the value of `l` is less than `r`, it calculates the middle element `m` of the array and calls the `mergeSort` function recursively for the two halves of the array. After the two halves are sorted, the `merge` function is called to merge the two sorted halves.

```
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
```
The function `printArray` takes an array `A` and its size as input and prints the elements of the array.

```
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
```
The `main` function declares an array `arr` with some elements, calculates its size, and prints the original array. The `mergeSort` function is called to sort the array and the sorted array is printed. The function returns 0.

```
clock_t t;
t = clock();
mergeSort(arr, 0, n-1);
t = clock() - t;
double time_taken = ((double)t)/CLOCKS_PER_SEC;
printf("Merge sort took %f seconds to execute \n", time_taken);
```
This code measures the time taken by the `mergeSort` function to sort an array of size `n` and prints the time taken in seconds.
*/
/*
 The code is a program to sort an array of integers using the merge sort algorithm. It has functions to sort the array, merge two sorted arrays, print the array, and measure the time taken by the sort function. The `main` function declares an array, sorts it using the `mergeSort` function, and prints the sorted array. The time taken by the sort function is also measured and printed.
*/
