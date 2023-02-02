write the codes in c following practical for my daa assignement 

All-Pairs Shortest Paths & TSP using Floyd's & DP: Implement Floyd's algorithm to find all-pairs shortest paths in a weighted graph, and implement a dynamic programming solution to the traveling salesman problem.
 Here's a code for finding all-pairs shortest paths in a weighted graph using Floyd's algorithm in C:

```
#include <stdio.h> 
#include <limits.h> 

#define V 100 
#define INF INT_MAX 

void floyd(int graph[][V], int V) 
{ 
    int dist[V][V], i, j, k; 
  
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 
  
    for (k = 0; k < V; k++) 
    { 
        for (i = 0; i < V; i++) 
        { 
            for (j = 0; j < V; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
  
    printf("The following matrix shows the shortest distances between every pair of vertices\n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            if (dist[i][j] == INF) 
                printf("%7s", "INF"); 
            else
                printf("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 

int main() 
{ 
    int graph[V][V]; 
    int V; 
  
    printf("Enter the number of vertices: "); 
    scanf("%d", &V); 
  
    printf("Enter the distance matrix: \n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            scanf("%d", &graph[i][j]); 
  
            if (graph[i][j] == 0) 
                graph[i][j] = INF; 
        } 
    } 
  
    floyd(graph, V); 
  
    return 0; 
} 
```

Here's a code for solving the traveling salesman problem using dynamic programming in C:

```
#include <stdio.h> 
#include <limits.h> 

#define V 100 
#define INF INT_MAX 

int tsp(int graph[][V], int s, int n, int dp[][V]) 
{ 
    if (dp[s][n] != -1) 
        return dp[s][n]; 
  
    int ans = INF; 
    for (int i = 0; i < V; i++) 
    { 
        if (graph[s][i] != INF && s != i) 
        { 
            int temp = graph[s][i] + tsp(graph, i, n, dp); 
            ans = min(ans, temp); 
        } 
    } 
  
    dp[s][n] = ans; 
  
    return ans; 
} 

int main() 
{ 
    int graph[V][V]; 
    int V; 
  
    printf("Enter the number of vertices: "); 
    scanf("%d", &V); 
  
    printf("Enter the distance matrix: \n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            scanf("%d", &graph[i][j]); 
  
            if (graph[i][j] == 0 && i != j) 
                graph[i][j] = INF; 
        } 
    } 
  
    int dp[V][V]; 
    memset(dp, -1, sizeof dp); 
  
    int s; 
    printf("Enter the starting vertex: "); 
    scanf("%d", &s); 
  
    int n = s; 
    printf("The minimum cost to travel all cities starting from vertex %d is %d\n", s, tsp(graph, s, n, dp)); 
  
    return 0; 
} 
```
/*
explain the following code 

 Here's a code for finding all-pairs shortest paths in a weighted graph using Floyd's algorithm in C:

```
#include <stdio.h> 
#include <limits.h> 

#define V 100 
#define INF INT_MAX 

void floyd(int graph[][V], int V) 
{ 
    int dist[V][V], i, j, k; 
  
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 
  
    for (k = 0; k < V; k++) 
    { 
        for (i = 0; i < V; i++) 
        { 
            for (j = 0; j < V; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
  
    printf("The following matrix shows the shortest distances between every pair of vertices\n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            if (dist[i][j] == INF) 
                printf("%7s", "INF"); 
            else
                printf("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 

int main() 
{ 
    int graph[V][V]; 
    int V; 
  
    printf("Enter the number of vertices: "); 
    scanf("%d", &V); 
  
    printf("Enter the distance matrix: \n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            scanf("%d", &graph[i][j]); 
  
            if (graph[i][j] == 0) 
                graph[i][j] = INF; 
        } 
    } 
  
    floyd(graph, V); 
  
    return 0; 
} 
```

Here's a code for solving the traveling salesman problem using dynamic programming in C:

```
#include <stdio.h> 
#include <limits.h> 

#define V 100 
#define INF INT_MAX 

int tsp(int graph[][V], int s, int n, int dp[][V]) 
{ 
    if (dp[s][n] != -1) 
        return dp[s][n]; 
  
    int ans = INF; 
    for (int i = 0; i < V; i++) 
    { 
        if (graph[s][i] != INF && s != i) 
        { 
            int temp = graph[s][i] + tsp(graph, i, n, dp); 
            ans = min(ans, temp); 
        } 
    } 
  
    dp[s][n] = ans; 
  
    return ans; 
} 

int main() 
{ 
    int graph[V][V]; 
    int V; 
  
    printf("Enter the number of vertices: "); 
    scanf("%d", &V); 
  
    printf("Enter the distance matrix: \n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            scanf("%d", &graph[i][j]); 
  
            if (graph[i][j] == 0 && i != j) 
                graph[i][j] = INF; 
        } 
    } 
  
    int dp[V][V]; 
    memset(dp, -1, sizeof dp); 
  
    int s; 
    printf("Enter the starting vertex: "); 
    scanf("%d", &s); 
  
    int n = s; 
    printf("The minimum cost to travel all cities starting from vertex %d is %d\n", s, tsp(graph, s, n, dp)); 
  
    return 0; 
} 
```
 

The first code is for finding all-pairs shortest paths in a weighted graph using Floyd's algorithm. The algorithm takes a 2D graph as input and returns the shortest distance between every pair of vertices. The code first initializes a 2D array `dist` with the input graph. Then, it implements the Floyd's algorithm to find the shortest distance between every pair of vertices. The algorithm uses a nested loop to iterate over all vertices and updates the distance between every pair of vertices if it finds a shorter path. Finally, it prints the shortest distance between every pair of vertices.

The second code is for solving the traveling salesman problem using dynamic programming. The algorithm takes a 2D graph and a starting vertex as input and returns the minimum cost to travel all cities starting from the given vertex. The code first initializes a 2D array `dp` with -1. Then, it implements a recursive function `tsp` to find the minimum cost to travel all cities. The function takes the current vertex, the destination vertex, and the dp array as input. If the value of dp for the current vertex and the destination vertex is already calculated, it returns the value. Otherwise, it calculates the minimum cost to travel all cities by iterating over all vertices and updating the minimum cost if it finds a shorter path. Finally, it returns the minimum cost. The main function takes the input graph and the starting vertex, initializes the dp array, and calls the `tsp` function to find the minimum cost.
*/
