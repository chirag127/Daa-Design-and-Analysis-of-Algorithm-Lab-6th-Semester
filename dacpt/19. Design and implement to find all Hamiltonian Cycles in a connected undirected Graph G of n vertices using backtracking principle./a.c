#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool isSafe(int v, int graph[][MAX], int path[], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
    {
        return false;
    }
    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
        {
            return false;
        }
    }
    return true;
}

bool hamiltonianCycleUtil(int graph[][MAX], int path[], int pos, int n)
{
    if (pos == n)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1, n) == true)
            {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}

bool hamiltonianCycle(int graph[][MAX], int n)
{
    int path[n];
    for (int i = 0; i < n; i++)
    {
        path[i] = -1;
    }
    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1, n) == false)
    {
        printf("\nSolution does not exist\n");
        return false;
    }
    printf("\nSolution exists\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", path[i]);
    }
    printf("%d ", path[0]);
    return true;
}

int main()
{
    int n, graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    hamiltonianCycle(graph, n);
    return 0;
}
