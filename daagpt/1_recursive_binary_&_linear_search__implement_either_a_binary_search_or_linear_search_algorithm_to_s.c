
#include <stdio.h>
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);

    i/*
 

Binary Search:
- `#include <stdio.h>`: This line includes the standard input-output library in the program.
- `int binarySearch(int arr[], int l, int r, int x)`: This is the function definition for the binary search algorithm. It takes in an integer array `arr`, the left index `l`, the right index `r`, and the target element `x` to search for. It returns the index of the target element if found, and -1 if not found.
- `if (r >= l)`: This is the base case for the recursive binary search. If the left index is greater than or equal to the right index, it means the target element is not in the array.
- `int mid = l + (r - l) / 2;`: This line calculates the middle index of the current subarray.
- `if (arr[mid] == x)`: If the target element is found at the middle index, return the index.
- `if (arr[mid] > x)`: If the target element is less than the middle element, search in the left half of the subarray.
- `return binarySearch(arr, mid + 1, r, x);`: If the target element is greater than the middle element, search in the right half of the subarray.
- `return -1;`: If the target element is not found, return -1.
- `int main(void)`: This is the main function of the program.
- `int arr[] = { 2, 3, 4, 10, 40 };`: This line initializes an integer array with the values `2, 3, 4, 10, 40`.
- `int n = sizeof(arr) / sizeof(arr[0]);`: This line calculates the size of the array.
- `int x = 10;`: This line initializes the target element to search for as `10`.
- `int result = binarySearch(arr, 0, n - 1, x);`: This line calls the binary search function with the array `arr`, the left index `0`, the right index `n - 1`, and the target element `x`, and stores the result in the `result` variable.
- `(result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);`: This line uses a ternary operator to print whether the target element was found or not. If the result is -1, it means the target element was not found, and the message "Element is not present in array" is printed. If the result is not -1, it means the target element was found, and the message "Element is present at index [result]" is printed.
- `return 0;`: This line returns 0 to indicate the program finished executing successfully.

Linear Search:
- `#include <stdio.h>`: This line includes the standard input-output library in the program.
- `int linearSearch(int arr[], int n, int x)`: This is the function definition for the linear search algorithm. It takes in an integer array `arr`, the size of the array `n`, and the target element `x` to search for. It returns the index of the target element if found, and -1 if not found.
- `int i;`: This line declares a variable `i` to use as the loop index.
- `for (i = 0; i < n; i++)`: This is the for loop that iterates through the array. The loop continues as long as `i` is less than `n`.
- `if (arr[i] == x)`: If the target element is found at the current index, return the index.
- `return -1;`: If the target element is not found, return -1.
- `int main(void)`: This is the main function of the program.
- `int arr[] = { 2, 3, 4, 10, 40 };`: This line initializes an integer array with the values `2, 3, 4, 10, 40`.
- `int n = sizeof(arr) / sizeof(arr[0]);`: This line calculates the size of the array.
- `int x = 10;`: This line initializes the target element to search for as `10`.
- `int result = linearSearch(arr, n, x);`: This line calls the linear search function with the array `arr`, the size of the array `n`, and the target element `x`, and stores the result in the `result` variable.
- `(result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);`: This line uses a ternary operator to print whether the target element was found or not. If the result is -1, it means the target element was not found, and the message "Element is not present in array" is printed. If the result is not -1, it means the target element was found, and the message "Element is present at index [result]" is printed.
- `return 0;`: This line returns 0 to indicate the program finished executing successfully.
*/
