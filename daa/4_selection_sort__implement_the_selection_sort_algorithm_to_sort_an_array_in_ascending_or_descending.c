write the codes in c following practical for my daa assignement 

Selection Sort: Implement the selection sort algorithm to sort an array in ascending or descending order.
 
```
#include <stdio.h>

void selectionSort(int arr[], int n, int ascending) {
  int i, j, minIndex, temp;
  for (i = 0; i < n-1; i++) {
    minIndex = i;
    for (j = i+1; j < n; j++) {
      if (ascending) {
        if (arr[j] < arr[minIndex])
          minIndex = j;
      } else {
        if (arr[j] > arr[minIndex])
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
  int ascending = 1; // 1 for ascending, 0 for descending

  selectionSort(arr, n, ascending);

  printf("Sorted array: \n");
  for (int i=0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}
```
/*


1. `#include <stdio.h>` - This line includes the standard input/output library in the program.
2. `void selectionSort(int arr[], int n, int ascending)` - This line declares a function named `selectionSort` that takes an array of integers `arr`, an integer `n` representing the number of elements in the array, and an integer `ascending` representing the sort order. The function returns no value.
3. `int i, j, minIndex, temp;` - This line declares four integer variables `i`, `j`, `minIndex`, and `temp`.
4. `for (i = 0; i < n-1; i++)` - This line starts a for loop that will run `n-1` times. The loop variable `i` is initialized to 0 and incremented by 1 each iteration. The loop will continue as long as `i` is less than `n-1`.
5. `minIndex = i;` - This line sets the value of `minIndex` to the current value of `i`.
6. `for (j = i+1; j < n; j++)` - This line starts a nested for loop that will run `n-i-1` times. The loop variable `j` is initialized to `i+1` and incremented by 1 each iteration. The loop will continue as long as `j` is less than `n`.
7. `if (ascending)` - This line checks the value of `ascending`. If it is true (not 0), the code inside the if statement will run.
8. `if (arr[j] < arr[minIndex])` - This line checks if the value of `arr[j]` is less than the value of `arr[minIndex]`. If it is, the value of `minIndex` is updated to `j`.
9. `else` - This line starts the else clause of the outer if statement. If the value of `ascending` is false (0), the code inside the else statement will run.
10. `if (arr[j] > arr[minIndex])` - This line checks if the value of `arr[j]` is greater than the value of `arr[minIndex]`. If it is, the value of `minIndex` is updated to `j`.
11. `temp = arr[minIndex];` - This line stores the value of `arr[minIndex]` in the variable `temp`.
12. `arr[minIndex] = arr[i];` - This line sets the value of `arr[minIndex]` to the value of `arr[i]`.
13. `arr[i] = temp;` - This line sets the value of `arr[i]` to the value stored in `temp`.
14. `int arr[] = {64, 25, 12, 22, 11};` - This line declares an array of integers `arr` with the values `64, 25, 12, 22, 11`.
15. `int n = sizeof(arr)/sizeof(arr[0]);` - This line declares an integer `n` and sets its value to the number of elements in the array `arr`.
16. `int ascending = 1;` - This line declares an integer `ascending` and sets its value to 1.
17. `selectionSort(arr, n, ascending);` - This line calls the `selectionSort` function with the arguments `arr`, `n`, and `ascending`.
18. `printf("Sorted array: \n");` - This line prints the text `Sorted array:` followed by a newline character.
19. `for (int i=0; i < n; i++)` - This line starts a for loop that will run `n` times. The loop variable `i` is initialized to 0 and incremented by 1 each iteration. The loop will continue as long as `i` is less than `n`.
20. `printf("%d ", arr[i]);` - This line prints the value of `arr[i]` followed by a space character.
21. `return 0;` - This line returns the value 0 to indicate that the program has executed successfully.
*/
