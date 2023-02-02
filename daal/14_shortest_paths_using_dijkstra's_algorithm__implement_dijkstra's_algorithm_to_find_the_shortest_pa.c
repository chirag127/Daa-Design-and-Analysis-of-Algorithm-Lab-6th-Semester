write the c code for practical for my daa assignement 

Shortest Paths using Dijkstra's Algorithm: Implement Dijkstra's algorithm to find the shortest paths from a given vertex to all other vertices in a weighted connected graph.

```
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9

int minDistance(int dist[], bool sptSet[]) {
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;
  return min_index;
}

void dijkstra(int graph[V][V], int src) {
  int dist[V];
  bool sptSet[V];
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;
  dist[src] = 0;
  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;
    for (int v = 0; v < V; v++)
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
  printf("Vertex\t Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d\t\t %d\n", i, dist[i]);
}

int main() {
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                     {4, 0, 8, 0, 0, 0, 0, 11, 0},
                     {0, 8, 0, 7, 0, 4, 0, 0, 2},
                     {0, 0, 7, 0, 9, 14, 0, 0, 0},
                     {0, 0, 0, 9, 0, 10, 0, 0, 0},
                     {0, 0, 4, 14, 10, 0, 2, 0, 0},
                     {0, 0, 0, 0, 0, 2, 0, 1, 6},
                     {8, 11, 0, 0, 0, 0, 1, 0, 7},
                     {0, 0, 2, 0, 0, 0, 6, 7, 0}
                    };
  dijkstra(graph, 0);
  return 0;
}
```
/*
 

```
#include <stdio.h>
```
This line includes the standard input/output library in the program.

```
#include <stdlib.h>
```
This line includes the standard library in the program.

```
#include <limits.h>
```
This line includes the limits library in the program.

```
#define V 9
```
This line defines the constant `V` as 9.

```
int minDistance(int dist[], bool sptSet[]) {
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;
  return min_index;
}
```
This function `minDistance` takes two arrays, `dist` and `sptSet`, as input and returns the index of the vertex with the minimum distance value. The function starts by initializing `min` to the maximum value of an `int` and `min_index` to 0. Then it iterates over all vertices, checking if the vertex is not in the shortest path tree and its distance value is less than `min`. If so, it updates `min` and `min_index`. The function returns `min_index` at the end.

```
void dijkstra(int graph[V][V], int src) {
  int dist[V];
  bool sptSet[V];
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;
  dist[src] = 0;
  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;
    for (int v = 0; v < V; v++)
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
  printf("Vertex\t Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d\t\t %d\n", i, dist[i]);
}
```
This function `dijkstra` implements Dijkstra's algorithm to find the shortest paths from a given vertex to all other vertices in a weighted connected graph. The function takes two inputs, an adjacency matrix `graph` and the source vertex `src`. It starts by initializing the `dist` array with the maximum value of an `int` and the `sptSet` array with `false`. It sets the distance of the source vertex to 0. The function then iterates `V-1` times, each time finding the vertex with the minimum distance value that is not in the shortest path tree using the `minDistance` function. The function updates the distance values of the vertices adjacent to the selected vertex if the new distance value is less than the current distance value. Finally, the function prints the distance values of all vertices.

```
int main() {
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                     {4, 0, 8, 0, 0, 0, 0, 11, 0},
                     {0, 8, 0, 7, 0, 4, 0, 0, 2},
                     {0, 0, 7, 0, 9, 14, 0, 0, 0},
                     {0, 0, 0, 9, 0, 10, 0, 0, 0},
                     {0, 0, 4, 14, 10, 0, 2, 0, 0},
                     {0, 0, 0, 0, 0, 2, 0, 1, 6},
                     {8, 11, 0, 0, 0, 0, 1, 0, 7},
                     {0, 0, 2, 0, 0, 0, 6, 7, 0}
                    };
  dijkstra(graph, 0);
  return 0;
}
```
This is the main function of the program. It initializes a weighted connected graph `graph` and calls the `dijkstra` function with `graph` and the source vertex 0. The function returns 0 at the end.
*/
/*
 This code implements Dijkstra's algorithm to find the shortest path from a given vertex to all other vertices in a weighted connected graph.
*/
