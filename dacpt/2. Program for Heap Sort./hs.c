// write program for the heap sort in c

#include<stdio.h>

int main()
{
    int  a[3]={4,3,5}, n, i, j, t;
    n=3;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > t)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
    printf("Sorted elements are: ");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    return 0;
}