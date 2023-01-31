// write a `program for the insertion sort in c`
#include <stdio.h>

void is(int a[], int n) /* function to sort an aay with insertion sort */
{
    int i, j, t;
    for (i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;

        while(j>=0 && t <= a[j])  /* Move the elements greater than t to one position ahead from their current position*/
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = t;
    }
}

void pa(int a[], int n) /* function to print the array */
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[] = { 12, 31, 25, 8, 32, 17 };
    int n = sizeof(a) / sizeof(a[0]);
    is(a, n);
    printf("\nAfter sorting array elements are - \n");
    pa(a, n);

    return 0;
}
