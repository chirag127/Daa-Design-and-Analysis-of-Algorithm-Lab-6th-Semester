write the codes in c following practical for my daa assignement 

Traveling Salesman Problem: Implement an algorithm to find the shortest possible route that visits a given set of cities and returns to the starting city.
 Here's a basic outline of a brute force algorithm in C:

```
#include<stdio.h>
#include<stdlib.h>

#define MAX_CITIES 100
#define INF 1000000

int n; 
int dist[MAX_CITIES][MAX_CITIES]; 
int best_route[MAX_CITIES]; 
int best_distance = INF; 

void find_route(int city, int route[], int distance) {
  if (city == n) { 
    // All cities have been visited
    if (distance + dist[route[n-1]][0] < best_distance) { 
      // Update the best route and distance
      best_distance = distance + dist[route[n-1]][0];
      for (int i = 0; i < n; i++) {
        best_route[i] = route[i];
      }
    }
    return;
  }
  for (int i = 1; i < n; i++) { 
    // Try visiting all cities
    int visited = 0;
    for (int j = 0; j < city; j++) {
      if (route[j] == i) {
        visited = 1;
        break;
      }
    }
    if (!visited) { 
      // City has not been visited
      route[city] = i;
      find_route(city+1, route, distance + dist[route[city-1]][i]);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &dist[i][j]);
    }
  }
  int route[MAX_CITIES];
  route[0] = 0; 
  find_route(1, route, 0);
  printf("Best route: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", best_route[i]);
  }
  printf("\nBest distance: %d\n", best_distance);
  return 0;
}
```
/*
explain the following code 

 Here's a basic outline of a brute force algorithm in C:

```
#include<stdio.h>
#include<stdlib.h>

#define MAX_CITIES 100
#define INF 1000000

int n; 
int dist[MAX_CITIES][MAX_CITIES]; 
int best_route[MAX_CITIES]; 
int best_distance = INF; 

void find_route(int city, int route[], int distance) {
  if (city == n) { 
    // All cities have been visited
    if (distance + dist[route[n-1]][0] < best_distance) { 
      // Update the best route and distance
      best_distance = distance + dist[route[n-1]][0];
      for (int i = 0; i < n; i++) {
        best_route[i] = route[i];
      }
    }
    return;
  }
  for (int i = 1; i < n; i++) { 
    // Try visiting all cities
    int visited = 0;
    for (int j = 0; j < city; j++) {
      if (route[j] == i) {
        visited = 1;
        break;
      }
    }
    if (!visited) { 
      // City has not been visited
      route[city] = i;
      find_route(city+1, route, distance + dist[route[city-1]][i]);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &dist[i][j]);
    }
  }
  int route[MAX_CITIES];
  route[0] = 0; 
  find_route(1, route, 0);
  printf("Best route: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", best_route[i]);
  }
  printf("\nBest distance: %d\n", best_distance);
  return 0;
}
```
 The code is a brute force algorithm to solve the traveling salesman problem. It finds the shortest possible route that visits a given set of cities and returns to the starting city.

The code starts by including the standard input/output library and the standard library. Then it defines `MAX_CITIES` as 100 and `INF` as 1000000.

`n` is the number of cities. `dist[MAX_CITIES][MAX_CITIES]` is a 2D array that stores the distances between cities. `best_route[MAX_CITIES]` is an array that stores the best route found so far. `best_distance` is a variable that stores the best distance found so far, initialized to `INF`.

The function `find_route` is a recursive function that takes the current city, the current route, and the current distance as arguments. If all cities have been visited, it updates the best route and distance if the current distance plus the distance from the last city back to the starting city is less than the best distance.

In the `main` function, the number of cities is read from the input. The distances between cities are also read from the input. The first city is set as the starting city and the `find_route` function is called with the first city and a route array with the first city. The best route and distance are printed at the end.
*/
