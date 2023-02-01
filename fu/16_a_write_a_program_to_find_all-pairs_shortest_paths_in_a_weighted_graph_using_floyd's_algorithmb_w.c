############################################################

(try to answer in C) 
(a) Write a program to find all-pairs shortest paths in a weighted graph using Floyd's algorithm.(b) Write a program to solve the Travelling Salesman Problem using dynamic programming.



(a) Here's an implementation of Floyd's algorithm in C for finding all-pairs shortest paths in a weighted graph:

```
#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX

void floyd(int graph[][V]) {
  int dist[V][V];
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      dist[i][j] = graph[i][j];
    }
  }
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  printf("The following matrix shows the shortest distances between every pair of vertices\n");
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF) {
        printf("%7s", "INF");
      } else {
        printf("%7d", dist[i][j]);
      }
    }
    printf("\n");
  }
}

int main() {
  int graph[V][V] = { {0,   5,  INF, 10},
                      {INF, 0,   3, INF},
                      {INF, INF, 0,   1},
                      {INF, INF, INF, 0}
                    };
  floyd(graph);
  return 0;
}
```

(b) Here's an implementation of the Travelling Salesman Problem (TSP) using dynamic programming in C:

```
#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX

int dist[V][V];
int dp[(1 << V)][V];

int tsp(int mask, int pos) {
  if (mask == (1 << V) - 1) {
    return dist[pos][0];
  }
  if (dp[mask][pos] != -1) {
    return dp[mask][pos];
  }
  int ans = INF;
  for (int city = 0; city < V; city++) {
    if ((mask & (1 << city)) == 0) {
      int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
      ans = min(ans, newAns);
    }
  }
  return dp[mask][pos] = ans;
}

int main() {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      scanf("%d", &dist[i][j]);
    }
  }
  for (int i = 0; i < (1 << V); i++) {
    for (int j = 0; j < V; j++) {
      dp[i][j] = -1;
    }
  }
  printf("%d\n", tsp(1, 0));
  return 0;
}
```
