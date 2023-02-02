
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
            {
                i++;
            }
            while (arr[j] > arr[pivot] && j >= low)
            {
                j--;
            }
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
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
```
/*


- `#include <stdio.h>`: This line includes the standard input/output library in the program.

- `void quickSort(int arr[], int low, int high)`: This function sorts an array of integers `arr[]` from index `low` to `high` using the quick sort algorithm.

- `int pivot, i, j, temp;`: These variables are used in the quicksort algorithm. `pivot` is the pivot element, `i` is the left pointer, `j` is the right pointer, and `temp` is used to store a temporary value during swapping.

- `if (low < high)`: This line checks if the low index is less than the high index, which means that there is a sub-array to be sorted. If the low index is greater than or equal to the high index, then the sub-array is already sorted and the function returns.

- `pivot = low;`: This line sets the pivot element to the first element of the sub-array.

- `i = low; j = high;`: These lines set the left and right pointers to the first and last elements of the sub-array, respectively.

- `while (i < j)`: This line starts a loop that continues until the left pointer is greater than or equal to the right pointer.

- `while (arr[i] <= arr[pivot] && i <= high)`: This line starts a loop that continues until either the value at the current left pointer is greater than the pivot value or the left pointer has reached the end of the sub-array.

- `while (arr[j] > arr[pivot] && j >= low)`: This line starts a loop that continues until either the value at the current right pointer is less than or equal to the pivot value or the right pointer has reached the start of the sub-array.

- `if (i < j)`: This line checks if the left pointer is still less than the right pointer, which means that the two pointers have not crossed each other yet. If the pointers have crossed, then the sub-array is partitioned and the function returns.

- `temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;`: This line swaps the values at the left and right pointers.

- `temp = arr[j]; arr[j] = arr[pivot]; arr[pivot] = temp;`: This line swaps the pivot value with the value at the right pointer, which places the pivot value in its final position in the sorted array.

- `quickSort(arr, low, j - 1); quickSort(arr, j + 1, high);`: These lines recursively call the `quickSort` function on the sub-arrays to the left and right of the pivot value.

- `int arr[100], n, i;`: These variables are used in the main function. `arr` is an array of integers, `n` is the number of elements in the array, and `i` is a loop counter.

- `printf("Enter the number of elements: "); scanf("%d", &n);`: This line prompts the user to enter the number of elements in the array and stores the value in `n`.

- `printf("Enter the elements: ");`: This line prompts the user to enter the elements of the array.

- `for (i = 0; i < n; i++)`: This line starts a loop that continues until all elements of the array have been entered.

- `scanf("%d", &arr[i]);`: This line reads the current element of the array from the user.

- `quickSort(arr, 0, n - 1);`: This line calls the `quickSort` function to sort the array.

- `printf("Sorted array: ");`: This line prints the message "Sorted array:".

- `for (i = 0; i < n; i++)`: This line starts a loop that continues until all elements of the sorted array have been printed.

- `printf("%d ", arr[i]);`: This line prints the current element of the sorted array.

- `return 0;`: This line returns 0 to indicate that the program has executed successfully.
*/
