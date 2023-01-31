#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool isSafe(int v, int graph[][MAX], int path[], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
    {
        return false;
    }
    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
        {
            return false;
        }
    }
    return true;
}

bool hamiltonianCycleUtil(int graph[][MAX], int path[], int pos, int n)
{
    if (pos == n)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1, n) == true)
            {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}

bool hamiltonianCycle(int graph[][MAX], int n)
{
    int path[n];
    for (int i = 0; i < n; i++)
    {
        path[i] = -1;
    }
    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1, n) == false)
    {
        printf("\nSolution does not exist\n");
        return false;
    }
    printf("\nSolution exists\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", path[i]);
    }
    printf("%d ", path[0]);
    return true;
}

int main()
{
    int n, graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    hamiltonianCycle(graph, n);
    return 0;
}
/* Here is the explanation for the code above:
1. isSafe(v, graph, path, pos) is a helper function that returns true if the vertex v can be added at index 'pos' in the Hamiltonian Cycle constructed so far (stored in 'path[]'). We basically check if there is an edge from the last vertex in path[] to the vertex v and if v is not already included in the path.
2. hamiltonianCycleUtil(graph, path[], pos, n) is a recursive utility function to solve Hamiltonian Cycle problem. It returns true if there is a Hamiltonian Cycle possible, otherwise false. It mainly uses isSafe() to check if a vertex can be added at index 'pos' in Hamiltonian Cycle constructed so far (stored in 'path[]').
3. hamiltonianCycle(graph, n) is a wrapper function for hamiltonianCycleUtil(). It mainly creates path[] and calls hamiltonianCycleUtil(). It also prints the solution.
4. main() is used to input the adjacency matrix and call hamiltonianCycle(). */
/* Here is the explanation for the code above:
1. Firstly, we create a function isSafe() which checks if the vertex v can be added at index 'pos' in the Hamiltonian Cycle constructed so far (stored in 'path[]').
2. The function returns true if the following conditions are met:
a. The graph is connected, i.e., there is an edge from the last vertex in the path to the vertex to be added.
b. The vertex to be added is not already included in the path.
3. If the vertex v can be added, we add it to the path and recursively check if adding vertex v+1 leads to a solution.
4. If adding v doesn't lead to a solution, then we remove it from the path and return false.
5. Finally, we create a function hamiltonianCycle() which solves the Hamiltonian Cycle problem using Backtracking. It mainly uses hamiltonianCycleUtil() to solve the problem. It returns false if no Hamiltonian Cycle is possible, otherwise return true and prints the path.
6. hamiltonianCycleUtil() is a recursive function that solves the Hamiltonian Cycle problem using Backtracking. It mainly uses isSafe() to check if it is possible to add vertex 'i' at position 'pos' in the Hamiltonian Cycle constructed so far (stored in 'path[]').
7. The base case is if all the vertices are included in the Hamiltonian Cycle, i.e., if pos is equal to the number of vertices.
8. If all the vertices are included in the Hamiltonian Cycle, then we return true if there is an edge from the last vertex in the path to the first vertex in the path, otherwise we return false.
9. If all the vertices are not included in the Hamiltonian Cycle constructed so far, then we try different vertices as a next candidate in Hamiltonian Cycle. We first check if adding the vertex to the Hamiltonian Cycle is safe or not, i.e., whether the edge exists and whether the vertex is already included in the Hamiltonian Cycle constructed so far.
10. If it is safe to add the vertex, we add the vertex to the path and then recursively check whether adding vertex 'i+1' leads to a solution or not.
11. If adding vertex 'i' doesn't lead to a solution, then we remove it from the path and try another vertex.
12. Finally, we create a main() function which takes the number of vertices and the adjacency matrix as input and calls the hamiltonianCycle() function. */
