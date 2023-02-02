write the codes in c following practical for my daa assignement 

Minimum Cost Spanning Tree using Kruskal's Algorithm: Implement Kruskal's algorithm to find the minimum cost spanning tree of a connected undirected graph. Use union-find algorithms in your program.
 Here's a sample implementation of Kruskal's Algorithm in C:

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100
#define ull unsigned long long

struct Edge {
  int src, dest, weight;
};

struct Graph {
  int V, E;
  struct Edge* edge;
};

struct subset {
  int parent;
  int rank;
};

int find(struct subset subsets[], int i) {
  if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
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
  struct Edge* a1 = (struct Edge*)a;
  struct Edge* b1 = (struct Edge*)b;
  return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph) {
  int V = graph->V;
  struct Edge result[V];
  int e = 0;
  int i = 0;
  qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
  struct subset *subsets =
      (struct subset*) malloc( V * sizeof(struct subset));
  for (int v = 0; v < V; ++v) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }
  while (e < V - 1) {
    struct Edge next_edge = graph->edge[i++];
    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);
    if (x != y) {
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }
  printf("Following are the edges in the constructed MST\n");
  for (i = 0; i < e; ++i)
    printf("%d -- %d == %d\n", result[i].src, result[i].dest,
           result[i].weight);
  return;
}

int main() {
  int V = 4;
  int E = 5;
  struct Graph* graph = createGraph(V, E);
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
/*


1. #include<stdio.h>, #include<stdlib.h>, #include<stdbool.h>
   These are the header files that are included. `stdio.h` is the standard input/output header file, `stdlib.h` is the standard library header file, and `stdbool.h` is the boolean header file.

2. #define MAX 100, #define ull unsigned long long
   These are macro definitions. `MAX` is defined to be 100, and `ull` is defined to be `unsigned long long`.

3. struct Edge {
      int src, dest, weight;
   };
   This is a structure definition for an edge in a graph. It has three members: `src` (source), `dest` (destination), and `weight` (weight of the edge).

4. struct Graph {
      int V, E;
      struct Edge* edge;
   };
   This is a structure definition for a graph. It has three members: `V` (number of vertices), `E` (number of edges), and `edge` (pointer to an array of edges).

5. struct subset {
      int parent;
      int rank;
   };
   This is a structure definition for a subset. It has two members: `parent` and `rank`.

6. int find(struct subset subsets[], int i) {
      if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
      return subsets[i].parent;
   }
   This is a function to find the parent of a node in a subset. It takes an array of subsets and an index as input. It returns the parent of the node at the given index.

7. void Union(struct subset subsets[], int x, int y) {
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
   This is a function to merge two subsets into one. It takes an array of subsets and two indices as input. It merges the subsets containing the nodes at the given indices.

8. int myComp(const void* a, const void* b) {
      struct Edge* a1 = (struct Edge*)a;
      struct Edge* b1 = (struct Edge*)b;
      return a1->weight > b1->weight;
   }
   This is a comparison function for sorting edges in ascending order of their weights. It takes two pointers to edges as input and returns a positive integer if the weight of the first edge is greater than the weight of the second edge, 0 if they are equal, and a negative integer if the weight of the first edge is less than the weight of the second edge.

9. void KruskalMST(struct Graph* graph) {
      int V = graph->V;
      struct Edge result[V];
      int e = 0;
      int i = 0;
      qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
      struct subset *subsets =
          (struct subset*) malloc( V * sizeof(struct subset));
      for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
      }
      while (e < V - 1) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
          result[e++] = next_edge;
          Union(subsets, x, y);
        }
      }
      printf("Following are the edges in the constructed MST\n");
      for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
               result[i].weight);
      return;
   }
   This is the main function for finding the minimum cost spanning tree using Kruskal's algorithm. It takes a pointer to a graph as input. It sorts the edges in ascending order of their weights, initializes the subsets, and then iteratively adds edges to the result while maintaining the property that the result is a tree. Finally, it prints the edges in the constructed minimum spanning tree.

10. int main() {
      int V = 4;
      int E = 5;
      struct Graph* graph = createGraph(V, E);
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
   This is the main function of the program. It sets the number of vertices and edges to 4 and 5, respectively, creates a graph, sets the edges and their weights, and then calls the `KruskalMST` function to find the minimum cost spanning tree. Finally, it returns 0.
*/
