write the codes in c following practical for my daa assignement 

Heap Sort: Implement the heap sort algorithm to sort an array in ascending or descending order.
 
```
#include<stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i=0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
}
```
/*


```
#include<stdio.h>
```
This line includes the standard input/output library in the program.

```
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
```
This function `heapify` takes an array `arr`, its size `n`, and an index `i` as input. It initializes `largest` as `i` and calculates the indices of its left and right children as `l` and `r` respectively.

```
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
```
It then checks if the left child exists and if it's greater than the current root, then updates the value of `largest` to `l`. Similarly, it checks for the right child.

```
    if (largest != i)
    {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, n, largest);
    }
}
```
If `largest` is not equal to `i`, it means the current root is not the largest value, so it swaps the values of the current root and the largest value and calls `heapify` again with the updated root.

```
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
```
The `heapSort` function takes an array `arr` and its size `n` as input. It starts from the middle of the array (the last non-leaf node) and calls `heapify` to convert the sub-tree rooted at each node into a max heap.

```
    for (int i=n-1; i>=0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
```
It then repeatedly swaps the root (the largest element) with the last element and calls `heapify` on the reduced heap to get the next largest element and repeats the process until the whole array is sorted.

```
void printArray(int arr[], int n)
{
    for (int i=0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
```
The `printArray` function takes an array `arr` and its size `n` as input and prints the elements of the array.

```
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
}
```
The `main` function initializes an array `arr` with some values, calculates its size `n`, sorts the array using `heapSort`, and prints the sorted array.
*/
