write the c code for practical for my daa assignement 

Selection Sort: Implement the selection sort algorithm to sort an array in ascending or descending order.
 Here's a C code implementation of selection sort algorithm to sort an array in ascending order:

```
#include <stdio.h>

void selectionSort(int arr[], int n) {
  int i, j, minIndex, temp;
  for (i = 0; i < n-1; i++) {
    minIndex = i;
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr, n);
  printf("Sorted array: \n");
  for (int i=0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
```

To sort the array in descending order, change the condition in the inner loop to `if (arr[j] > arr[minIndex])`.
/*


1. `#include <stdio.h>`: This line includes the standard input/output library in the code.

2. `void selectionSort(int arr[], int n)`: This line declares a function named `selectionSort` that takes two parameters: an integer array `arr` and an integer `n`. The `void` keyword means the function does not return a value.

3. `int i, j, minIndex, temp;`: These lines declare four integer variables: `i`, `j`, `minIndex`, and `temp`.

4. `for (i = 0; i < n-1; i++)`: This line starts a for loop that will run `n-1` times. The variable `i` is initialized to 0 and will be incremented by 1 each iteration up to `n-1`.

5. `minIndex = i;`: This line sets the value of `minIndex` to the current value of `i`.

6. `for (j = i+1; j < n; j++)`: This line starts a nested for loop that will run `n-(i+1)` times. The variable `j` is initialized to `i+1` and will be incremented by 1 each iteration up to `n`.

7. `if (arr[j] < arr[minIndex])`: This line checks if the value of `arr[j]` is less than the value of `arr[minIndex]`.

8. `minIndex = j;`: If the condition in the previous line is true, the value of `minIndex` is updated to `j`.

9. `temp = arr[minIndex];`: This line stores the value of `arr[minIndex]` in the variable `temp`.

10. `arr[minIndex] = arr[i];`: This line sets the value of `arr[minIndex]` to the value of `arr[i]`.

11. `arr[i] = temp;`: This line sets the value of `arr[i]` to the value stored in `temp`.

12. `int main()`: This line starts the main function.

13. `int arr[] = {64, 25, 12, 22, 11};`: This line declares an integer array `arr` with the values `64, 25, 12, 22, 11`.

14. `int n = sizeof(arr)/sizeof(arr[0]);`: This line calculates the number of elements in the array `arr` and stores the result in the integer variable `n`.

15. `selectionSort(arr, n);`: This line calls the `selectionSort` function with the arguments `arr` and `n`.

16. `printf("Sorted array: \n");`: This line prints the string `"Sorted array: \n"` to the console.

17. `for (int i=0; i < n; i++)`: This line starts a for loop that will run `n` times. The variable `i` is initialized to 0 and will be incremented by 1 each iteration up to `n`.

18. `printf("%d ", arr[i]);`: This line prints the value of `arr[i]` followed by a space to the console.

19. `return 0;`: This line returns the value 0 from the `main` function.
*/
/*


1. `#include <stdio.h>`: This line adds some helper tools so we can print things on the screen.

2. `void selectionSort(int arr[], int n)`: This line starts a plan to sort a list of numbers. It takes two things: a list of numbers and how many numbers are in the list.

3. `int i, j, minIndex, temp;`: These lines make four helpers to help us sort the list of numbers.

4. `for (i = 0; i < n-1; i++)`: This line starts a big loop that will repeat `n-1` times. The helper `i` starts at 0 and goes up by 1 each time through the loop.

5. `minIndex = i;`: This line sets the helper `minIndex` to the current value of `i`.

6. `for (j = i+1; j < n; j++)`: This line starts a smaller loop inside the big loop. It will repeat `n-(i+1)` times. The helper `j` starts at `i+1` and goes up by 1 each time through the loop.

7. `if (arr[j] < arr[minIndex])`: This line checks if the number in the list at place `j` is smaller than the number in the list at place `minIndex`.

8. `minIndex = j;`: If the numbers in step 7 are true, then `minIndex` is changed to `j`.

9. `temp = arr[minIndex];`: This line saves the number at place `minIndex` in a helper called `temp`.

10. `arr[minIndex] = arr[i];`: This line swaps the number at place `minIndex` with the number at place `i`.

11. `arr[i] = temp;`: This line swaps the number at place `i` with the number saved in `temp`.

12. `int main()`: This line starts the main part of the program.

13. `int arr[] = {64, 25, 12, 22, 11};`: This line makes a list of numbers with the values `64, 25, 12, 22, 11`.

14. `int n = sizeof(arr)/sizeof(arr[0]);`: This line finds out how many numbers are in the list and saves it in the helper `n`.

15. `selectionSort(arr, n);`: This line runs the plan from step 2 with the list of numbers and how many numbers are in the list.

16. `printf("Sorted array: \n");`: This line prints the words "Sorted array:" followed by a blank line.

17. `for (int i=0; i < n; i++)`: This line starts a loop that will repeat `n` times. The helper `i` starts at 0 and goes up by 1 each time through the loop.

18. `printf("%d ", arr[i]);`: This line prints the number at place `i` in the list, followed by a space.

19. `return 0;`: This line ends the main part of the program and gives back the number 0.
*/
