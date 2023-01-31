//  Program for Recursive Binary & Linear Search.

#include <stdio.h>

int binary_search(int a[], int low, int high, int key)
{
    int mid;
    if (low > high)
        return -1;
    mid = (low + high) / 2;
    if (key == a[mid])
        return mid;
    else if (key < a[mid])
        return binary_search(a, low, mid - 1, key);
    else
        return binary_search(a, mid + 1, high, key);
}

int linear_search(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int a[100], n, i, key, pos;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the key : ");
    scanf("%d", &key);

    printf("enter search type 1 for binary search and 2 for linear search : ");
    scanf("%d", &i);

    if (i == 1)
        pos = binary_search(a, 0, n - 1, key);
    else
        pos = linear_search(a, n, key);

    if (pos == -1)
        printf("Key not found");

    else

        printf("Key found at position %d", pos + 1);
    return 0;

}