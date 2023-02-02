
#include <bits/stdc++.h>
using namespace std;

const int V = 100;
int path[V];
bool isVisited[V];

bool isSafe(int v, int graph[V][V], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamCycleUtil(int graph[V][V], int pos)
{
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, pos))
        {
            path[pos] = v;
            if (hamCycleUtil(graph, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(int graph[V][V])
{
    memset(path, -1, sizeof path);
    path[0] = 0;
    if (hamCycleUtil(graph, 1) == false)
    {
        cout << "\nSolution does not exist";
        return false;
    }
    return true;
}

int main()
{
    int graph[V][V] = {{0, 1, 0, 1, 0},
                       {1, 0, 1, 1, 1},
                       {0, 1, 0, 0, 1},
                       {1, 1, 0, 0, 1},
                       {0, 1, 1, 1, 0},
                      };
    hamCycle(graph);
    return 0;
}
```
/*


```
#include <bits/stdc++.h>
```
This line is the preprocessor directive to include the standard C++ library.

```
using namespace std;
```
This line specifies the use of the standard namespace, which is the standard library for C++.

```
const int V = 100;
int path[V];
bool isVisited[V];
```
Here, `V` is a constant integer that is set to 100. `path` is an array of integers with a size of `V`, and `isVisited` is an array of boolean values with a size of `V`.

```
bool isSafe(int v, int graph[V][V], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
```
This is the `isSafe` function, which takes 3 arguments: `v`, `graph`, and `pos`. The function returns `false` if the edge between `path[pos - 1]` and `v` is equal to 0. If the value of `v` is already present in `path`, the function returns `false`. If both conditions are not met, the function returns `true`.

```
bool hamCycleUtil(int graph[V][V], int pos)
{
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, pos))
        {
            path[pos] = v;
            if (hamCycleUtil(graph, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
```
This is the `hamCycleUtil` function, which takes 2 arguments: `graph` and `pos`. The function returns `true` if the value of `pos` is equal to `V` and the edge between `path[pos - 1]` and `path[0]` is equal to 1. If the value of `pos` is not equal to `V`, the function iterates through all values of `v` from 1 to `V - 1`. If the `isSafe` function returns `true` for a given value of `v`, the value of `v` is added to `path` and the function is called recursively with `pos + 1`. If the recursive call returns `false`, the value of `v` is set back to -1. If the function returns `false` for all values of `v`, the function returns `false`.

```
bool hamCycle(int graph[V][V])
{
    memset(path, -1, sizeof path);
    path[0] = 0;
    if (hamCycleUtil(graph, 1) == false)
    {
        cout << "\nSolution does not exist";
        return false;
    }
    return true;
}
```
This is the `hamCycle` function, which takes 1 argument: `graph`. The function sets all values in `path` to -1 using the `memset` function and sets the value of the first element in `path` to 0. The function returns `false` if the `hamCycleUtil` function returns `false`. If the `hamCycleUtil` function returns `true`, the function returns `true`.

```
int main()
{
    int graph[V][V] = {{0, 1, 0, 1, 0},
                       {1, 0, 1, 1, 1},
                       {0, 1, 0, 0, 1},
                       {1, 1, 0, 0, 1},
                       {0, 1, 1, 1, 0},
                      };
    hamCycle(graph);
    return 0;
}
```
This is the main function. It declares an array `graph` with values and calls the `hamCycle` function with `graph` as an argument. The function returns 0.
*/
