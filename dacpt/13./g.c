#include <stdio.h>
#include <stdbool.h>

// A utility function to return maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i;
    int w;

    // Builds a table K[][] in bottom up manner
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // stores the result of Knapsack
    int res = K[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1][w-wt[i-1]])
        if (res == K[i - 1][w])
            continue;
        else
        {

            // This item is included.
            printf("%d ", wt[i - 1]);

            // Since this weight is included its value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }

    return K[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
