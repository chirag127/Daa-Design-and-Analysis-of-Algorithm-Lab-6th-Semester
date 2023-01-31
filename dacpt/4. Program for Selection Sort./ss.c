#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    printf("Sorted array: \n");
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
/* Here is the explanation for the code above:
1. The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

2. 1) The subarray which is already sorted.
3. 2) Remaining subarray which is unsorted.

4. In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

5. Following example explains the above steps:

6. Let 10, 25, 30, 5, 15, 20 be the input array and size be 6.

7. 10, 25, 30, 5, 15, 20 be the given array and size be 6.

8. In the above array, find the lowest element 5 and place it at the beginning of the array.

9. Then find the lowest element from 10, 25, 30, 15, 20 and place it at the beginning of the array after 5.

10. Then find the lowest element from 10, 25, 30, 20 and place it at the beginning of the array after 5, 10.

11. Then find the lowest element from 25, 30, 20 and place it at the beginning of the array after 5, 10, 15.

12. Then find the lowest element from 30, 20 and place it at the beginning of the array after 5, 10, 15, 20.

13. Then find the lowest element from 30 and place it at the beginning of the array after 5, 10, 15, 20, 25.

14. Finally, the lowest element from 30 and place it at the beginning of the array after 5, 10, 15, 20, 25, 30.

15. The array will then become 5, 10, 15, 20, 25, 30. */