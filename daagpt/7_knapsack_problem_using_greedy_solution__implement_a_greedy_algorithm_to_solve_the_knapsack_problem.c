write the codes in c following practical for my daa assignement 

Knapsack Problem using Greedy Solution: Implement a greedy algorithm to solve the knapsack problem, which is a combinatorial optimization problem.
 Here's a code for solving the knapsack problem using a greedy algorithm in C:

```
#include <stdio.h> 
#include <stdbool.h> 

#define MAX_ITEMS 100 
#define MAX_WEIGHT 100 

int n; 
int weight[MAX_ITEMS]; 
int value[MAX_ITEMS]; 

bool taken[MAX_ITEMS]; 

int knapsack(int n, int weight[], int value[], int maxWeight) 
{ 
    int curWeight = 0; 
    int curValue = 0; 
  
    for (int i = 0; i < n; i++) 
    { 
        if (curWeight + weight[i] <= maxWeight) 
        { 
            taken[i] = true; 
            curWeight += weight[i]; 
            curValue += value[i]; 
        } 
        else
        { 
            taken[i] = false; 
        } 
    } 
  
    return curValue; 
} 

int main() 
{ 
    int maxWeight; 
  
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) 
    { 
        scanf("%d%d", &weight[i], &value[i]); 
    } 
  
    scanf("%d", &maxWeight); 
  
    int maxValue = knapsack(n, weight, value, maxWeight); 
  
    printf("%d\n", maxValue); 
  
    return 0; 
} 
```
/*
explain the following code 

 Here's a code for solving the knapsack problem using a greedy algorithm in C:

```
#include <stdio.h> 
#include <stdbool.h> 

#define MAX_ITEMS 100 
#define MAX_WEIGHT 100 

int n; 
int weight[MAX_ITEMS]; 
int value[MAX_ITEMS]; 

bool taken[MAX_ITEMS]; 

int knapsack(int n, int weight[], int value[], int maxWeight) 
{ 
    int curWeight = 0; 
    int curValue = 0; 
  
    for (int i = 0; i < n; i++) 
    { 
        if (curWeight + weight[i] <= maxWeight) 
        { 
            taken[i] = true; 
            curWeight += weight[i]; 
            curValue += value[i]; 
        } 
        else
        { 
            taken[i] = false; 
        } 
    } 
  
    return curValue; 
} 

int main() 
{ 
    int maxWeight; 
  
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) 
    { 
        scanf("%d%d", &weight[i], &value[i]); 
    } 
  
    scanf("%d", &maxWeight); 
  
    int maxValue = knapsack(n, weight, value, maxWeight); 
  
    printf("%d\n", maxValue); 
  
    return 0; 
} 
```
 The code is a C implementation of a greedy algorithm to solve the knapsack problem. 

- The `#include` statements include the standard input/output library and the `stdbool.h` header file, which defines the `bool` data type.
- The `MAX_ITEMS` and `MAX_WEIGHT` macros define the maximum number of items and maximum weight that the knapsack can hold, respectively.
- The `n` variable stores the number of items.
- The `weight` and `value` arrays store the weight and value of each item, respectively.
- The `taken` array stores a boolean value indicating whether an item has been taken or not.
- The `knapsack` function takes four arguments: the number of items `n`, the weight and value arrays, and the maximum weight `maxWeight` of the knapsack. The function calculates the maximum value that can be obtained by taking items with the maximum weight constraint.
- The `main` function reads the number of items `n`, the weight and value of each item, and the maximum weight of the knapsack. It then calls the `knapsack` function to get the maximum value and prints it.
*/
