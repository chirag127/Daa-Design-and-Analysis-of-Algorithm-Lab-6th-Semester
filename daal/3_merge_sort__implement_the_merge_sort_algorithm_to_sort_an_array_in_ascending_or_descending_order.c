write the c code for practical for my daa assignement 

Merge Sort: Implement the merge sort algorithm to sort an array in ascending or descending order.
 
```
#include<stdio.h> 
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
/*


```
#include<stdio.h>
```
This line includes the standard input/output library in the program.

```
void merge(int arr[], int l, int m, int r)
```
This line declares the function "merge" that takes an array of integers "arr", an integer "l" for the left index, an integer "m" for the middle index, and an integer "r" for the right index as arguments. This function is used to merge two subarrays of the original array.

```
int i, j, k;
int n1 = m - l + 1;
int n2 =  r - m;
int L[n1], R[n2];
```
This block declares three integer variables "i", "j", and "k" and two integer variables "n1" and "n2". "n1" is calculated as the difference between the middle index and the left index plus 1, and "n2" is calculated as the difference between the right index and the middle index. Two arrays "L" and "R" are declared with sizes "n1" and "n2" respectively.

```
for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
```
This for loop copies the elements from the left half of the original array to the array "L".

```
for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];
```
This for loop copies the elements from the right half of the original array to the array "R".

```
i = 0;
j = 0;
k = l;
```
These lines initialize the variables "i", "j", and "k" to 0, 0, and "l" respectively.

```
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
This while loop compares the elements of the arrays "L" and "R" and merges them in sorted order into the original array "arr".

```
while (i < n1)
{
    arr[k] = L[i];
    i++;
    k++;
}
```
This while loop copies the remaining elements of the array "L" into the original array "arr".

```
while (j < n2)
{
    arr[k] = R[j];
    j++;
    k++;
}
```
This while loop copies the remaining elements of the array "R" into the original array "arr".

```
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```
This function "mergeSort" sorts the elements of the original array "arr" using the merge sort algorithm. It takes the original array, the left index "l", and the right index "r" as arguments. If the left index is less than the right index, it calculates the middle index "m", and calls the "mergeSort" function recursively for the left half and the right half of the original array. Finally, it calls the "merge" function to merge the two sorted subarrays.

```
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
```
This function "printArray" takes an array of integers "A" and its size as arguments and prints the elements of the array.

```
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
```
This is the main function of the program. It declares an array of integers "arr" with some elements, calculates its size "arr_size", and prints the original array. Then it calls the "mergeSort" function to sort the elements of the array and prints the sorted array. Finally, it returns 0.
*/
/*
 This is a C program that sorts an array of integers using the merge sort algorithm. The program first declares a function "merge" that takes four arguments, an array of integers, and three integers for the left, middle, and right indices of the array. The function is used to merge two subarrays of the original array into a single sorted subarray. Then it declares a function "mergeSort" that sorts the elements of the original array using the merge sort algorithm. The function takes the original array and two integers for the left and right indices of the array as arguments. Finally, it declares a function "printArray" that takes an array of integers and its size as arguments and prints the elements of the array. The main function of the program declares an array of integers, calculates its size, prints the original array, calls the "mergeSort" function to sort the elements of the array, and prints the sorted array.
*/
