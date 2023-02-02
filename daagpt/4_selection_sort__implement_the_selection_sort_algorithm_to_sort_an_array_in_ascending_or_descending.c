
#include<stdio.h>
#define MAX_SIZE 100

void selectionSort(int arr[], int n, int order) {
  int i, j, min_idx, temp;
  for (i = 0; i < n-1; i++) {
    min_idx = i;
    for (j = i+1; j < n; j++) {
      if (order == 0 && arr[j] < arr[min_idx])
        min_idx = j;
      else if (order == 1 && arr[j] > arr[min_idx])
        min_idx = j;
    }
    temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int arr[MAX_SIZE];
  int n, order, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i=0; i<n; i++)
    scanf("%d", &arr[i]);
  printf("Enter 0 for ascending order, 1 for descending order: ");
  scanf("%d", &order);
  selectionSort(arr, n, order);
  printf("Sorted array: \n");
  for (i=0; i<n; i++)
    printf("%d\n", arr[i]);
  return 0;
}
/*


```
#include<stdio.h>
```
This line includes the standard input/output library in C.

```
#define MAX_SIZE 100
```
This line defines a constant `MAX_SIZE` with value 100. It is used to set the maximum size of the array.

```
void selectionSort(int arr[], int n, int order) {
  int i, j, min_idx, temp;
```
This line declares a function `selectionSort` that takes three parameters: an integer array `arr`, an integer `n` representing the number of elements in the array, and an integer `order` representing the ordering of the array (0 for ascending and 1 for descending). The function declares four integer variables `i`, `j`, `min_idx`, and `temp`.

```
  for (i = 0; i < n-1; i++) {
    min_idx = i;
```
This line starts a for loop that iterates `n-1` times. The variable `min_idx` is initialized to `i` at the beginning of each iteration.

```
    for (j = i+1; j < n; j++) {
      if (order == 0 && arr[j] < arr[min_idx])
        min_idx = j;
      else if (order == 1 && arr[j] > arr[min_idx])
        min_idx = j;
    }
```
This line starts a nested for loop that iterates from `i+1` to `n-1`. The purpose of this loop is to find the index of the minimum (or maximum, depending on the value of `order`) element in the array. The variable `min_idx` is updated if a smaller (or larger) element is found.

```
    temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
```
This block of code swaps the element at index `i` with the element at index `min_idx`.

```
int main() {
  int arr[MAX_SIZE];
  int n, order, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i=0; i<n; i++)
    scanf("%d", &arr[i]);
  printf("Enter 0 for ascending order, 1 for descending order: ");
  scanf("%d", &order);
  selectionSort(arr, n, order);
  printf("Sorted array: \n");
  for (i=0; i<n; i++)
    printf("%d\n", arr[i]);
  return 0;
}
```
This is the main function of the program. It declares an array `arr` of size `MAX_SIZE`, three integers `n`, `order`, and `i`, and uses `printf` and `scanf` to read the number of elements, the elements of the array, and the ordering of the array. The function then calls the `selectionSort` function to sort the array and prints the sorted array. The function returns 0 to indicate that the program has executed successfully.
*/
