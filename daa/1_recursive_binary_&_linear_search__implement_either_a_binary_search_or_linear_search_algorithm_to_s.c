
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}
```

And here's the code for Linear Search in C:

```
#include <stdio.h>

int search(int arr[], int n, int x)
{
   int i;
   for (i=0; i < n; i++)
       if (arr[i] == x)
         return i;
   return -1;
}

int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = search(arr, n, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}
```
/*


Recursive Binary Search:
1. #include <stdio.h> - This line includes the standard input/output library in the program.
2. int binarySearch(int arr[], int l, int r, int x) - This line declares a function binarySearch which takes an integer array, two integers l and r and an integer x as input.
3. if (r >= l) - This line checks if the right index is greater than or equal to the left index.
4. int mid = l + (r - l)/2; - This line calculates the middle index of the array.
5. if (arr[mid] == x)  return mid; - This line checks if the element at the middle index is equal to the target element x. If it is, it returns the index.
6. if (arr[mid] > x) return binarySearch(arr, l, mid-1, x); - This line checks if the element at the middle index is greater than the target element x. If it is, it calls the binarySearch function recursively with the left half of the array.
7. return binarySearch(arr, mid+1, r, x); - This line calls the binarySearch function recursively with the right half of the array.
8. return -1; - This line returns -1 if the target element is not found in the array.
9. int main(void) - This line declares the main function.
10. int arr[] = {2, 3, 4, 10, 40}; - This line declares an integer array with elements 2, 3, 4, 10, 40.
11. int n = sizeof(arr)/ sizeof(arr[0]); - This line calculates the number of elements in the array.
12. int x = 10; - This line declares the target element x.
13. int result = binarySearch(arr, 0, n-1, x); - This line calls the binarySearch function with the array, the left index 0, the right index n-1 and the target element x.
14. (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result); - This line checks if the result of binarySearch is -1. If it is, it prints "Element is not present in array". If not, it prints "Element is present at index [result]".
15. return 0; - This line returns 0 from the main function.

Linear Search:
1. #include <stdio.h> - This line includes the standard input/output library in the program.
2. int search(int arr[], int n, int x) - This line declares a function search which takes an integer array, an integer n and an integer x as input.
3. int i; - This line declares an integer i.
4. for (i=0; i < n; i++) - This line starts a for loop which runs from 0 to n-1.
5. if (arr[i] == x) - This line checks if the element at the current index i is equal to the target element x.
6. return i; - This line returns the index i if the element is found.
7. return -1; - This line returns -1 if the target element is not found in the array.
8. int main(void) - This line declares the main function.
9. int arr[] = {2, 3, 4, 10, 40}; - This line declares an integer array with elements 2, 3, 4, 10, 40.
10. int n = sizeof(arr)/ sizeof(arr[0]); - This line calculates the number of elements in the array.
11. int x = 10; - This line declares the target element x.
12. int result = search(arr, n, x); - This line calls the search function with the array, the number of elements n and the target element x.
13. (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result); - This line checks if the result of search is -1. If it is, it prints "Element is not present in array". If not, it prints "Element is present at index [result]".
14. return 0; - This line returns 0 from the main function.
*/
