write the c code for practical for my daa assignement 

Minimum Cost Spanning Tree using Prim's Algorithm: Implement Prim's algorithm to find the minimum cost spanning tree of a connected undirected graph.

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 1000000000

int n, m;
int cost[MAX_VERTICES][MAX_VERTICES];
bool used[MAX_VERTICES];
int mincost[MAX_VERTICES];

void prim() {
  for (int i = 0; i < n; i++) {
    mincost[i] = INF;
    used[i] = false;
  }

  mincost[0] = 0;
  int res = 0;

  while (true) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }

    if (v == -1) break;
    used[v] = true;
    res += mincost[v];

    for (int u = 0; u < n; u++) {
      mincost[u] = min(mincost[u], cost[v][u]);
    }
  }

  printf("Minimum cost: %d\n", res);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cost[i][j] = INF;
    }
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--; b--;
    cost[a][b] = cost[b][a] = c;
  }

  prim();
  return 0;
}
```
