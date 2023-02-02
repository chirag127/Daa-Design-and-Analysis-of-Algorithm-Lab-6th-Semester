write the codes in c following practical for my daa assignement 

Minimum Spanning Tree using Kruskal’s Algorithm: Implement Kruskal's algorithm to find the minimum spanning tree of a connected undirected graph.
 
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define bool int
#define true 1
#define false 0

typedef struct Edge {
  int src, dest, weight;
} Edge;

typedef struct Graph {
  int V, E;
  Edge* edge;
} Graph;

typedef struct Subset {
  int parent;
  int rank;
} Subset;

int find(Subset subsets[], int i) {
  if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);
  if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if (subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
  else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

int myComp(const void* a, const void* b) {
  Edge* a1 = (Edge*)a;
  Edge* b1 = (Edge*)b;
  return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph) {
  int V = graph->V;
  Edge result[V];
  int e = 0;
  int i = 0;
  qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
  Subset *subsets = (Subset*) malloc( V * sizeof(Subset) );
  for (int v = 0; v < V; ++v) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }
  while (e < V - 1) {
    Edge next_edge = graph->edge[i++];
    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);
    if (x != y) {
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }
  printf("Following are the edges in the constructed MST\n");
  for (i = 0; i < e; ++i)
    printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
  return;
}

Graph* createGraph(int V, int E) {
  Graph* graph = (Graph*) malloc( sizeof(Graph) );
  graph->V = V;
  graph->E = E;
  graph->edge = (Edge*) malloc( graph->E * sizeof(Edge) );
  return graph;
}

int main() {
  int V = 4;
  int E = 5;
  Graph* graph = createGraph(V, E);
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[0].weight = 10;
  graph->edge[1].src = 0;
  graph->edge[1].dest = 2;
  graph->edge[1].weight = 6;
  graph->edge[2].src = 0;
  graph->edge[2].dest = 3;
  graph->edge[2].weight = 5;
  graph->edge[3].src = 1;
  graph->edge[3].dest = 3;
  graph->edge[3].weight = 15;
  graph->edge[4].src = 2;
  graph->edge[4].dest = 3;
  graph->edge[4].weight = 4;
  KruskalMST(graph);
  return 0;
}
```
