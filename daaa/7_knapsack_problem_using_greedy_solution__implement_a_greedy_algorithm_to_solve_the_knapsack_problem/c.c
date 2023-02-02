write the c code for practical for my daa assignement 

Knapsack Problem using Greedy Solution: Implement a greedy algorithm to solve the knapsack problem, which is a combinatorial optimization problem.
 
```
#include<bits/stdc++.h> 
using namespace std; 

// item structure 
struct item{ 
    int value, weight; 
}; 

// for sorting items in decreasing order of value/weight 
bool cmp(struct item a, struct item b){ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 

// function to get maximum value 
double fractionalKnapsack(int W, struct item arr[], int n){ 
    sort(arr, arr + n, cmp); 
    int curWeight = 0; 
    double finalvalue = 0.0; 
    for (int i = 0; i < n; i++){ 
        if (curWeight + arr[i].weight <= W){ 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
        else{ 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
    return finalvalue; 
} 

int main(){ 
    int W = 50; 
    item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Maximum value we can obtain = " 
         << fractionalKnapsack(W, arr, n); 
    return 0; 
} 
```
