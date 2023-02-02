write the c code for practical for my daa assignement 

Quick Sort Time Complexity Analysis: Implement the quick sort algorithm and analyze its time complexity for varying values of n (number of elements in the array). Plot a graph to show the relationship between the time taken and n.
 Here is the code for Quick Sort in C:

```
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}
```

To analyze the time complexity, you can use the `clock()` function from `time.h` to measure the time taken for sorting an array of size n. Plot the time taken for sorting arrays of increasing size n to visualize the relationship between time taken and n. The time complexity of Quick Sort is O(n log n) on average, and O(n^2) in the worst case.
/*
 Line by line explanation:

1. `#include <stdio.h>`: This line includes the standard input/output library in the code.

2. `void swap(int *a, int *b)`: This is the declaration of a function `swap` that takes two pointers to integers as arguments and swaps their values.

3. `int temp = *a;`: This line creates a temporary variable `temp` and assigns to it the value stored at the memory location pointed to by `a`.

4. `*a = *b;`: This line assigns the value stored at the memory location pointed to by `b` to the memory location pointed to by `a`.

5. `*b = temp;`: This line assigns the value stored in `temp` to the memory location pointed to by `b`.

6. `int partition(int arr[], int low, int high)`: This is the declaration of a function `partition` that takes an array of integers, and two integers `low` and `high` as arguments.

7. `int pivot = arr[high];`: This line creates a variable `pivot` and assigns to it the value stored in the `high`th element of the array `arr`.

8. `int i = (low - 1);`: This line creates a variable `i` and assigns to it `low - 1`.

9. `for (int j = low; j <= high - 1; j++)`: This is a for loop that iterates from `low` to `high - 1`.

10. `if (arr[j] < pivot)`: This line checks if the `j`th element of the array `arr` is less than the value stored in `pivot`.

11. `i++;`: If the condition in line 10 is true, this line increments the value of `i` by 1.

12. `swap(&arr[i], &arr[j]);`: If the condition in line 10 is true, this line calls the `swap` function with `arr[i]` and `arr[j]` as arguments.

13. `swap(&arr[i + 1], &arr[high]);`: This line calls the `swap` function with `arr[i + 1]` and `arr[high]` as arguments.

14. `return (i + 1);`: This line returns the value of `i + 1`.

15. `void quickSort(int arr[], int low, int high)`: This is the declaration of a function `quickSort` that takes an array of integers and two integers `low` and `high` as arguments.

16. `if (low < high)`: This line checks if `low` is less than `high`.

17. `int pi = partition(arr, low, high);`: If the condition in line 16 is true, this line calls the function `partition` with `arr`, `low`, and `high` as arguments, and stores the return value in the variable `pi`.

18. `quickSort(arr, low, pi - 1);`: If the condition in line 16 is true, this line calls the function `quickSort` with `arr`, `low`, and `pi - 1` as arguments.

19. `quickSort(arr, pi + 1, high);`: If the condition in line 16 is true, this line calls the function `quickSort` with `arr`, `pi + 1`, and `high` as arguments.

20. `int main()`: This is the main function.

21. `int arr[] = {10, 7, 8, 9, 1, 5};`: This line creates an array `arr` with the values `10, 7, 8, 9, 1, 5`.

22. `int n = sizeof(arr) / sizeof(arr[0]);`: This line creates a variable `n` and assigns to it the size of the array `arr` divided by the size of a single element of the array `arr`.

23. `quickSort(arr, 0, n - 1);`: This line calls the function `quickSort` with `arr`, `0`, and `n - 1` as arguments.

24. `printf("Sorted array: \n");`: This line prints the string `"Sorted array: \n"` to the standard output.

25. `for (int i = 0; i < n; i++)`: This is a for loop that iterates from 0 to `n - 1`.

26. `printf("%d ", arr[i]);`: This line prints the `i`th element of the array `arr` to the standard output.

27. `return 0;`: This line returns 0, indicating the successful termination of the program.
*/
/*
  Imagine you have a bunch of toys and you want to sort them by size.

1. `#include <stdio.h>`: This line is like saying you need a helper to print out the toys you sorted.

2. `void swap(int *a, int *b)`: This is like saying you have a helper function to swap two toys you want to switch places.

3. `int temp = *a;`: This line is like saying you have a box to temporarily hold one toy you want to swap.

4. `*a = *b;`: This line is like saying you put the toy in the box into the place of the other toy.

5. `*b = temp;`: This line is like saying you put the other toy into the box.

6. `int partition(int arr[], int low, int high)`: This is like saying you have a helper function to sort a bunch of toys into two piles.

7. `int pivot = arr[high];`: This line is like saying you pick the biggest toy in the bunch.

8. `int i = (low - 1);`: This line is like saying you keep track of the first toy in the left pile.

9. `for (int j = low; j <= high - 1; j++)`: This is like saying you go through all the toys in the bunch one by one.

10. `if (arr[j] < pivot)`: This line is like saying if the toy you are looking at is smaller than the biggest toy.

11. `i++;`: If the condition in line 10 is true, this line is like saying you move the first toy in the left pile one step to the right.

12. `swap(&arr[i], &arr[j]);`: If the condition in line 10 is true, this line is like saying you switch the toy you are looking at with the first toy in the left pile.

13. `swap(&arr[i + 1], &arr[high]);`: This line is like saying you switch the biggest toy with the first toy in the right pile.

14. `return (i + 1);`: This line is like saying you tell the helper function where the first toy in the right pile is.

15. `void quickSort(int arr[], int low, int high)`: This is like saying you have a helper function to sort a bunch of toys.

16. `if (low < high)`: This line is like saying if there is more than one toy in the bunch.

17. `int pi = partition(arr, low, high);`: If the condition in line 16 is true, this line is like saying you ask the helper function to sort the bunch into two piles.

18. `quickSort(arr, low, pi - 1);`: If the condition in line 16 is true, this line is like saying you ask the helper function to sort the left pile.

19. `quickSort(arr, pi + 1, high);`: If the condition in line 16 is true, this line is like saying you ask the helper function to sort the right pile.

20. `int main()`: This is the main function.

21. `int arr[] = {10, 7, 8, 9, 1, 5};`: This line is like saying you have a bunch of toys with sizes `10, 7, 8, 9, 1, 5`.

22. `int n = sizeof(arr) / sizeof(arr[0]);`: This line is like saying you keep track of how many toys you have.

23. `quickSort(arr, 0, n - 1);`: This line is like saying you ask the helper function to sort all the toys.

24. `printf("Sorted array: \n");`: This line is like saying you ask the helper to print out the message "Sorted array:".

25. `for (int i = 0; i < n; i++)`: This is like saying you go through all the toys one by one.

26. `printf("%d ", arr[i]);`: This line is like saying you ask the helper to print out the size of each toy.

27. `return 0;`: This line is like saying you are done sorting the toys.
*/
