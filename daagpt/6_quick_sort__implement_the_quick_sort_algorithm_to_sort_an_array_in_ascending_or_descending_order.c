write the codes in c following practical for my daa assignement 

Quick Sort: Implement the quick sort algorithm to sort an array in ascending or descending order.

```
#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i <= high)
                i++;
            while (arr[j] > arr[pivot] && j >= low)
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int arr[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```
/*
explain the following code 


```
#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i <= high)
                i++;
            while (arr[j] > arr[pivot] && j >= low)
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int arr[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```
 This code implements the Quick Sort algorithm to sort an array of integers in ascending order. The `quickSort` function takes an array `arr`, the lower index `low` and the higher index `high` as arguments. The function uses the pivot element as the first element of the array and partitions the array into two sub-arrays. The elements that are smaller than the pivot are placed on the left side of the pivot, and the elements that are larger are placed on the right side. The function then calls itself recursively on the two sub-arrays until the entire array is sorted. The `main` function takes the input of the number of elements and the elements of the array, calls the `quickSort` function and prints the sorted array.
*/
