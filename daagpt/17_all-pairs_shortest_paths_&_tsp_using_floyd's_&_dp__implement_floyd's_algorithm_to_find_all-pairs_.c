write the codes in c following practical for my daa assignement 

All-Pairs Shortest Paths & TSP using Floyd's & DP: Implement Floyd's algorithm to find all-pairs shortest paths in a weighted graph, and implement a dynamic programming solution to the traveling salesman problem.
 
```
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, dist[N][N];

void floyd() {
    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int tsp(int pos, int bitmask) {
    if (bitmask == (1 << n) - 1) return dist[pos][0];
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (bitmask & (1 << i)) continue;
        ans = min(ans, dist[pos][i] + tsp(i, bitmask | (1 << i)));
    }
    return ans;
}

int main() {
    cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
    floyd();
    cout << tsp(0, 1) << endl;
    return 0;
}
```
