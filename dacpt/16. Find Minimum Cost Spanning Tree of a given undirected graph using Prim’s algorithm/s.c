#include <stdio.h>
#include <stdbool.h>
#define V 5
#define INF 99999

int minKey(int key[], bool mstSet[])
{
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    primMST(graph);
    return 0;
}
/* Here is the explanation for the code above:
1. The program is written in C language and uses the standard input/output library (stdio.h) and the standard bool library (stdbool.h).
2. The program is run on a 5 vertex graph. The user can modify the number of vertices by changing the value of the V constant.
3. The INF constant is set to 99999 as a representation of infinity.
4. The minKey() function finds the vertex with the minimum key value, from the set of vertices not yet included in MST.
5. The printMST() function prints the constructed MST stored in parent[].
6. The primMST() function creates a MST for a graph represented using adjacency matrix representation.
7. The main() function creates a graph given in the above diagram and prints the MST. */
/* Here is the explanation for the code above:
1. We first define the number of vertices as V and the number of edges as E.
2. We define the INF as 99999 which is assumed to be infinity.
3. In the minKey() function, we initialize the minimum value as INF and the minimum index as 0.
4. We then traverse through the array and if the value is less than the minimum and if it is not in the mstSet, we update the minimum value and index.
5. In the printMST() function, we print the edges and weights of the graph.
6. In the primMST() function, we initialize the key array with INF and mstSet with false.
7. We then set the key of the first vertex as 0 and the parent of the first vertex as -1.
8. We then run a loop V-1 times where V is the number of vertices.
9. We then call the minKey() function to get the minimum index of the key.
10. We then set mstSet to true for the minimum index.
11. We then run another loop to check if the graph at the minimum index and the current index is true, if it is not in the mstSet and if the graph value is less than the key value, we update the parent and key.
12. We then call the printMST() function to print the MST.
13. We then call the main() function and then return 0. */
