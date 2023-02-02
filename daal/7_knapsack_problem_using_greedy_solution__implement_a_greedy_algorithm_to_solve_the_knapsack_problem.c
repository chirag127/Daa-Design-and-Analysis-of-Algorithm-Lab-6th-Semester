write the c code for practical for my daa assignement 

Knapsack Problem using Greedy Solution: Implement a greedy algorithm to solve the knapsack problem, which is a combinatorial optimization problem.
 Here's the code for a knapsack problem using a greedy solution in C:
```
#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))

typedef struct {
    int value;
    int weight;
    float ratio;
} item;

int compare(const void *a, const void *b) {
    item *ia = (item *)a;
    item *ib = (item *)b;
    return (int)(100.0f*ib->ratio - 100.0f*ia->ratio);
}

void knapsack(item items[], int n, int capacity) {
    int i, space;
    int value = 0;

    qsort(items, n, sizeof(item), compare);

    for (i = 0, space = capacity; i < n; i++) {
        if (space >= items[i].weight) {
            value += items[i].value;
            space -= items[i].weight;
        } else {
            value += space * items[i].ratio;
            break;
        }
    }

    printf("Value: %d\n", value);
}

int main() {
    item items[] = {{60, 10, 6.0f}, {100, 20, 5.0f}, {120, 30, 4.0f}};
    int n = sizeof(items) / sizeof(item);
    int capacity = 50;

    knapsack(items, n, capacity);

    return 0;
}
```
/*
 
- `#include<stdio.h>` and `#include<stdlib.h>` are header files that provide access to standard input/output and general library functions in C.
- `#define max(a,b) ((a)>(b)?(a):(b))` defines a macro `max` that takes two arguments and returns the maximum value of the two.
- `typedef struct { int value; int weight; float ratio;} item;` defines a new data type `item` that consists of three fields: `value`, `weight`, and `ratio`.
- `int compare(const void *a, const void *b)` is a comparison function used by `qsort` to sort an array of `item`s based on their `ratio` field.
- `void knapsack(item items[], int n, int capacity)` implements the greedy algorithm to solve the knapsack problem. It sorts the items in decreasing order of their `ratio` field, then iterates over the items and adds the maximum value item to the knapsack until it's full.
- `int main()` is the main function that defines the problem instance and calls the `knapsack` function to solve it.
- `item items[] = {{60, 10, 6.0f}, {100, 20, 5.0f}, {120, 30, 4.0f}}` is an array of `item`s with three elements.
- `int n = sizeof(items) / sizeof(item)` calculates the number of items in the array.
- `int capacity = 50` is the capacity of the knapsack.
- `knapsack(items, n, capacity)` calls the `knapsack` function to solve the problem.
- `printf("Value: %d\n", value)` outputs the total value of the items in the knapsack.
- `return 0` returns 0 from the `main` function to indicate successful execution.
*/
/*

- `#include<stdio.h>` and `#include<stdlib.h>` are like helpers that let us use some special tools to make our program work.
- `#define max(a,b) ((a)>(b)?(a):(b))` is like a magic word that helps us find the biggest number out of two numbers.
- `typedef struct { int value; int weight; float ratio;} item;` is like a box that has three things inside: `value`, `weight`, and `ratio`.
- `int compare(const void *a, const void *b)` is a helper that helps us sort the boxes in a special way.
- `void knapsack(item items[], int n, int capacity)` is like a smart robot that knows how to put things in a bag to make the most valuable bag.
- `int main()` is like the boss of the program that tells the robot what to do.
- `item items[] = {{60, 10, 6.0f}, {100, 20, 5.0f}, {120, 30, 4.0f}}` is like a bunch of boxes that the robot will put in the bag.
- `int n = sizeof(items) / sizeof(item)` is like counting how many boxes there are.
- `int capacity = 50` is like the size of the bag that the robot will use.
- `knapsack(items, n, capacity)` is like telling the robot to start working.
- `printf("Value: %d\n", value)` is like telling us how valuable the bag is after the robot is done.
- `return 0` is like telling the boss that the program is done and everything is okay.
*/
