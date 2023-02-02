write the c code for practical for my daa assignement 

Traveling Salesman Problem: Implement an algorithm to find the shortest possible route that visits a given set of cities and returns to the starting city.
 Here's an example of a brute force algorithm in C to solve the Traveling Salesman Problem:

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 100
#define INFINITY INT_MAX

int dist[MAX_CITIES][MAX_CITIES];
int cities[MAX_CITIES];
int n;

int tsp(int currCity, int visited, int cost) {
    if (visited == (1 << n) - 1) {
        return cost + dist[currCity][0];
    }

    int minCost = INFINITY;
    for (int i = 0; i < n; i++) {
        if (!(visited & (1 << i))) {
            int newCost = cost + dist[currCity][i];
            int newVisited = visited | (1 << i);
            int res = tsp(i, newVisited, newCost);
            minCost = min(minCost, res);
        }
    }

    return minCost;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cities[i] = i;
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    int cost = tsp(0, 1, 0);
    printf("Minimum cost: %d\n", cost);
    return 0;
}
```
