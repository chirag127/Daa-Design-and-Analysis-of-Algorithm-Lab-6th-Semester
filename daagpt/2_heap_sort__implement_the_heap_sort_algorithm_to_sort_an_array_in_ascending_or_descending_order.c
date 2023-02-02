
#include <stdio.h>
#include <stdlib.h>

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
        int swap = arr[0];
        arr[0] = arr[i];
        arr[i] = swap;

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


- `#include <stdio.h>` and `#include <stdlib.h>` are header files which provide standard input/output and general purpose functions in C.
- `void heapify(int arr[], int n, int i)` is a function that takes in an array `arr`, its size `n`, and an index `i`. It is used to maintain the heap property.
- `int largest = i;` initializes `largest` with `i` which is the index of the current node.
- `int l = 2*i + 1;` and `int r = 2*i + 2;` are used to calculate the indices of the left and right children of the node at index `i` in the array.
- `if (l < n && arr[l] > arr[largest])` checks if the left child exists and if its value is greater than the current node. If so, it updates `largest` with the index of the left child.
- `if (r < n && arr[r] > arr[largest])` checks if the right child exists and if its value is greater than the current node. If so, it updates `largest` with the index of the right child.
- `if (largest != i)` checks if the current node is not the largest among its children. If so, it swaps the current node with the largest child and calls `heapify` on the child to maintain the heap property.
- `void heapSort(int arr[], int n)` is a function that sorts the input array `arr` of size `n` using the heap sort algorithm.
- `for (int i = n / 2 - 1; i >= 0; i--)` is a loop that starts from the last non-leaf node and calls `heapify` on each node to build the heap.
- `for (int i=n-1; i>=0; i--)` is a loop that performs the sorting by repeatedly swapping the root node with the last node and calling `heapify` on the root node.
- `void printArray(int arr[], int n)` is a function that takes in an array `arr` and its size `n` and prints the elements of the array.
- `int main()` is the main function that initializes an array with values, calculates its size, calls `heapSort` on the array, prints the sorted array, and returns 0.
*/
