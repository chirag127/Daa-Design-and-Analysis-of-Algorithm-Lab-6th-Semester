write the c code for practical for my daa assignement 

Minimum Cost Spanning Tree using Kruskal's Algorithm: Implement Kruskal's algorithm to find the minimum cost spanning tree of a connected undirected graph. Use union-find algorithms in your program.
 
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Edge {
  int src, dest, weight;
};

struct Graph {
  int V, E;
  struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
  struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
  graph->V = V;
  graph->E = E;
  graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
  return graph;
}

int find(int parent[], int i) {
  if (parent[i] == -1)
    return i;
  return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
  int xset = find(parent, x);
  int yset = find(parent, y);
  parent[xset] = yset;
}

int isCycle( struct Graph* graph ) {
  int *parent = (int*) malloc( graph->V * sizeof(int) );
  memset(parent, -1, sizeof(int) * graph->V);
  for(int i = 0; i < graph->E; ++i) {
    int x = find(parent, graph->edge[i].src);
    int y = find(parent, graph->edge[i].dest);
    if (x == y)
      return 1;
    Union(parent, x, y);
  }
  return 0;
}

int comp(const void* a, const void* b) {
  struct Edge* a1 = (struct Edge*)a;
  struct Edge* b1 = (struct Edge*)b;
  return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph) {
  int V = graph->V;
  struct Edge result[V];
  int e = 0;
  int i = 0;
  qsort(graph->edge, graph->E, sizeof(graph->edge[0]), comp);
  int *parent = (int*) malloc( V * sizeof(int) );
  memset(parent, -1, sizeof(int) * V);
  while (e < V - 1) {
    struct Edge next_edge = graph->edge[i++];
    int x = find(parent, next_edge.src);
    int y = find(parent, next_edge.dest);
    if (x != y) {
      result[e++] = next_edge;
      Union(parent, x, y);
    }
  }
  printf("Following are the edges in the constructed MST\n");
  for (i = 0; i < e; ++i)
    printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
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
```
/*
 

This is a C code that implements Kruskal's algorithm to find the minimum cost spanning tree of a connected undirected graph. The code consists of the following parts:

1. Includes: 
   - `stdio.h` for input/output operations
   - `stdlib.h` for memory allocation functions
   - `string.h` for string operations

2. Structs:
   - `Edge`: A struct that represents an edge in a graph with `src`, `dest`, and `weight` fields.
   - `Graph`: A struct that represents a graph with `V` (number of vertices), `E` (number of edges), and `edge` (pointer to an array of Edge structs) fields.

3. Functions:
   - `createGraph`: A function that creates a graph given the number of vertices and edges.
   - `find`: A function that implements the find operation of the union-find algorithm.
   - `Union`: A function that implements the union operation of the union-find algorithm.
   - `isCycle`: A function that checks if the graph has a cycle using the union-find algorithm.
   - `comp`: A function that compares two edges based on their weight for sorting.
   - `KruskalMST`: The main function that implements Kruskal's algorithm to find the minimum cost spanning tree of a graph.
   - `main`: The main program that creates a sample graph, calls the `KruskalMST` function, and prints the result.

4. Program Execution:
   - The program initializes a graph with 4 vertices and 5 edges.
   - It sets the properties of each edge (`src`, `dest`, `weight`).
   - It calls the `KruskalMST` function to find the minimum cost spanning tree of the graph.
   - It prints the edges of the minimum cost spanning tree.
   - The program terminates.
*/
/*


This code is like a game of building a tree with sticks. We have 4 blocks and 5 sticks to connect them. We want to make a tree with the minimum total weight of sticks. The code helps us do that.

1. We need some tools to play the game, so we include some tools from the library.
   - `stdio.h` is for printing the result of the game.
   - `stdlib.h` is for allocating memory for the game.
   - `string.h` is for working with strings.

2. We define two things for the game:
   - `Edge`: A stick that connects two blocks. It has three parts: `src` (the starting block), `dest` (the ending block), and `weight` (the weight of the stick).
   - `Graph`: The whole game with blocks and sticks. It has three parts: `V` (the number of blocks), `E` (the number of sticks), and `edge` (a pointer to an array of sticks).

3. We have some helper functions for the game:
   - `createGraph`: A function that creates a game given the number of blocks and sticks.
   - `find`: A function that helps us find the root block of a block.
   - `Union`: A function that helps us connect two blocks.
   - `isCycle`: A function that checks if the game has a cycle (a block connected to itself).
   - `comp`: A function that compares two sticks based on their weight for sorting.
   - `KruskalMST`: The main function that plays the game and finds the minimum cost tree.
   - `main`: The main program that creates a sample game, calls the `KruskalMST` function, and prints the result.

4. How to play the game:
   - The program starts the game with 4 blocks and 5 sticks.
   - It sets the properties of each stick (`src`, `dest`, `weight`).
   - It calls the `KruskalMST` function to find the minimum cost tree.
   - It prints the sticks of the minimum cost tree.
   - The program ends.
*/
