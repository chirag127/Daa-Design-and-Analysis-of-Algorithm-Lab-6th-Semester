
#include <bits/stdc++.h>
using namespace std;

struct item {
  int weight, value;
};

bool cmp(item a, item b) {
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

double fractional_knapsack(int W, item arr[], int n) {
  sort(arr, arr + n, cmp);

  int curWeight = 0;
  double finalvalue = 0.0;

  for (int i = 0; i < n; i++) {
    if (curWeight + arr[i].weight <= W) {
      curWeight += arr[i].weight;
      finalvalue += arr[i].value;
    } else {
      int remain = W - curWeight;
      finalvalue += arr[i].value * ((double) remain / arr[i].weight);
      break;
    }
  }
  return finalvalue;
}

int main() {
  int W = 50;
  item arr[] = {{10, 60}, {20, 100}, {30, 120}};

  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Maximum value we can obtain = "
       << fractional_knapsack(W, arr, n);
  return 0;
}
/*


```
#include <bits/stdc++.h>
```
This line is a preprocessor directive to include the standard C++ library. It includes all the standard libraries in C++.

```
using namespace std;
```
This line allows the use of standard library functions without the need to qualify with std::.

```
struct item {
  int weight, value;
};
```
This line defines a struct `item` with two integer member variables `weight` and `value`.

```
bool cmp(item a, item b) {
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}
```
This function `cmp` is used to sort the items in the knapsack. It takes two struct `item` variables `a` and `b` as parameters. It calculates the ratio of value to weight for each item and returns `true` if the ratio of the first item is greater than the ratio of the second item.

```
double fractional_knapsack(int W, item arr[], int n) {
  sort(arr, arr + n, cmp);

  int curWeight = 0;
  double finalvalue = 0.0;

  for (int i = 0; i < n; i++) {
    if (curWeight + arr[i].weight <= W) {
      curWeight += arr[i].weight;
      finalvalue += arr[i].value;
    } else {
      int remain = W - curWeight;
      finalvalue += arr[i].value * ((double) remain / arr[i].weight);
      break;
    }
  }
  return finalvalue;
}
```
This function `fractional_knapsack` implements the greedy algorithm to solve the knapsack problem. It takes an integer `W` which is the maximum weight that the knapsack can hold, an array of struct `item` `arr`, and an integer `n` which is the number of items.

The function sorts the items in the knapsack based on the ratio of value to weight using the `cmp` function.

The function then loops through the items and adds them to the knapsack if the current weight plus the weight of the item is less than or equal to the maximum weight `W`. If the current weight plus the weight of the item is greater than the maximum weight `W`, the function calculates the fraction of the item to add to the knapsack and adds that amount to the final value.

```
int main() {
  int W = 50;
  item arr[] = {{10, 60}, {20, 100}, {30, 120}};

  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Maximum value we can obtain = "
       << fractional_knapsack(W, arr, n);
  return 0;
}
```
This is the main function of the program. It initializes the maximum weight `W` to 50, the array of items `arr` with three items, and the number of items `n`.

The function then calls the `fractional_knapsack` function and outputs the maximum value that can be obtained.
*/
