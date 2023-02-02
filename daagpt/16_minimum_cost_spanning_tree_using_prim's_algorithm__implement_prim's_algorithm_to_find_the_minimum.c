write the codes in c following practical for my daa assignement 

Minimum Cost Spanning Tree using Prim's Algorithm: Implement Prim's algorithm to find the minimum cost spanning tree of a connected undirected graph.
 
```
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100
#define E 200

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph);
}

int main()
{
    int graph[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    primMST(graph);
    return 0;
}
```
/*
explain the following code 

 
```
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100
#define E 200

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph);
}

int main()
{
    int graph[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    primMST(graph);
    return 0;
}
```
 This code implements Prim's algorithm to find the minimum cost spanning tree of a connected undirected graph. The `primMST` function takes an adjacency matrix `graph` representing the graph as an argument. The function initializes an array `key` to store the minimum weight of each vertex, an array `parent` to store the parent of each vertex in the minimum spanning tree, and a boolean array `mstSet` to keep track of which vertices are included in the minimum spanning tree. The function then finds the vertex with the minimum key value that is not included in the minimum spanning tree, adds it to the minimum spanning tree, and updates the key values of its adjacent vertices. This process is repeated until all vertices are included in the minimum spanning tree. The `printMST` function prints the edges and their weights of the minimum spanning tree. The `main` function takes the input of the adjacency matrix of the graph, calls the `primMST` function and prints the minimum cost spanning tree.
*/
