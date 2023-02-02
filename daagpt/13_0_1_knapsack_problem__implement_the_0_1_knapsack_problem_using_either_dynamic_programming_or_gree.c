
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int n,m,w[1005],v[1005],f[1005];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&v[i]);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=w[i];j--)
            f[j]=max(f[j],f[j-w[i]]+v[i]);
    printf("%d\n",f[m]);
    return 0;
}
```
/*


```
#include<stdio.h>
```
This line includes the standard input/output library in the code.

```
#define max(a,b) ((a)>(b)?(a):(b))
```
This line defines a macro `max` that returns the maximum of two values `a` and `b`. The macro uses a ternary operator to return the maximum value.

```
int n,m,w[1005],v[1005],f[1005];
```
These lines declare the following variables:
- `n` and `m` are integers that represent the number of items and the knapsack capacity, respectively.
- `w[1005]` and `v[1005]` are arrays of integers that represent the weight and value of each item, respectively.
- `f[1005]` is an array of integers that represents the maximum value that can be obtained for each knapsack capacity.

```
int main(){
    scanf("%d%d",&n,&m);
```
This line reads the values of `n` and `m` from the standard input.

```
    for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&v[i]);
```
This loop reads the values of `w[i]` and `v[i]` for each item `i` from the standard input.

```
    for(int i=1;i<=n;i++)
        for(int j=m;j>=w[i];j--)
            f[j]=max(f[j],f[j-w[i]]+v[i]);
```
This double loop implements the dynamic programming algorithm for the 0/1 knapsack problem. The outer loop iterates over each item `i`. The inner loop iterates over each knapsack capacity `j` from `m` to `w[i]` (in reverse order). The line `f[j]=max(f[j],f[j-w[i]]+v[i])` updates the maximum value that can be obtained for knapsack capacity `j` by either keeping the previous maximum value (`f[j]`) or taking the current item `i` (`f[j-w[i]]+v[i]`).

```
    printf("%d\n",f[m]);
    return 0;
}
```
This line prints the maximum value that can be obtained for knapsack capacity `m`, and the function returns 0 to indicate success.
*/
