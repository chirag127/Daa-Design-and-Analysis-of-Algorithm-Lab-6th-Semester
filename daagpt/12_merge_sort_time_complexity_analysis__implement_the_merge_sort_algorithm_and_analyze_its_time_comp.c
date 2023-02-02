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
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;
    clock_t t;
    t = clock();
    mergeSort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("Sorted array: \n"); 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\nTime taken: %f", time_taken); 
    return 0; 
} 
```

To plot the graph, you can modify the code to repeat the sorting process for different values of n and record the time taken for each iteration. Then, you can use a plotting library such as matplotlib in Python to plot the data as a scatter plot.
/*
explain the following code 


```
#include <stdio.h>
#include <stdlib.h>
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
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;
    clock_t t;
    t = clock();
    mergeSort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("Sorted array: \n"); 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\nTime taken: %f", time_taken); 
    return 0; 
} 
```

To plot the graph, you can modify the code to repeat the sorting process for different values of n and record the time taken for each iteration. Then, you can use a plotting library such as matplotlib in Python to plot the data as a scatter plot.

This code implements the Merge Sort algorithm in C and measures the time taken to sort an array of random integers.

The `merge` function takes in an array `arr`, the left index `l`, the middle index `m`, and the right index `r`. It splits the input array into two sub-arrays `L` and `R` and then merges them back into the original array in a sorted manner.

The `mergeSort` function takes in an array `arr`, the left index `l`, and the right index `r`. It uses the divide-and-conquer approach to sort the array by dividing it into two halves, calling `mergeSort` recursively on each half, and then merging the two sorted halves using the `merge` function.

In the `main` function, the user is prompted to enter the number of elements in the array. A random array of integers is generated and the time taken to sort it using the `mergeSort` function is measured using the `clock` function from the `time.h` library. The sorted array and the time taken are then printed to the console.
*/
