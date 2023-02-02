write the c code for practical for my daa assignement 

0/1 Knapsack Problem: Implement the 0/1 knapsack problem using either dynamic programming or greedy method.
 Here's the code for 0/1 knapsack problem using dynamic programming:

```
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,w[N],v[N],f[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }
    cout<<f[m];
    return 0;
}
```

And here's the code for 0/1 knapsack problem using greedy method:

```
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,w[N],v[N];
bool cmp(int a,int b){
    return 1.0*v[a]/w[a]>1.0*v[b]/w[b];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    vector<int> id;
    for(int i=1;i<=n;i++) id.push_back(i);
    sort(id.begin(),id.end(),cmp);
    int ans=0;
    for(int i=0;i<n;i++){
        int j=id[i];
        if(m>=w[j]){
            ans+=v[j];
            m-=w[j];
        }
        else{
            ans+=1.0*v[j]/w[j]*m;
            break;
        }
    }
    cout<<ans;
    return 0;
}
```
