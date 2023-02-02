write the codes in c following practical for my daa assignement 

Quick Sort Time Complexity Analysis: Implement the quick sort algorithm and analyze its time complexity for varying values of n (number of elements in the array). Plot a graph to show the relationship between the time taken and n.

```
#include<stdio.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i=0; i<n; i++)
    {
        arr[i] = rand() % 100;
    }
    clock_t t;
    t = clock();
    quickSort(arr, 0, n-1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Quick sort took %f seconds to sort %d elements\n", time_taken, n);
    return 0;
}
```
To plot the graph, you can modify the code to store the values of `n` and `time_taken` for each iteration in two separate arrays, and then use a plotting library (e.g. matplotlib in Python) to plot the graph.
/*


This is a program to implement the quick sort algorithm and analyze its time complexity.

```
#include<stdio.h>
#include<time.h>
```
- These are header files that are included to use standard input/output functions (`printf`, `scanf`) and time functions (`clock`, `CLOCKS_PER_SEC`).

```
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
```
- `swap` is a function that takes two pointers to integers as arguments and swaps their values.

```
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
```
- `partition` is a function that takes an array `arr`, and two indices `low` and `high` as arguments.
- It selects the last element of the array as the pivot.
- It uses two indices `i` and `j` to partition the array into two parts: elements less than or equal to pivot, and elements greater than pivot.
- `i` starts at `low - 1` and `j` starts at `low`.
- If `arr[j]` is less than or equal to the pivot, `i` is incremented and `arr[i]` and `arr[j]` are swapped.
- When `j` reaches `high - 1`, the pivot is swapped with `arr[i + 1]` and `i + 1` is returned as the pivot index.

```
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```
- `quickSort` is a recursive function that sorts the array `arr` using the quick sort algorithm.
- If `low` is less than `high`, the function calls `partition` to get the pivot index `pi`.
- It then calls itself recursively on the sub-arrays `arr[low, pi - 1]` and `arr[pi + 1, high]` to sort the elements.

```
int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i=0; i<n; i++)
    {
        arr[i] = rand() % 100;
    }
    clock_t t;
    t = clock();
    quickSort(arr, 0, n-1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Quick sort took %f seconds to sort %d elements\n", time_taken, n);
    return 0;
}
```
- `main` is the main function of the program.
- It prompts the user to enter the number of elements `n` to be sorted.
- It then initializes an array `arr` of size `n` with random values between 0 and 99.
- It measures the time taken to sort the array using the `clock` function and calculates the time taken in seconds.
- It finally prints the time taken and the number of elements sorted.
*/
