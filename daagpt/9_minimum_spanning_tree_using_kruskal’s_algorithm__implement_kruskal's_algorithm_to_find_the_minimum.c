write the codes in c following practical for my daa assignement 

Minimum Spanning Tree using Kruskal’s Algorithm: Implement Kruskal's algorithm to find the minimum spanning tree of a connected undirected graph.
 
```
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,m,f[N];
vector<pair<int,pair<int,int> > > e;

int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e.push_back({z,{x,y}});
    }
    sort(e.begin(),e.end());
    int cnt=0,ans=0;
    for(int i=0;i<m;i++){
        int x=e[i].second.first,y=e[i].second.second;
        int fx=find(x),fy=find(y);
        if(fx!=fy){
            f[fx]=fy;
            cnt++;
            ans+=e[i].first;
            if(cnt==n-1) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
```
/*
explain the following code 

 
```
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,m,f[N];
vector<pair<int,pair<int,int> > > e;

int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e.push_back({z,{x,y}});
    }
    sort(e.begin(),e.end());
    int cnt=0,ans=0;
    for(int i=0;i<m;i++){
        int x=e[i].second.first,y=e[i].second.second;
        int fx=find(x),fy=find(y);
        if(fx!=fy){
            f[fx]=fy;
            cnt++;
            ans+=e[i].first;
            if(cnt==n-1) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
```

This code implements Kruskal's algorithm to find the minimum spanning tree of a connected undirected graph. The input consists of the number of nodes `n` and edges `m` in the graph, followed by `m` lines each containing `x`, `y`, and `z` representing an edge between node `x` and node `y` with weight `z`. 

The code uses an array `f` to store the parent node of each node in the graph. The `find` function returns the parent node of a node. The `main` function sorts the edges based on their weights and adds edges to the minimum spanning tree if they do not form a cycle. The sum of the weights of the edges added to the minimum spanning tree is stored in `ans`. The final answer is printed.
*/
