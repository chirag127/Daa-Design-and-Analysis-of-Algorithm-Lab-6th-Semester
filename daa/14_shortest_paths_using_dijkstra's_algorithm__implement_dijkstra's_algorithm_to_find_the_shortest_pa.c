write the codes in c following practical for my daa assignement 

Shortest Paths using Dijkstra's Algorithm: Implement Dijkstra's algorithm to find the shortest paths from a given vertex to all other vertices in a weighted connected graph.
 Here's an implementation of Dijkstra's Algorithm in C:

```
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define true 1
#define false 0

int n, m;  // n: number of vertices, m: number of edges
int dist[MAX];  // dist[i]: shortest distance from the source vertex to i
int prev[MAX];  // prev[i]: previous vertex of i on the shortest path from the source to i
int visited[MAX];  // visited[i]: true if i is visited, false otherwise
int graph[MAX][MAX];  // graph[i][j]: weight of the edge (i, j), INT_MAX if there is no edge

void dijkstra(int start) {
  int i, v, w;

  // Initialize
  for (i = 0; i < n; i++) {
    dist[i] = INT_MAX;
    prev[i] = -1;
    visited[i] = false;
  }
  dist[start] = 0;

  // Dijkstra's algorithm
  for (i = 0; i < n; i++) {
    v = min_distance(dist, visited);
    visited[v] = true;

    for (w = 0; w < n; w++) {
      if (!visited[w] && graph[v][w] != INT_MAX && dist[v] + graph[v][w] < dist[w]) {
        dist[w] = dist[v] + graph[v][w];
        prev[w] = v;
      }
    }
  }
}

int min_distance(int dist[], int visited[]) {
  int i, min_index, min_value = INT_MAX;

  for (i = 0; i < n; i++) {
    if (!visited[i] && dist[i] < min_value) {
      min_value = dist[i];
      min_index = i;
    }
  }

  return min_index;
}

int main() {
  int i, j, start, end, weight;

  // Input graph
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      graph[i][j] = INT_MAX;
    }
  }
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &start, &end, &weight);
    graph[start][end] = weight;
  }

  // Compute shortest paths
  dijkstra(0);  // Start from vertex 0

  // Output shortest paths
  for (i = 0; i < n; i++) {
    printf("%d %d\n", i, dist[i]);
  }

  return 0;
}
```
/*


- `#include <stdio.h>`: This line includes the standard input/output library in the code.
- `#include <stdlib.h>`: This line includes the standard library in the code.
- `#include <limits.h>`: This line includes the limits library in the code, which provides information about the maximum and minimum values of various data types.
- `#define MAX 100`: This line defines a constant `MAX` with a value of 100. This is used to define the size of arrays.
- `#define true 1`: This line defines a constant `true` with a value of 1. This is used to represent a boolean value `true`.
- `#define false 0`: This line defines a constant `false` with a value of 0. This is used to represent a boolean value `false`.
- `int n, m;`: These two variables represent the number of vertices and edges in the graph, respectively.
- `int dist[MAX];`: This array `dist` stores the shortest distance from the source vertex to each vertex in the graph.
- `int prev[MAX];`: This array `prev` stores the previous vertex of each vertex on the shortest path from the source to that vertex.
- `int visited[MAX];`: This array `visited` stores a boolean value indicating whether each vertex has been visited or not.
- `int graph[MAX][MAX];`: This two-dimensional array `graph` stores the weights of the edges in the graph. If there is no edge between two vertices, the weight is set to `INT_MAX`.
- `void dijkstra(int start)`: This function implements Dijkstra's algorithm to find the shortest paths from the source vertex `start` to all other vertices in the graph.
- `int min_distance(int dist[], int visited[])`: This function finds the index of the vertex with the minimum distance that has not been visited yet.
- `int main()`: This is the main function of the program. It inputs the graph, computes the shortest paths using `dijkstra()`, and outputs the shortest paths.
*/
