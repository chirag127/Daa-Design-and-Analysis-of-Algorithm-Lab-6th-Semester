write the codes in c following practical for my daa assignement 

Merge Sort Time Complexity Analysis: Implement the merge sort algorithm and analyze its time complexity for varying values of n (number of elements in the array). Plot a graph to show the relationship between the time taken and n.

```
#include <stdio.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
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
        }
        else {
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

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    clock_t t;
    t = clock();
    mergeSort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTime taken by program is: %f\n", time_taken);
    return 0;
}
```
Note: To plot the graph, you can save the values of n and time taken for each iteration in a file and use a plotting tool like gnuplot or matplotlib to plot the graph.
/*
 

```
#include <stdio.h>
#include <time.h>
```
These are the header files included for standard input/output and time functions.

```
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
```
Here, `merge` function takes an integer array `arr`, and three integers `l`, `m`, and `r` as arguments. `i`, `j`, and `k` are declared as integers. `n1` is calculated as `m-l+1` and `n2` is calculated as `r-m`. `L` and `R` are two integer arrays with `n1` and `n2` elements, respectively.

```
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
```
In these two for loops, `L` and `R` arrays are filled with elements from `arr`.

```
    i = 0;
    j = 0;
    k = l;
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
```
`i`, `j`, and `k` are initialized to 0, 0, and `l` respectively. The while loop runs until `i` is less than `n1` and `j` is less than `n2`. If `L[i]` is less than or equal to `R[j]`, the `arr[k]` is assigned `L[i]` and `i` is incremented by 1. Else, `arr[k]` is assigned `R[j]` and `j` is incremented by 1. `k` is incremented by 1 in each iteration.

```
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
```
Two while loops are used to copy the remaining elements of `L` and `R` arrays to `arr`.

```
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```
`mergeSort` function takes an integer array `arr`, and two integers `l` and `r` as arguments. If `l` is less than `r`, `m` is calculated as `l + (r - l) / 2`. Then, `mergeSort` is called recursively twice, once for the first half of the array and once for the second half. The `merge` function is called to merge the two sorted halves.

```
int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
```
In the `main` function, the number of elements in the array is taken as input from the user. The array is initialized with random numbers less than 100.

```
    clock_t t;
    t = clock();
    mergeSort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
```
The time is taken before and after the `mergeSort` function is called and the time taken is calculated as `time_taken`.

```
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTime taken by program is: %f\n", time_taken);
    return 0;
}
```
The sorted array is printed, followed by the time taken by the program.
*/
