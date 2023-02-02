write the c code for practical for my daa assignement 

Insertion Sort: Implement the insertion sort algorithm to sort an array in ascending or descending order.

```
#include<stdio.h>

void insertionSort(int arr[], int n, int ascending) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    if (ascending) {
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    } else {
      while (j >= 0 && arr[j] < key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int ascending = 1; // set to 0 for descending sort
  insertionSort(arr, n, ascending);
  int i;
  printf("Sorted array: \n");
  for (i=0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}
```
/*
 
```
#include<stdio.h>
```
This line includes the standard input/output library in the C program.

```
void insertionSort(int arr[], int n, int ascending) {
```
This line declares the function "insertionSort" which takes in an integer array "arr", an integer "n" which represents the size of the array, and an integer "ascending" which determines the order in which the array is sorted. The function returns no value (declared as "void").

```
  int i, key, j;
```
These lines declare three integer variables "i", "key", and "j".

```
  for (i = 1; i < n; i++) {
```
This line starts a for loop which iterates "i" from 1 to n-1.

```
    key = arr[i];
    j = i - 1;
```
These lines assign the value of "arr[i]" to "key" and "i-1" to "j".

```
    if (ascending) {
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    } else {
      while (j >= 0 && arr[j] < key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    }
```
This block of code checks the value of "ascending". If "ascending" is true, the while loop inside the "if" statement will run. The while loop continues as long as "j" is greater than or equal to 0 and "arr[j]" is greater than "key". Within the while loop, "arr[j+1]" is assigned the value of "arr[j]" and "j" is decremented by 1. If "ascending" is false, the while loop inside the "else" statement will run. The while loop continues as long as "j" is greater than or equal to 0 and "arr[j]" is less than "key". Within the while loop, "arr[j+1]" is assigned the value of "arr[j]" and "j" is decremented by 1.

```
    arr[j + 1] = key;
  }
}
```
This line assigns the value of "key" to "arr[j+1]".

```
int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int ascending = 1; // set to 0 for descending sort
```
These lines declare an integer array "arr" with values {12, 11, 13, 5, 6}, an integer "n" which is assigned the size of the array, and an integer "ascending" which is set to 1.

```
  insertionSort(arr, n, ascending);
```
This line calls the "insertionSort" function with the arguments "arr", "n", and "ascending".

```
  int i;
  printf("Sorted array: \n");
  for (i=0; i < n; i++)
    printf("%d ", arr[i]);
```
These lines declare an integer "i", print the message "Sorted array:", and use a for loop to print each element of the sorted array "arr".

```
  return 0;
}
```
This line returns 0 from the "main" function.
*/
/*


```
#include<stdio.h>
```
This line is like asking for a tool from the toolbox to use in the program.

```
void insertionSort(int arr[], int n, int ascending) {
```
This line is like making a plan for sorting the numbers in the array either in ascending or descending order.

```
  int i, key, j;
```
These lines are like making three helpers to sort the numbers.

```
  for (i = 1; i < n; i++) {
```
This line is like telling the first helper to start sorting the numbers one by one.

```
    key = arr[i];
    j = i - 1;
```
These lines are like giving the second and third helpers the current number and the previous number to be sorted.

```
    if (ascending) {
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    } else {
      while (j >= 0 && arr[j] < key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
    }
```
This block of code is like checking if the numbers should be sorted in ascending or descending order. If it's ascending, the second and third helpers will sort the numbers by comparing them and putting the smaller one first. If it's descending, the second and third helpers will sort the numbers by comparing them and putting the bigger one first.

```
    arr[j + 1] = key;
  }
}
```
This line is like putting the current number in the right place after sorting.

```
int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int ascending = 1; // set to 0 for descending sort
```
These lines are like making an array of numbers to be sorted and deciding if it should be sorted in ascending or descending order.

```
  insertionSort(arr, n, ascending);
```
This line is like using the plan to sort the numbers.

```
  int i;
  printf("Sorted array: \n");
  for (i=0; i < n; i++)
    printf("%d ", arr[i]);
```
These lines are like printing the sorted numbers one by one.

```
  return 0;
}
```
This line is like telling the program that the sorting is done and it can stop now.
*/
