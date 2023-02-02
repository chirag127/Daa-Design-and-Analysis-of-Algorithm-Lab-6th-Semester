
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define V 1000

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int n, int graph[V][V]) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph);
}

int main() {
    int graph[V][V];
    memset(graph, 0, sizeof(graph));
    // input graph
    primMST(graph);
    return 0;
}

/*

1. `#include <stdio.h>`: Includes the standard input/output library in the code.
2. `#include <stdlib.h>`: Includes the standard library in the code.
3. `#include <string.h>`: Includes the string library in the code.
4. `#include <limits.h>`: Includes the limits library in the code.
5. `#define V 1000`: Defines the constant `V` with value `1000`.
6. `int minKey(int key[], bool mstSet[])`: This function returns the index of the minimum key value from the `key` array, which is not in the minimum spanning tree set `mstSet`.
7. `int printMST(int parent[], int n, int graph[V][V])`: This function prints the edges and weights of the minimum spanning tree.
8. `void primMST(int graph[V][V])`: This function implements Prim's algorithm to find the minimum spanning tree of a connected undirected graph.
9. `int main()`: This is the main function, which initializes the 2D graph array `graph` to 0 and calls the `primMST` function to find the minimum spanning tree.
*/
