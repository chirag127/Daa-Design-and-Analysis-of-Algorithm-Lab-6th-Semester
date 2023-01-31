// write the c code for the 0/1 knapsack for the dyanamic and greedy algorithm
#include<stdio.h>
int max(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

int greedy(int *w, int *v, int n, int W){
    int i, j, k
int dynamic(int n, int w[], int v[], int W)
{
    int i, j;
    int k[n+1][W+1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                k[i][j] = 0;
            }
            else if (w[i-1] <= j)
            {
                k[i][j] = max(v[i-1] + k[i-1][j-w[i-1]], k[i-1][j]);
            }
            else
            {
                k[i][j] = k[i-1][j];
            }
        }
    }
    return k[n][W];
}

int main(int argc, char *argv[])
{
    int	n = 3;
    int w[] = {2, 3, 4};
    int v[] = {3, 4, 5};
    int W = 5;

    printf("%d\n", dynamic(n, w, v, W));
    return 0;
} 