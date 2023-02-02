write the codes in c following practical for my daa assignement 

Insertion Sort: Implement the insertion sort algorithm to sort an array in ascending or descending order.

```
#include<stdio.h>
#define MAX_SIZE 100

void insertionsort(int arr[], int n, int order)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        if (order == 0)
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[MAX_SIZE];
    int n, order, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter 0 for ascending order, 1 for descending order: ");
    scanf("%d", &order);
    insertionsort(arr, n, order);
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
```
/*


```
#include<stdio.h> 
```
This line includes the standard input/output library in the code. This library provides functions such as `printf` and `scanf` which are used in the code.

```
#define MAX_SIZE 100
```
This line defines a constant `MAX_SIZE` with the value of 100. This constant is used to define the size of the array.

```
void insertionsort(int arr[], int n, int order)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        if (order == 0)
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
    }
}
```
This is the implementation of the insertion sort algorithm. The function takes three parameters, an array `arr`, an integer `n` representing the size of the array, and an integer `order` representing the order in which the array should be sorted (ascending or descending).

The function starts with a for loop, with `i` starting from 1 and running until `i` is less than `n`. On each iteration of the for loop, the value of `arr[i]` is assigned to `key`. `j` is initialized to `i - 1`.

There is an if-else statement, which checks the value of `order`. If `order` is 0, the while loop runs until `j` is greater than or equal to 0 and `arr[j]` is greater than `key`. In each iteration of the while loop, the value of `arr[j+1]` is assigned the value of `arr[j]`, and `j` is decremented by 1.

If `order` is not 0, the else block runs, which is similar to the if block, but the condition is `j >= 0 && arr[j] < key`.

After the while loop, the value of `key` is assigned to `arr[j+1]`.

```
int main()
{
    int arr[MAX_SIZE];
    int n, order, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter 0 for ascending order, 1 for descending order: ");
    scanf("%d", &order);
    insertionsort(arr, n, order);
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
```
This is the main function of the program. It starts by defining an array `arr` of size `MAX_SIZE`.

`n`, `order`, and `i` are defined as integers.

The program prompts the user to enter the size of the array and stores the value in `n`.

The program then prompts the user to enter the elements of the array and stores them in `arr`.

The program then prompts the user to enter either 0 for ascending order or 1 for descending order and stores the value in `order`.

The `insertionsort` function is called with the parameters `arr`, `n`, and `order`.

The sorted array is then printed.

Finally, the function returns 0.
*/
