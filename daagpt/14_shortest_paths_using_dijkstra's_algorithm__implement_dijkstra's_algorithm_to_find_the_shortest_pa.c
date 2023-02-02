write the codes in c following practical for my daa assignement 

Shortest Paths using Dijkstra's Algorithm: Implement Dijkstra's algorithm to find the shortest paths from a given vertex to all other vertices in a weighted connected graph.

```
#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long
#define pii pair<int, int>
#define pb push_back

vector<pii> adj[MAX];
int dist[MAX];
bool vis[MAX];

void dijkstra(int src)
{
    memset(dist, 0x3f, sizeof dist);
    memset(vis, false, sizeof vis);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m, x, y, w, src;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    cin >> src;
    dijkstra(src);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}
```
