############################################################

(try to answer in C) 
Write a program to solve the Knapsack problem using a greedy algorithm.


```
#include <stdio.h>
#include <stdlib.h>

// structure for an item which stores weight and corresponding value 
struct Item 
{ 
    int value, weight; 
}; 

// Comparison function to sort Item according to val/weight ratio 
int cmp(const void *a, const void *b) 
{ 
    struct Item *a1 = (struct Item *)a; 
    struct Item *b1 = (struct Item *)b; 
    double r1 = (double)a1->value / a1->weight; 
    double r2 = (double)b1->value / b1->weight; 
    return r1 > r2 ? -1 : 1; 
} 

// Main greedy function to solve problem 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    // sorting Item on basis of ratio 
    qsort(arr, n, sizeof(arr[0]), cmp); 
  
    // Uncomment to see new order of Items with their ratio 
    /* 
    for (int i = 0; i < n; i++) 
    { 
        printf("%d  %d  %f\n", arr[i].value, arr[i].weight, 
                                           (double)arr[i].value / arr[i].weight); 
    } 
    */
  
    int curWeight = 0;  // Current weight in knapsack 
    double finalvalue = 0.0; // Result (value in Knapsack) 
  
    // Looping through all Items 
    for (int i = 0; i < n; i++) 
    { 
        // If adding Item won't overflow, add it completely 
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        // If we can't add current Item, add fractional part of it 
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
  
    // Returning final value 
    return finalvalue; 
} 

int main() 
{ 
    int W = 50;   // Weight of knapsack 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Maximum value we can obtain = %f", fractionalKnapsack(W, arr, n)); 
    return 0; 
} 
```
