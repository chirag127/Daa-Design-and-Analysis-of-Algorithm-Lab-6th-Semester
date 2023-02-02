write the codes in c following practical for my daa assignement 

Shortest Paths using Dijkstra's Algorithm: Implement Dijkstra's algorithm to find the shortest paths from a given vertex to all other vertices in a weighted connected graph.
 
```
#include <limits.h>
#include <stdio.h>

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
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
  printf("Vertex \t Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0},
                     {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0},
                     {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
                     {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7},
                     {0, 0, 2, 0, 0, 0, 6, 7, 0}};
  dijkstra(graph, 0);
  return 0;
}
```
/*
explain the following code 

 
```
#include <limits.h>
#include <stdio.h>

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
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
  printf("Vertex \t Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0},
                     {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0},
                     {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
                     {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7},
                     {0, 0, 2, 0, 0, 0, 6, 7, 0}};
  dijkstra(graph, 0);
  return 0;
}
```
 The code is an implementation of Dijkstra's algorithm in C. Dijkstra's algorithm is used to find the shortest paths from a given vertex to all other vertices in a weighted connected graph. The `dijkstra` function takes a 2D array `graph` representing the weighted graph and an integer `src` representing the source vertex as input parameters. The function initializes an array `dist` to store the shortest distances from the source vertex to all other vertices and an array `sptSet` to keep track of vertices included in the shortest path tree. The algorithm calculates the shortest distances using a greedy approach and stores the results in the `dist` array. Finally, the results are printed. The `main` function initializes a sample graph and calls the `dijkstra` function with the graph and the source vertex as input parameters.
*/
