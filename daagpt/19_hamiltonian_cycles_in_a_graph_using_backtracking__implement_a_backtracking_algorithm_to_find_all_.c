write the codes in c following practical for my daa assignement 

Hamiltonian Cycles in a Graph using Backtracking: Implement a backtracking algorithm to find all Hamiltonian cycles in a connected undirected graph.
 Here's an implementation of a backtracking algorithm to find all Hamiltonian cycles in a connected undirected graph in C:
```
#include<stdio.h>
#include<stdbool.h>
 
#define V 5
 
void printSolution(int path[]);
 
/* A utility function to check if the vertex v can be added at index 'pos'
   in the Hamiltonian Cycle constructed so far (stored in 'path[]') */
bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    /* Check if this vertex is an adjacent vertex of the previously
       added vertex. */
    if (graph [ path[pos-1] ][ v ] == 0)
        return false;
 
    /* Check if the vertex has already been included */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 
/* A recursive utility function to solve hamiltonian cycle problem */
bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
    /* base case: If all vertices are included in Hamiltonian Cycle */
    if (pos == V)
    {
        // And if there is an edge from the last included vertex to the
        // first vertex
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return true;
        else
           return false;
    }
 
    /* Try different vertices as a next candidate in Hamiltonian Cycle.
       We don't try for 0 as we included 0 as starting point in hamCycle() */
    for (int v = 1; v < V; v++)
    {
        /* Check if this vertex can be added to Hamiltonian Cycle */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
 
            /* recur to construct rest of the path */
            if (hamCycleUtil (graph, path, pos+1) == true)
                return true;
 
            /* If adding vertex v doesn't lead to a solution,
               then remove it */
            path[pos] = -1;
        }
    }
 
    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
       then return false */
    return false;
}
 
/* This function solves the Hamiltonian Cycle problem using Backtracking.
  It mainly uses hamCycleUtil() to solve the problem. It returns false
  if there is no Hamiltonian Cycle possible, otherwise return true and
  prints the path. Please note that there may be more than one solutions,
  this function prints one of the feasible solutions. */
bool hamCycle(bool graph[V][V])
{
    int *path = malloc(V * sizeof(*path));
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
    /* Let us put vertex 0 as the first vertex in the path. If there is
       a Hamiltonian Cycle, then the path can be started from any point
       of the cycle as the graph is undirected */
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == false )
    {
        printf("\nSolution does not exist");
        return false;
    }
 
    printSolution(path);
    return true;
}
 
/* A utility function to print solution */
void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
 
    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}
 
// Driver program to test above function
int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0}};
 
    // Print the solution
    hamCycle(graph1);
 
    return 0;
}
```
/*
explain the following code 

 Here's an implementation of a backtracking algorithm to find all Hamiltonian cycles in a connected undirected graph in C:
```
#include<stdio.h>
#include<stdbool.h>
 
#define V 5
 
void printSolution(int path[]);
 
/* A utility function to check if the vertex v can be added at index 'pos'
   in the Hamiltonian Cycle constructed so far (stored in 'path[]') */
bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    /* Check if this vertex is an adjacent vertex of the previously
       added vertex. */
    if (graph [ path[pos-1] ][ v ] == 0)
        return false;
 
    /* Check if the vertex has already been included */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 
/* A recursive utility function to solve hamiltonian cycle problem */
bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
    /* base case: If all vertices are included in Hamiltonian Cycle */
    if (pos == V)
    {
        // And if there is an edge from the last included vertex to the
        // first vertex
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return true;
        else
           return false;
    }
 
    /* Try different vertices as a next candidate in Hamiltonian Cycle.
       We don't try for 0 as we included 0 as starting point in hamCycle() */
    for (int v = 1; v < V; v++)
    {
        /* Check if this vertex can be added to Hamiltonian Cycle */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
 
            /* recur to construct rest of the path */
            if (hamCycleUtil (graph, path, pos+1) == true)
                return true;
 
            /* If adding vertex v doesn't lead to a solution,
               then remove it */
            path[pos] = -1;
        }
    }
 
    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
       then return false */
    return false;
}
 
/* This function solves the Hamiltonian Cycle problem using Backtracking.
  It mainly uses hamCycleUtil() to solve the problem. It returns false
  if there is no Hamiltonian Cycle possible, otherwise return true and
  prints the path. Please note that there may be more than one solutions,
  this function prints one of the feasible solutions. */
bool hamCycle(bool graph[V][V])
{
    int *path = malloc(V * sizeof(*path));
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
    /* Let us put vertex 0 as the first vertex in the path. If there is
       a Hamiltonian Cycle, then the path can be started from any point
       of the cycle as the graph is undirected */
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == false )
    {
        printf("\nSolution does not exist");
        return false;
    }
 
    printSolution(path);
    return true;
}
 
/* A utility function to print solution */
void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
 
    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}
 
// Driver program to test above function
int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0}};
 
    // Print the solution
    hamCycle(graph1);
 
    return 0;
}
```
 The code is an implementation of a backtracking algorithm to find all Hamiltonian cycles in a connected undirected graph. The algorithm uses the concept of backtracking to find all possible cycles in the graph. The graph is represented as a 2D boolean array where `graph[i][j]` is `1` if there is an edge between vertex `i` and vertex `j`, and `0` otherwise. The function `hamCycle` is the main function that solves the problem using backtracking. It uses the function `hamCycleUtil` as a helper function to construct the Hamiltonian cycle. The function `isSafe` is a utility function to check if a particular vertex can be added to the Hamiltonian cycle. The function `printSolution` is a utility function to print the Hamiltonian cycle.
*/
