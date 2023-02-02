write the codes in c following practical for my daa assignement 

Minimum Cost Spanning Tree using Kruskal's Algorithm: Implement Kruskal's algorithm to find the minimum cost spanning tree of a connected undirected graph. Use union-find algorithms in your program.

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDGE 100000
#define MAX_VERTEX 100

struct Edge {
  int start, end, weight;
};

struct Graph {
  int vertex_count, edge_count;
  struct Edge edges[MAX_EDGE];
};

int parent[MAX_VERTEX];

int find(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y)
    parent[y] = x;
}

int cmp(const void *a, const void *b) {
  struct Edge *x = (struct Edge *)a;
  struct Edge *y = (struct Edge *)b;
  return x->weight - y->weight;
}

void kruskal(struct Graph *graph) {
  int i, count = 0, x, y;
  for (i = 0; i < graph->vertex_count; i++)
    parent[i] = i;
  qsort(graph->edges, graph->edge_count, sizeof(struct Edge), cmp);
  for (i = 0; i < graph->edge_count; i++) {
    x = find(graph->edges[i].start);
    y = find(graph->edges[i].end);
    if (x != y) {
      count++;
      union_set(x, y);
      printf("%d - %d: %d\n", graph->edges[i].start, graph->edges[i].end,
             graph->edges[i].weight);
      if (count == graph->vertex_count - 1)
        break;
    }
  }
}

int main() {
  int i;
  struct Graph graph;
  scanf("%d%d", &graph.vertex_count, &graph.edge_count);
  for (i = 0; i < graph.edge_count; i++)
    scanf("%d%d%d", &graph.edges[i].start, &graph.edges[i].end,
          &graph.edges[i].weight);
  kruskal(&graph);
  return 0;
}
```
