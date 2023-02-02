write the codes in c following practical for my daa assignement 

Quick Sort: Implement the quick sort algorithm to sort an array in ascending or descending order.
 

```
#include<stdio.h>

void quickSort(int arr[], int left, int right) {
   int i, j, pivot, temp;
   if (left < right) {
      pivot = left;
      i = left;
      j = right;
      while (i < j) {
         while (arr[i] <= arr[pivot] && i < right)
            i++;
         while (arr[j] > arr[pivot])
            j--;
         if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
      temp = arr[pivot];
      arr[pivot] = arr[j];
      arr[j] = temp;
      quickSort(arr, left, j-1);
      quickSort(arr, j+1, right);
   }
}

int main() {
   int arr[100], num, i;
   printf("Enter number of elements in the array: ");
   scanf("%d", &num);
   printf("Enter elements of the array: ");
   for (i = 0; i < num; i++)
      scanf("%d", &arr[i]);
   quickSort(arr, 0, num-1);
   printf("Sorted array: ");
   for (i = 0; i < num; i++)
      printf("%d ", arr[i]);
   return 0;
}
```
