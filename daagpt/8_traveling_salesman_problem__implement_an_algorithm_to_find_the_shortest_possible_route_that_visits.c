write the codes in c following practical for my daa assignement 

Traveling Salesman Problem: Implement an algorithm to find the shortest possible route that visits a given set of cities and returns to the starting city.
 Here is a sample code in C for the Traveling Salesman Problem using the nearest neighbor algorithm:

```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CITIES 100
#define MAX_DISTANCE 1000000

struct City {
  int x;
  int y;
};

int n;
struct City cities[MAX_CITIES];
int path[MAX_CITIES];
int visited[MAX_CITIES];
int min_distance;

int distance(struct City a, struct City b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

void find_path(int current_city, int current_distance) {
  if (current_distance >= min_distance) {
    return;
  }
  if (current_city == 0) {
    min_distance = current_distance;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      path[current_city] = i;
      visited[i] = 1;
      find_path(i, current_distance + distance(cities[current_city], cities[i]));
      visited[i] = 0;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &cities[i].x, &cities[i].y);
  }
  min_distance = MAX_DISTANCE;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[j] = 0;
    }
    path[0] = i;
    visited[i] = 1;
    find_path(i, 0);
    visited[i] = 0;
  }
  printf("%d\n", min_distance);
  return 0;
}
```
