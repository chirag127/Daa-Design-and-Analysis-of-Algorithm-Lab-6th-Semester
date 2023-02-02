write the codes in c following practical for my daa assignement 

All-Pairs Shortest Paths & TSP using Floyd's & DP: Implement Floyd's algorithm to find all-pairs shortest paths in a weighted graph, and implement a dynamic programming solution to the traveling salesman problem.
 
```
#include<stdio.h>
#define MAX_NODES 100
#define INFINITY 99999

int n; // number of nodes
int w[MAX_NODES][MAX_NODES]; // adjacency matrix

void floyd() {
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
}

int tsp(int u, int mask) {
  if (mask == (1 << n) - 1) return w[u][0];
  int res = INFINITY;
  for (int v = 0; v < n; v++)
    if (!(mask & (1 << v)))
      res = min(res, w[u][v] + tsp(v, mask | (1 << v)));
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &w[i][j]);
  floyd();
  printf("%d\n", tsp(0, 1));
  return 0;
}
```
/*

1. `#include<stdio.h>`: This line includes the standard input/output library in the code.
2. `#define MAX_NODES 100`: This line defines a constant `MAX_NODES` with a value of 100.
3. `#define INFINITY 99999`: This line defines a constant `INFINITY` with a value of 99999.
4. `int n;`: This line declares a variable `n` which represents the number of nodes in the graph.
5. `int w[MAX_NODES][MAX_NODES];`: This line declares a 2D array `w` with dimensions `MAX_NODES x MAX_NODES` which represents the adjacency matrix of the graph.
6. `void floyd()`: This line declares a function `floyd` which implements the Floyd's algorithm to find all-pairs shortest paths in a weighted graph.
7. `for (int k = 0; k < n; k++)`: This line starts a for loop which iterates `k` from 0 to `n-1`.
8. `for (int i = 0; i < n; i++)`: This line starts a nested for loop which iterates `i` from 0 to `n-1`.
9. `for (int j = 0; j < n; j++)`: This line starts another nested for loop which iterates `j` from 0 to `n-1`.
10. `w[i][j] = min(w[i][j], w[i][k] + w[k][j]);`: This line updates the value of `w[i][j]` as the minimum of its current value and the sum of `w[i][k]` and `w[k][j]`.
11. `int tsp(int u, int mask)`: This line declares a function `tsp` which implements a dynamic programming solution to the traveling salesman problem.
12. `if (mask == (1 << n) - 1) return w[u][0];`: This line checks if the `mask` is equal to `(1 << n) - 1`, if true, the function returns `w[u][0]`.
13. `int res = INFINITY;`: This line declares a variable `res` with an initial value of `INFINITY`.
14. `for (int v = 0; v < n; v++)`: This line starts a for loop which iterates `v` from 0 to `n-1`.
15. `if (!(mask & (1 << v)))`: This line checks if the `v`th bit of `mask` is not set, if true, it proceeds to the next line.
16. `res = min(res, w[u][v] + tsp(v, mask | (1 << v)));`: This line updates the value of `res` as the minimum of its current value and the sum of `w[u][v]` and the result of `tsp(v, mask | (1 << v))`.
17. `return res;`: This line returns the value of `res`.
18. `int main()`: This line declares the main function of the program.
19. `scanf("%d", &n);`: This line reads the value of `n` from the input.
20. `for (int i = 0; i < n; i++)`: This line starts a for loop which iterates `i` from 0 to `n-1`.
21. `for (int j = 0; j < n; j++)`: This line starts a nested for loop which iterates `j` from 0 to `n-1`.
22. `scanf("%d", &w[i][j]);`: This line reads the value of `w[i][j]` from the input.
23. `floyd();`: This line calls the `floyd` function.
24. `printf("%d\n", tsp(0, 1));`: This line prints the result of `tsp(0, 1)` to the output.
25. `return 0;`: This line returns 0 from the main function.
*/
