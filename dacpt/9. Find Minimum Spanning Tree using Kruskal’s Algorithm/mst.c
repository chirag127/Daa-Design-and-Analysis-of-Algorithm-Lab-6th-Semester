#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5
#define E 7

// Utility function to find the parent of a node in a set
int find(int parent[], int i)
{
    if (parent[i] == -1)
    {
        return i;
    }

    return find(parent, parent[i]);
}

// Utility function to perform union of two sets
void union1(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Function to find the minimum spanning tree using Kruskal's Algorithm
void KruskalMST(int graph[][V])
{
    int parent[V];

    // Initialize each node as a parent of itself
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }

    // The edges are stored in an array of size E
    int edges[E][3] =
        {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4},
            {2, 4, 3},
            {3, 4, 2}};

    // Sort the edges in increasing order of weight
    for (int i = 0; i < E; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                int temp0 = edges[j][0];
                int temp1 = edges[j][1];
                int temp2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp0;
                edges[j + 1][1] = temp1;
                edges[j + 1][2] = temp2;
            }
        }
    }

    int e = 0;
    int i = 0;

    // Iterate over the edges, adding each edge to the minimum spanning tree
    // if it does not form a cycle with the edges already in the tree
    while (e < V - 1)
    {
        int x = find(parent, edges[i][0]);
        int y = find(parent, edges[i][1]);

        if (x != y)
        {
            printf("%d -- %d: %d\n", edges[i][0], edges[i][1], edges[i][2]);
            e++;
            union1(parent, x, y);
        }

        i++;
    }
}
int main()
{
    int graph[V][V] =
        {
            {0, 10, 6, 5, 0},
            {10, 0, 0, 15, 0},
            {6, 0, 0, 4, 3},
            {5, 15, 4, 0, 2},
            {0, 0, 3, 2, 0}};
    KruskalMST(graph);

    return 0;

}
/* Here is the explanation for the code above:
1. The graph is represented using an adjacency matrix. Each element in the matrix is the weight of the edge between the two vertices. If there is no edge between the vertices, then the value is 0.

2. The edges are stored in an array of size E. Each row of the array represents an edge. The first two elements are the vertices connected by the edge and the third element is the weight of the edge.

3. The edges are sorted in increasing order of weight using a bubble sort.

4. The find() function is used to find the parent of a node in a set. The union() function is used to perform union of two sets. Both the functions use the path compression optimization.

5. The KruskalMST() function is used to find the minimum spanning tree using Kruskal’s Algorithm. The parent[] array is used to store the parent of each node. Initially, each node is a parent of itself. The e variable is used to keep track of the number of edges in the minimum spanning tree. The i variable is used to keep track of the next edge in the sorted list of edges.

6. The while loop is used to iterate over the edges, adding each edge to the minimum spanning tree if it does not form a cycle with the edges already in the tree. If the two vertices connected by the edge are not in the same set, then the edge is added to the minimum spanning tree. Otherwise, the edge is discarded. The find() function is used to find the parent of each node in the edge. If the parent of the two nodes is the same, then the two nodes are in the same set. If the parent of the two nodes is different, then the two nodes are not in the same set. The union() function is used to perform union of the two sets.

7. The main() function is used to represent the graph using an adjacency matrix and call the KruskalMST() function. */