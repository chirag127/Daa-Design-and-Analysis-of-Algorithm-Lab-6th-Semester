write the codes in c following practical for my daa assignement 

Traveling Salesman Problem: Implement an algorithm to find the shortest possible route that visits a given set of cities and returns to the starting city.
 Here's one way to solve TSP using the nearest neighbor algorithm in C:

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_CITIES 100
#define MAX_DISTANCE 1000000

int n; // number of cities
int cities[MAX_CITIES][2]; // x, y coordinates of cities
bool visited[MAX_CITIES]; // whether a city has been visited
int current_city; // current city
int total_distance; // total distance traveled

int distance(int city1, int city2) {
    int x = cities[city1][0] - cities[city2][0];
    int y = cities[city1][1] - cities[city2][1];
    return (int) sqrt(x*x + y*y);
}

int nearest_neighbor() {
    int min_distance = MAX_DISTANCE;
    int nearest_city = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance(current_city, i) < min_distance) {
            min_distance = distance(current_city, i);
            nearest_city = i;
        }
    }
    return nearest_city;
}

int main() {
    // read in the number of cities
    scanf("%d", &n);

    // read in the x, y coordinates of each city
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cities[i][0], &cities[i][1]);
    }

    // start at the first city
    current_city = 0;

    // repeat until all cities have been visited
    for (int i = 0; i < n; i++) {
        visited[current_city] = true;
        int nearest = nearest_neighbor();
        total_distance += distance(current_city, nearest);
        current_city = nearest;
    }

    // return to the starting city
    total_distance += distance(current_city, 0);

    // print the total distance
    printf("%d\n", total_distance);
    return 0;
}
```
/*
 

1. `#include <stdio.h>`, `#include <stdlib.h>`, `#include <stdbool.h>`, `#include <math.h>`: These are preprocessor directives that include the standard input/output library, the standard library, the boolean library, and the math library, respectively. These libraries provide functions used in the code.

2. `#define MAX_CITIES 100` and `#define MAX_DISTANCE 1000000`: These are constant definitions that set the maximum number of cities to 100 and the maximum distance to 1000000.

3. `int n; // number of cities`: This declares an integer variable `n` that represents the number of cities.

4. `int cities[MAX_CITIES][2]; // x, y coordinates of cities`: This declares a two-dimensional array `cities` that stores the x and y coordinates of each city.

5. `bool visited[MAX_CITIES]; // whether a city has been visited`: This declares a boolean array `visited` that keeps track of whether each city has been visited or not.

6. `int current_city; // current city`: This declares an integer variable `current_city` that represents the current city.

7. `int total_distance; // total distance traveled`: This declares an integer variable `total_distance` that represents the total distance traveled.

8. `int distance(int city1, int city2)`: This declares a function `distance` that calculates the distance between two cities. It takes two integer arguments `city1` and `city2` and returns the distance between them.

9. `int nearest_neighbor()`: This declares a function `nearest_neighbor` that finds the nearest unvisited city to the current city. It returns the index of the nearest city.

10. `scanf("%d", &n);`: This reads in the number of cities from the user.

11. `for (int i = 0; i < n; i++) { ... }`: This loop reads in the x and y coordinates of each city from the user.

12. `current_city = 0;`: This sets the current city to the first city.

13. `for (int i = 0; i < n; i++) { ... }`: This loop finds the nearest unvisited city and updates the current city and total distance until all cities have been visited.

14. `total_distance += distance(current_city, 0);`: This adds the distance from the current city back to the starting city to the total distance.

15. `printf("%d\n", total_distance);`: This prints the total distance.

16. `return 0;`: This returns 0 to indicate that the program has run successfully.
*/
