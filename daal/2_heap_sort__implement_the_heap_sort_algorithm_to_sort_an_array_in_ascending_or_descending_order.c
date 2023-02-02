write the c code for practical for my daa assignement 

Heap Sort: Implement the heap sort algorithm to sort an array in ascending or descending order.

```c
#include<stdio.h>
#include<stdlib.h>
 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void heapify(int arr[], int n, int i, int order) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 
    if (order == 1) {
        if (l < n && arr[l] > arr[largest])
            largest = l;
 
        if (r < n && arr[r] > arr[largest])
            largest = r;
 
        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            heapify(arr, n, largest, order);
        }
    } else {
        if (l < n && arr[l] < arr[largest])
            largest = l;
 
        if (r < n && arr[r] < arr[largest])
            largest = r;
 
        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            heapify(arr, n, largest, order);
        }
    }
}
 
void heapSort(int arr[], int n, int order) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, order);
 
    for (i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, order);
    }
}
 
void printArray(int arr[], int n) {
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, n);
 
    heapSort(arr, n, 1);
 
    printf("\nSorted array is \n");
    printArray(arr, n);
 
    return 0;
}
```
