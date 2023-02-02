write the codes in c following practical for my daa assignement 

Minimum Cost Spanning Tree using Kruskal's Algorithm: Implement Kruskal's algorithm to find the minimum cost spanning tree of a connected undirected graph. Use union-find algorithms in your program.

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(E * sizeof(struct Edge));
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

int isCycle(struct Graph* graph) {
    int *parent = (int*) malloc(graph->V * sizeof(int));
    memset(parent, -1, sizeof(int) * graph->V);
    for (int i = 0; i < graph->E; i++) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);
        if (x == y)
            return 1;
        Union(parent, x, y);
    }
    return 0;
}

int cmp(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), cmp);
    int *parent = (int*) malloc(V * sizeof(int));
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


1. `#include <stdio.h>`: This line includes the standard input/output library in the program.
2. `#include <stdlib.h>`: This line includes the standard library in the program.
3. `#include <string.h>`: This line includes the string library in the program.
4. `#define MAX 100`: This line defines the constant `MAX` with a value of 100.
5. `struct Edge { int src, dest, weight; };`: This line defines a structure `Edge` with three integer variables `src`, `dest`, and `weight`.
6. `struct Graph { int V, E; struct Edge* edge; };`: This line defines a structure `Graph` with two integer variables `V` and `E`, and a pointer to the structure `Edge` named `edge`.
7. `struct Graph* createGraph(int V, int E)`: This line defines a function `createGraph` that takes two integer arguments `V` and `E` and returns a pointer to the structure `Graph`. The function creates a graph with `V` vertices and `E` edges, and returns the pointer to the graph.
8. `int find(int parent[], int i)`: This line defines a function `find` that takes an array of integers `parent` and an integer `i` as arguments, and returns an integer. The function returns the representative of the set to which `i` belongs.
9. `void Union(int parent[], int x, int y)`: This line defines a function `Union` that takes an array of integers `parent` and two integers `x` and `y` as arguments, and returns nothing. The function merges the two sets represented by `x` and `y`.
10. `int isCycle(struct Graph* graph)`: This line defines a function `isCycle` that takes a pointer to the structure `Graph` as an argument and returns an integer. The function returns 1 if the graph contains a cycle, and 0 if it does not.
11. `int cmp(const void* a, const void* b)`: This line defines a function `cmp` that takes two `void` pointers as arguments and returns an integer. The function is used as a comparison function for the `qsort` function.
12. `void KruskalMST(struct Graph* graph)`: This line defines a function `KruskalMST` that takes a pointer to the structure `Graph` as an argument and returns nothing. The function implements Kruskal's algorithm to find the minimum cost spanning tree of the graph.
13. `int main()`: This line defines the main function.
14. `int V = 4; int E = 5;`: These lines define two integer variables `V` and `E` with values 4 and 5, respectively.
15. `struct Graph* graph = createGraph(V, E);`: This line creates a graph with `V` vertices and `E` edges using the `createGraph` function, and stores the pointer to the graph in the variable `graph`.
16. `graph->edge[0].src = 0; graph->edge[0].dest = 1; graph->edge[0].weight = 10;`: These lines define the first edge in the graph with source vertex 0, destination vertex 1, and weight 10.
17. `KruskalMST(graph);`: This line calls the `KruskalMST` function to find the minimum cost spanning tree of the graph.
18. `return 0;`: This line returns 0 from the main function.
*/
