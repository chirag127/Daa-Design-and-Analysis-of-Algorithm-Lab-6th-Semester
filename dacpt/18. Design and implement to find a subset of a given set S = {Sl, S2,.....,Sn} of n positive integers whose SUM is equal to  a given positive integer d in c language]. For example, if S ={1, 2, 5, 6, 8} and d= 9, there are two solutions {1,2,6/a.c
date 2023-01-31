#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool subsetSum(int set[], int n, int sum)
{
    bool subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        subset[i][0] = true;
    }
    for (int i = 1; i <= sum; i++)
    {
        subset[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
            {
                subset[i][j] = subset[i - 1][j];
            }
            if (j >= set[i - 1])
            {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }
    }
    return subset[n][sum];
}

int main()
{
    int set[MAX], n, d, sum = 0;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
        sum += set[i];
    }
    printf("Enter the value of d: ");
    scanf("%d", &d);
    if (sum < d || (sum + d) % 2 == 1)
    {
        printf("No subset found whose sum is equal to d\n");
        return 0;
    }
    sum = (sum + d) / 2;
    if (subsetSum(set, n, sum))
    {
        printf("A subset with the given sum d exists\n");
    }
    else
    {
        printf("No subset found whose sum is equal to d\n");
    }
    return 0;
}
