write the codes in c following practical for my daa assignement 

Minimum Cost Spanning Tree using Prim's Algorithm: Implement Prim's algorithm to find the minimum cost spanning tree of a connected undirected graph.
 Here's a sample implementation of Prim's algorithm in C:

#include<stdio.h>
#define MAX 100
#define infinity 9999
#define NIL -1

int n, cost[MAX][MAX];
int prim(int source)
{
    int i, j, k, u, v, min_cost=0;
    int parent[MAX], key[MAX];
    bool mst_set[MAX];
    for(i=0; i<n; i++)
    {
        key[i]=infinity;
        mst_set[i]=false;
    }
    key[source]=0;
    parent[source]=NIL;
    for(i=0; i<n-1; i++)
    {
        u=min_key(key, mst_set);
        mst_set[u]=true;
        for(v=0; v<n; v++)
        {
            if(cost[u][v] && mst_set[v]==false && cost[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=cost[u][v];
            }
        }
    }
    for(i=1; i<n; i++)
    {
        min_cost+=cost[i][parent[i]];
    }
    return min_cost;
}

int min_key(int key[], bool mst_set[])
{
    int i, min=infinity, min_index;
    for(i=0; i<n; i++)
    {
        if(mst_set[i]==false && key[i]<min)
        {
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}

void main()
{
    int source, minimum_cost;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter the source node: ");
    scanf("%d", &source);
    minimum_cost=prim(source);
    printf("Minimum cost: %d", minimum_cost);
}
/*
 

#include<stdio.h>
This line includes the standard input and output header file in the program.

#define MAX 100
#define infinity 9999
#define NIL -1
These lines define the maximum number of nodes in the graph as 100, the value of infinity as 9999, and NIL as -1.

int n, cost[MAX][MAX];
These lines declare the number of nodes in the graph and the cost matrix, which stores the cost of each edge in the graph.

int prim(int source)
This line declares the function prim, which takes the source node as an input and returns the minimum cost of the minimum cost spanning tree.

{
    int i, j, k, u, v, min_cost=0;
    int parent[MAX], key[MAX];
    bool mst_set[MAX];
    for(i=0; i<n; i++)
    {
        key[i]=infinity;
        mst_set[i]=false;
    }
    key[source]=0;
    parent[source]=NIL;
    for(i=0; i<n-1; i++)
    {
        u=min_key(key, mst_set);
        mst_set[u]=true;
        for(v=0; v<n; v++)
        {
            if(cost[u][v] && mst_set[v]==false && cost[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=cost[u][v];
            }
        }
    }
    for(i=1; i<n; i++)
    {
        min_cost+=cost[i][parent[i]];
    }
    return min_cost;
}

This block of code implements the Prim's algorithm.
- The arrays "key" and "parent" are used to store the minimum cost of reaching each node and the parent node of each node, respectively.
- The array "mst_set" is used to keep track of nodes that are included in the minimum cost spanning tree.
- The for loop sets the initial values of "key" and "mst_set" for all nodes.
- The for loop with i<n-1 implements the main part of the Prim's algorithm.
  - The function "min_key" is called to find the node with the minimum key value that is not yet included in the minimum cost spanning tree.
  - The node is then marked as included in the minimum cost spanning tree.
  - The for loop updates the key values and parent nodes of all nodes that are adjacent to the node just included in the minimum cost spanning tree.
- The for loop calculates the minimum cost of the minimum cost spanning tree by summing up the costs of all edges in the tree.

int min_key(int key[], bool mst_set[])
This line declares the function "min_key", which takes the arrays "key" and "mst_set" as inputs and returns the index of the node with the minimum key value that is not yet included in the minimum cost spanning tree.

{
    int i, min=infinity, min_index;
    for(i=0; i<n; i++)
    {
        if(mst_set[i]==false && key[i]<min)
        {
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}

This block of code implements the "min_key" function.
- The for loop iterates through all nodes and finds the node with the minimum key value that is not yet included in the minimum cost spanning tree.
- The index of the node is returned as the result of the function.

void main()
{
    int source, minimum_cost;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter the source node: ");
    scanf("%d", &source);
    minimum_cost=prim(source);
    printf("Minimum cost: %d", minimum_cost);
}

This block of code implements the main function of the program.
- The number of nodes in the graph and the cost matrix are inputted by the user.
- The source node is also inputted by the user.
- The minimum cost of the minimum cost spanning tree is calculated by calling the "prim" function with the source node as an input.
- The minimum cost is then outputted to the user.
*/
