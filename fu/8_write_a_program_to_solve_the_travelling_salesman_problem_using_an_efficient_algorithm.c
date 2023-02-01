############################################################

(try to answer in C) 
Write a program to solve the Travelling Salesman Problem using an efficient algorithm.

 The Traveling Salesman Problem (TSP) is a well-known NP-hard optimization problem that requires finding the shortest possible route that visits a given set of cities and returns to the starting city. There is no efficient algorithm that can solve the TSP exactly for large instances, but there are several heuristics and approximation algorithms that can provide good solutions in practice.

One popular heuristic algorithm for TSP is the Nearest Neighbor algorithm. Here's an implementation in C:

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 100
#define INF INT_MAX

int n;
int g[MAX_CITIES][MAX_CITIES];
bool visited[MAX_CITIES];
int tour[MAX_CITIES];
int minCost = INF;

void copyTour(int currTour[]) {
  for (int i = 0; i < n; i++) {
    tour[i] = currTour[i];
  }
  minCost = 0;
  for (int i = 0; i < n - 1; i++) {
    minCost += g[currTour[i]][currTour[i + 1]];
  }
  minCost += g[currTour[n - 1]][currTour[0]];
}

void tsp(int currTour[], int currPos, int currCost) {
  if (currPos == n) {
    if (currCost + g[currTour[n - 1]][currTour[0]] < minCost) {
      copyTour(currTour);
    }
    return;
  }
  for (int city = 0; city < n; city++) {
    if (!visited[city]) {
      int tempTour[MAX_CITIES];
      for (int i = 0; i < currPos; i++) {
        tempTour[i] = currTour[i];
      }
      tempTour[currPos] = city;
      visited[city] = true;
      tsp(tempTour, currPos + 1, currCost + g[currTour[currPos - 1]][city]);
      visited[city] = false;
    }
  }
}

int main() {
  printf("Enter the number of cities: ");
  scanf("%d", &n);
  printf("Enter the cost matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &g[i][j]);
    }
    visited[i] = false;
  }
  int start = 0;
  int currTour[MAX_CITIES];
  currTour[0] = start;
  visited[start] = true;
  tsp(currTour, 1, 0);
  printf("Minimum cost tour:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", tour[i]);
  }
  printf("\nCost: %d\n", minCost);
  return 0;
}
```
