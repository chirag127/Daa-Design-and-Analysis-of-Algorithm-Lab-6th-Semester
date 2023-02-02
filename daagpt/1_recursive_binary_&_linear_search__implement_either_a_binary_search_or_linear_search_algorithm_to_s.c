
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);

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
// ```

// And here's an example code for linear search in C:

// ```
#include <stdio.h>

int search(int arr[], int n, int x)
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
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = search(arr, n, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}

// The first code is an implementation of a recursive binary search algorithm in C. The `binarySearch` function takes an array `arr`, the left index `l`, the right index `r`, and the element `x` to be searched for as inputs. The function uses a recursive approach to divide the array into halves and search for `x` in the appropriate half. If `x` is found, its index is returned. If `x` is not found, the function returns -1

// The second code is an implementation of a linear search algorithm in C. The `search` function takes an array `arr`, the size of the array `n`, and the element `x` to be searched for as inputs. The function uses a loop to iterate through the array and search for `x`. If `x` is found, its index is returned. If `x` is not found, the function returns -1.
