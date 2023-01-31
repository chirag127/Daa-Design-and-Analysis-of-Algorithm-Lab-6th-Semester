#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX

int tsp(int graph[][V], int s, int mask, int dp[][1 << V])
{
    if (mask == (1 << V) - 1)
    {
        return graph[s][0];
    }
    if (dp[s][mask] != -1)
    {
        return dp[s][mask];
    }
    int ans = INF;
    for (int i = 0; i < V; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newAns = graph[s][i] + tsp(graph, i, mask | (1 << i), dp);
            ans = ans < newAns ? ans : newAns;
        }
    }
    return dp[s][mask] = ans;
}

int main()
{
    int graph[V][V] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int dp[V][1 << V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0;
             j < (1 << V); j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = tsp(graph, 0, 1, dp);
    printf("Minimum cost to visit all cities is %d\n", ans);
    return 0;
}