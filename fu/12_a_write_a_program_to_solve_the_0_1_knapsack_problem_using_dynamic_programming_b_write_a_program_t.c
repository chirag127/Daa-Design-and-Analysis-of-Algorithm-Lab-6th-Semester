############################################################

(try to answer in C) 
(a) Write a program to solve the 0/1 Knapsack problem using dynamic programming. (b) Write a program to solve the 0/1 Knapsack problem using a greedy algorithm.

 Here's a program to solve the 0/1 Knapsack problem using dynamic programming in C:

```
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
  int i, w;
  int K[n + 1][W + 1];

  for (i = 0; i <= n; i++) {
    for (w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i - 1] <= w)
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }

  return K[n][W];
}

int main() {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int W = 50;
  int n = sizeof(val) / sizeof(val[0]);
  printf("%d", knapSack(W, wt, val, n));
  return 0;
}
```

And here's a program to solve the 0/1 Knapsack problem using a greedy algorithm in C:

```
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value, weight;
  float ratio;
} Item;

int compare(const void *a, const void *b) {
  Item *ia = (Item *)a;
  Item *ib = (Item *)b;
  return (int)(100.f * ib->ratio - 100.f * ia->ratio);
}

void knapSack(int W, Item arr[], int n) {
  int curWeight = 0;
  int finalValue = 0;

  qsort(arr, n, sizeof(arr[0]), compare);

  for (int i = 0; i < n; i++) {
    if (curWeight + arr[i].weight <= W) {
      curWeight += arr[i].weight;
      finalValue += arr[i].value;
    } else {
      int remain = W - curWeight;
      finalValue += arr[i].value * ((float)remain / arr[i].weight);
      break;
    }
  }

  printf("Final Value is: %d\n", finalValue);
}

int main() {
  Item arr[] = {{60, 10, 6}, {100, 20, 5}, {120, 30, 4}};
  int n = sizeof(arr) / sizeof(arr[0]);
  int W = 50;
  knapSack(W, arr, n);
  return 0;
}
```
