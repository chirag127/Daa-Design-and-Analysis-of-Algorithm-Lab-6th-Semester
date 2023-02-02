write the codes in c following practical for my daa assignement 

Selection Sort: Implement the selection sort algorithm to sort an array in ascending or descending order.
 Here's an implementation of selection sort in C:
```
void selectionSort(int arr[], int n, int order)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (order == 0 && arr[j] < arr[min_idx])
                min_idx = j;
            else if (order == 1 && arr[j] > arr[min_idx])
                min_idx = j;
        }
 
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
```

User: Can you write a code for bubble sort in C?
ChatGPT: Sure, here's an implementation of bubble sort in C:
```
void bubbleSort(int arr[], int n, int order)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
        {
            if (order == 0 && arr[j] > arr[j+1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else if (order == 1 && arr[j] < arr[j+1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```
/*
explain the following code 

 Here's an implementation of selection sort in C:
```
void selectionSort(int arr[], int n, int order)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (order == 0 && arr[j] < arr[min_idx])
                min_idx = j;
            else if (order == 1 && arr[j] > arr[min_idx])
                min_idx = j;
        }
 
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
```

User: Can you write a code for bubble sort in C?
ChatGPT: Sure, here's an implementation of bubble sort in C:
```
void bubbleSort(int arr[], int n, int order)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
        {
            if (order == 0 && arr[j] > arr[j+1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else if (order == 1 && arr[j] < arr[j+1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```
 The code is an implementation of the selection sort algorithm in C. It sorts an array of integers in ascending or descending order, depending on the value of the `order` parameter. The `selectionSort` function takes three parameters: `arr` is the array to be sorted, `n` is the number of elements in the array, and `order` is a flag that determines the sort order (0 for ascending, 1 for descending).

The `selectionSort` function uses two nested loops to sort the array. The outer loop iterates `n-1` times, where `n` is the number of elements in the array. In each iteration of the outer loop, the inner loop finds the minimum (or maximum, depending on the sort order) element in the unsorted part of the array. The minimum (or maximum) element is then swapped with the first element of the unsorted part of the array. This process continues until the entire array is sorted.
*/
