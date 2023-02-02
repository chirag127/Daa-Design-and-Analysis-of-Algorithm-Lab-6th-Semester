write the codes in c following practical for my daa assignement 

Knapsack Problem using Greedy Solution: Implement a greedy algorithm to solve the knapsack problem, which is a combinatorial optimization problem.
 Here's a C program to solve the knapsack problem using a greedy algorithm:

```
#include<stdio.h>
#include<stdlib.h>

// Structure to store items
struct item {
    int value;
    int weight;
};

// Comparison function to sort items in descending order of value/weight ratio
int cmp(const void *a, const void *b) {
    struct item *ia = (struct item *)a;
    struct item *ib = (struct item *)b;
    float ratioA = (float)ia->value / ia->weight;
    float ratioB = (float)ib->value / ib->weight;
    return ratioB - ratioA;
}

// Function to solve knapsack problem using greedy algorithm
void knapsack(int n, int capacity, struct item *items) {
    qsort(items, n, sizeof(struct item), cmp);
    int currentWeight = 0;
    int currentValue = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            currentValue += items[i].value;
        } else {
            int remaining = capacity - currentWeight;
            currentValue += items[i].value * ((float)remaining / items[i].weight);
            break;
        }
    }
    printf("Maximum value: %d\n", currentValue);
}

int main() {
    int n = 3;
    int capacity = 50;
    struct item items[] = {{60, 10}, {100, 20}, {120, 30}};
    knapsack(n, capacity, items);
    return 0;
}
```
/*
 

```
#include<stdio.h>
#include<stdlib.h>
```
These are preprocessor directives to include the standard input/output library and the standard library in the program.

```
// Structure to store items
struct item {
    int value;
    int weight;
};
```
This defines a structure `item` with two integer members `value` and `weight`.

```
// Comparison function to sort items in descending order of value/weight ratio
int cmp(const void *a, const void *b) {
    struct item *ia = (struct item *)a;
    struct item *ib = (struct item *)b;
    float ratioA = (float)ia->value / ia->weight;
    float ratioB = (float)ib->value / ib->weight;
    return ratioB - ratioA;
}
```
This is a comparison function `cmp` to sort items in descending order of the ratio of `value` to `weight`. It takes two void pointers `a` and `b` and casts them to `struct item` pointers `ia` and `ib`. The ratios `ratioA` and `ratioB` are calculated and the function returns the difference `ratioB - ratioA`.

```
// Function to solve knapsack problem using greedy algorithm
void knapsack(int n, int capacity, struct item *items) {
    qsort(items, n, sizeof(struct item), cmp);
    int currentWeight = 0;
    int currentValue = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            currentValue += items[i].value;
        } else {
            int remaining = capacity - currentWeight;
            currentValue += items[i].value * ((float)remaining / items[i].weight);
            break;
        }
    }
    printf("Maximum value: %d\n", currentValue);
}
```
This is the main function `knapsack` to solve the knapsack problem using a greedy algorithm. It takes three arguments: `n`, the number of items; `capacity`, the maximum weight the knapsack can hold; and `items`, an array of `struct item` elements. The function sorts the items using the `qsort` function and the `cmp` comparison function. Then it initializes `currentWeight` and `currentValue` to 0. In the for loop, it adds each item to the knapsack if its weight does not exceed the remaining capacity. If the weight of the next item exceeds the remaining capacity, it calculates the fraction of the item that fits in the knapsack and adds that fraction to the current value. Finally, it prints the maximum value.

```
int main() {
    int n = 3;
    int capacity = 50;
    struct item items[] = {{60, 10}, {100, 20}, {120, 30}};
    knapsack(n, capacity, items);
    return 0;
}
```
This is the main function of the program. It initializes `n` to 3, `capacity` to 50, and `items` to an array of three `struct item` elements. Then it calls the `knapsack` function to solve the knapsack problem and returns 0.
*/
