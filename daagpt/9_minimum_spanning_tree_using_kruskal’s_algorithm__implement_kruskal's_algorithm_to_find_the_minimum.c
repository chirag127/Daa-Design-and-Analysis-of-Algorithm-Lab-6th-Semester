write the codes in c following practical for my daa assignement 

Minimum Spanning Tree using Kruskal’s Algorithm: Implement Kruskal's algorithm to find the minimum spanning tree of a connected undirected graph.

```
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int p[N];

struct edge{
    int u,v,w;
};

bool cmp(edge a,edge b){
    return a.w<b.w;
}

int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

void kruskal(vector<edge> e,int n,int m){
    sort(e.begin(),e.end(),cmp);
    for(int i=0;i<=n;i++) p[i]=i;
    int cnt=0,ans=0;
    for(int i=0;i<m;i++){
        int x=find(e[i].u),y=find(e[i].v);
        if(x!=y){
            p[x]=y;
            cnt++;
            ans+=e[i].w;
            if(cnt==n-1) break;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<edge> e(m);
    for(int i=0;i<m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    kruskal(e,n,m);
    return 0;
}
```
