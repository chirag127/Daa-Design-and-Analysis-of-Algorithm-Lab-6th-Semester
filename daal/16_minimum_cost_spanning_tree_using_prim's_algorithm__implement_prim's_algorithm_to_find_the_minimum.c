write the c code for practical for my daa assignement 

Minimum Cost Spanning Tree using Prim's Algorithm: Implement Prim's algorithm to find the minimum cost spanning tree of a connected undirected graph.

```
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

int minKey(int key[], bool mstSet[]) {
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;
  return min_index;
}

void printMST(int parent[], int graph[V][V]) {
  printf("Edge \tWeight\n");
  for (int i = 1; i < V; i++)
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
  int parent[V];
  int key[V];
  bool mstSet[V];
  for (int i = 0; i < V; i++)
    key[i] = INT_MAX, mstSet[i] = false;
  key[0] = 0;
  parent[0] = -1;
  for (int count = 0; count < V - 1; count++) {
    int u = minKey(key, mstSet);
    mstSet[u] = true;
    for (int v = 0; v < V; v++)
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        parent[v] = u, key[v] = graph[u][v];
  }
  printMST(parent, graph);
}

int main() {
  int graph[V][V] = {{0, 2, 0, 6, 0},
                     {2, 0, 3, 8, 5},
                     {0, 3, 0, 0, 7},
                     {6, 8, 0, 0, 9},
                     {0, 5, 7, 9, 0}};
  primMST(graph);
  return 0;
}
```
/*


1. `#include <stdio.h>`: This line includes the standard input/output library in the program.
2. `#include <stdlib.h>`: This line includes the standard library in the program.
3. `#include <limits.h>`: This line includes the limits library in the program.
4. `#define V 5`: This line defines a constant `V` with a value of 5. This constant is used to represent the number of vertices in the graph.
5. `int minKey(int key[], bool mstSet[])`: This function takes two arrays as inputs, `key` and `mstSet`, and returns the index of the minimum key value that is not yet included in the minimum spanning tree (MST).
6. `void printMST(int parent[], int graph[V][V])`: This function takes two arrays as inputs, `parent` and `graph`, and prints the edges and weights of the MST.
7. `void primMST(int graph[V][V])`: This function takes a 2D array `graph` as input and implements Prim's algorithm to find the MST.
8. `int main()`: This is the main function of the program. It initializes a graph using a 2D array and calls the `primMST` function to find the MST.
9. `int graph[V][V] = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};`: This line initializes a 2D array `graph` as an adjacency matrix representation of a graph.
10. `primMST(graph)`: This line calls the `primMST` function and passes the `graph` array as an argument.
11. `return 0;`: This line returns 0 to indicate successful termination of the program.
*/
/*
 

1. `#include <stdio.h>`: This line helps us to use the computer to print things on the screen.
2. `#include <stdlib.h>`: This line helps us use some extra tools that can make our program work better.
3. `#include <limits.h>`: This line helps us use the biggest and smallest numbers that the computer can handle.
4. `#define V 5`: This line sets the number of vertices in the graph to 5.
5. `int minKey(int key[], bool mstSet[])`: This function helps us find the smallest number in the `key` array that is not yet in the minimum spanning tree.
6. `void printMST(int parent[], int graph[V][V])`: This function helps us print the edges and weights of the minimum spanning tree.
7. `void primMST(int graph[V][V])`: This function helps us find the minimum spanning tree using Prim's algorithm.
8. `int main()`: This is the main part of the program. It starts the program and sets up the graph.
9. `int graph[V][V] = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};`: This line sets up the graph using a 2D array.
10. `primMST(graph)`: This line calls the function that finds the minimum spanning tree.
11. `return 0;`: This line ends the program and tells the computer that everything worked well.
*/
