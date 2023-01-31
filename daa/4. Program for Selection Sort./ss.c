// C program for implementation of selection sort
#include <stdio.h>

void s(int *xp, int *yp)
{
    int t = *xp;
    *xp = *yp;
    *yp = t;
}


void ss(int a[], int n)
{
    int i, j, mi;
    for (i = 0; i < n-1; i++)
    {
        mi = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[mi])
            mi = j;
        s(&a[mi], &a[i]);
    }

}

void pa(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a)/sizeof(a[0]);
    ss(a, n);
    printf("Sorted array: \n");
    pa(a, n);
    return 0;
}