#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 4

// Utility function to find the minimum of two integers
int min(int x, int y)
{
    return (x < y) ? x : y;
}

// Function to find the minimum weight Hamiltonian Cycle
int tsp(int graph[][V], int v, int currPos, int n, int count, int cost, int limit, int *ans)
{
    // If all cities are visited
    if (count == n && graph[currPos][0])
    {
        return cost + graph[currPos][0];
    }

    // Initialize result with a large value
    int res = INT_MAX;

    // Try every city that is not visited
    for (int i = 0; i < n; i++)
    {
        if (v & (1 << i))
        {
            continue;
        }

        int newCost = cost + graph[currPos][i];

        // If the cost of reaching city i from currPos and visiting
        // all other cities after that is greater than limit, then
        // stop further exploration
        if (newCost + (n - count - 1) * limit >= *ans)
        {
            continue;
        }

        v |= (1 << i);
        int temp = tsp(graph, v, i, n, count + 1, newCost, limit, ans);
        v &= ~(1 << i);

        // Update result if a better path is found
        res = min(res, temp);
    }

    return res;
}

int main()
{
    int graph[][V] =
        {
            {0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}};

    int limit = INT_MAX;
    int ans = INT_MAX;

    // Find the minimum weight Hamiltonian Cycle
    int res = tsp(graph, 1, 0, V, 1, 0, limit, &ans);
    printf("Minimum cost: %d\n", res);

    return 0;
} /* Here is the explanation for the code above:
 1. The function tsp() is a recursive function that takes the following parameters:
 i. graph[][]: Adjacency matrix representation of the graph
 ii. v: Bitmask for the visited nodes
 iii. currPos: Current node
 iv. n: Number of nodes
 v. count: Number of nodes visited so far
 vi. cost: Cost of the path so far
 vii. limit: Upper bound on the cost of the path
 viii. ans: Pointer to the final answer

 2. The function returns the minimum weight Hamiltonian Cycle reachable from v with the cost of the path so far as cost and the number of nodes visited so far as count.

 3. The function first checks if all the nodes are visited and if an edge exists from the current node to the starting node. If these conditions are met, it returns the cost of the path so far plus the cost of the edge from the current node to the starting node.

 4. If all nodes are not visited, it initializes the result with INT_MAX and then tries every node that is not visited.

 5. If the cost of reaching the node i from the current node and visiting all other nodes after that is greater than the limit, it stops further exploration.

 6. If the cost of reaching the node i from the current node and visiting all other nodes after that is less than the limit, it calculates the new cost of the path so far and the new bitmask and calls the tsp() function for the node i.

 7. The final answer is stored in the pointer ans.

 8. The main function first initializes the limit to INT_MAX and the answer to INT_MAX.

 9. Then it calls the tsp() function for the starting node and prints the final answer.

 The time complexity of the above solution is O(n2*2n). */
