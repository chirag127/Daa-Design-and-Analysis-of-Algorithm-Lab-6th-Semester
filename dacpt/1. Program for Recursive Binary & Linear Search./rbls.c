#include <stdio.h>
#include <stdlib.h>

// Recursive Binary Search
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not present in array
    return -1;
}

// Linear Search
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d\n", result);
    result = linearSearch(arr, n, x);
    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d\n", result);
    return 0;
}
/* Here is the explanation for the code above:
1. The function to perform the binary search is called binarySearch. It takes the array, the leftmost index, the rightmost index, and the element to be searched as parameters.
2. If the element to be searched is found at the middle, the function returns the index of the element.
3. If the element to be searched is smaller than the element at the middle, the function is called again with the left subarray.
4. If the element to be searched is greater than the element at the middle, the function is called again with the right subarray.
5. If the element is not found, the function returns -1.
6. The function to perform the linear search is called linearSearch. It takes the array, the size of the array, and the element to be searched as parameters.
7. The function returns the index of the element if it is found, and -1 if it is not found.
8. The main function initializes the array, the size of the array, and the element to be searched.
9. The linear search is performed and the result is printed.
10. The binary search is performed and the result is printed.
11. The program ends. */
