write the codes in c following practical for my daa assignement 

Traveling Salesman Problem: Implement an algorithm to find the shortest possible route that visits a given set of cities and returns to the starting city.
 Here's a code in C for solving TSP using the nearest neighbor algorithm:

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_CITIES 100

typedef struct {
  int x, y;
} City;

double dist(City a, City b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int n;
  City cities[MAX_CITIES];
  bool visited[MAX_CITIES];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &cities[i].x, &cities[i].y);
    visited[i] = false;
  }

  int current = 0;
  double total_distance = 0;
  for (int i = 0; i < n; i++) {
    visited[current] = true;
    int next = -1;
    double min_distance = 1e9;
    for (int j = 0; j < n; j++) {
      if (!visited[j]) {
        double d = dist(cities[current], cities[j]);
        if (d < min_distance) {
          min_distance = d;
          next = j;
        }
      }
    }
    total_distance += min_distance;
    current = next;
  }
  total_distance += dist(cities[current], cities[0]);

  printf("Total distance: %lf\n", total_distance);

  return 0;
}
```
/*


```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
```
This section includes the standard libraries for input/output, memory allocation, boolean variables, and mathematical functions.

```
#define MAX_CITIES 100
```
This line defines a constant `MAX_CITIES` with a value of 100, which sets the maximum number of cities that can be processed in the program.

```
typedef struct {
  int x, y;
} City;
```
This line defines a new data type `City` that consists of two integer variables `x` and `y`, representing the coordinates of a city.

```
double dist(City a, City b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}
```
This function calculates the Euclidean distance between two cities `a` and `b`. The distance is calculated as the square root of the sum of the squares of the differences between the `x` and `y` coordinates of the two cities.

```
int main() {
  int n;
  City cities[MAX_CITIES];
  bool visited[MAX_CITIES];
```
This section declares the main function of the program. `n` is the number of cities, `cities` is an array of `City` structures to store the coordinates of the cities, and `visited` is a boolean array to keep track of which cities have been visited.

```
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &cities[i].x, &cities[i].y);
    visited[i] = false;
  }
```
This section reads the number of cities `n` from the input and then reads the coordinates of each city and initializes the `visited` array to false.

```
  int current = 0;
  double total_distance = 0;
  for (int i = 0; i < n; i++) {
    visited[current] = true;
    int next = -1;
    double min_distance = 1e9;
    for (int j = 0; j < n; j++) {
      if (!visited[j]) {
        double d = dist(cities[current], cities[j]);
        if (d < min_distance) {
          min_distance = d;
          next = j;
        }
      }
    }
    total_distance += min_distance;
    current = next;
  }
```
This section implements the nearest neighbor algorithm to find the shortest route that visits all cities and returns to the starting city. The algorithm starts at the first city (`current = 0`) and finds the nearest unvisited city (`next`) using the `dist` function. The distance to the nearest city is added to the total distance (`total_distance`) and the current city becomes the next city. The process is repeated until all cities have been visited.

```
  total_distance += dist(cities[current], cities[0]);
```
This line adds the distance from the last city back to the starting city to the total distance.

```
  printf("Total distance: %lf\n", total_distance);

  return 0;
}
```
This section prints the total distance and returns 0 to indicate that the program has completed successfully.
*/
