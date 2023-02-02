write the c code for practical for my daa assignement 

All-Pairs Shortest Paths & TSP using Floyd's & DP: Implement Floyd's algorithm to find all-pairs shortest paths in a weighted graph, and implement a dynamic programming solution to the traveling salesman problem.

```
#include <stdio.h>
#define MAX_N 100
#define INF 1000000

int n;
int g[MAX_N][MAX_N];

void floyd() {
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int tsp(int u, int S) {
  if (S == (1 << n) - 1) return g[u][0];
  int res = INF;
  for (int v = 0; v < n; v++)
    if (!(S & (1 << v)))
      res = min(res, g[u][v] + tsp(v, S | (1 << v)));
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &g[i][j]);
  floyd();
  printf("%d\n", tsp(0, 1));
  return 0;
}
```
