write the codes in c following practical for my daa assignement 

Hamiltonian Cycles in a Graph using Backtracking: Implement a backtracking algorithm to find all Hamiltonian cycles in a connected undirected graph.
 Here's the code:

```
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, g[N][N];
int path[N];
bool vis[N];

bool is_safe(int v, int pos) {
    if (g[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamiltonian_cycle_util(int pos) {
    if (pos == n) {
        if (g[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < n; v++) {
        if (is_safe(v, pos)) {
            path[pos] = v;
            if (hamiltonian_cycle_util(pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamiltonian_cycle() {
    memset(path, -1, sizeof path);
    path[0] = 0;
    if (hamiltonian_cycle_util(1) == false) {
        cout << "Solution does not exist\n";
        return false;
    }
    cout << "Solution exists: \n";
    for (int i = 0; i < n; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
    return true;
}

int main() {
    cin >> n >> m;
    memset(g, 0, sizeof g);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    hamiltonian_cycle();
    return 0;
}
```
