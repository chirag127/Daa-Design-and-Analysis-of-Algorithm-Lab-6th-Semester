#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
/* Here is the explanation for the code above:
1. The first for loop is used for traversing the array from the second element of the array. So, i starts from 1 and not 0.
2. The second for loop is used for traversing the array from the 0th index till the i-1 th index. The array from 0th index to i-1 th index is sorted.
3. The key variable is used to store the current element. So, the key variable stores the value of arr[i].
4. The j variable is used for traversing the array from the i-1 th index till the 0th index.
5. The while loop is used for comparing the key variable with arr[j]. If the arr[j] > key, then arr[j] is shifted to the right by one position. This shifting is done till the arr[j] > key is true.
6. Once the while loop is broken, the key variable is assigned to arr[j+1]. So, the key variable is placed in the right position.
7. The printArray function is used for printing the array.
8. The main function contains the array arr[] and the size of the array n.
9. The insertionSort function is called with arr[] and n as the arguments.
10. The printArray function is called with arr[] and n as the arguments. */