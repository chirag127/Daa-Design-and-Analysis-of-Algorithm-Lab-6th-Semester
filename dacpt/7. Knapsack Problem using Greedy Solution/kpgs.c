#include <stdio.h>
#include <stdlib.h>

// Structure for items
struct Item
{
  int value;
  int weight;
};

// Function to compare two items based on their value-to-weight ratio
int cmp(const void *a, const void *b)
{
  struct Item *ia = (struct Item *)a;
  struct Item *ib = (struct Item *)b;
  double valuePerWeightA = (double)ia->value / ia->weight;
  double valuePerWeightB = (double)ib->value / ib->weight;
  return (valuePerWeightB > valuePerWeightA) - (valuePerWeightB < valuePerWeightA);
}

// Greedy function to find the maximum value for a knapsack of capacity W
double fractionalKnapsack(int W, struct Item arr[], int n)
{
  // Sort items based on their value-to-weight ratio
  qsort(arr, n, sizeof(struct Item), cmp);

  int currentWeight = 0;
  double currentValue = 0.0;

  for (int i = 0; i < n; i++)
  {
    // If adding the next item will not exceed the knapsack capacity
    if (currentWeight + arr[i].weight <= W)
    {
      // Add the next item completely
      currentWeight += arr[i].weight;
      currentValue += arr[i].value;
    }
    // If adding the next item will exceed the knapsack capacity
    else
    {
      // Add a fraction of the next item
      int remain = W - currentWeight;
      currentValue += arr[i].value * ((double)remain / arr[i].weight);
      break;
    }
  }

  return currentValue;
}

int main()
{
  int W = 50;
  struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Maximum value: %.2f\n", fractionalKnapsack(W, arr, n));
  return 0;
}
/* Here is the explanation for the code above:
1. The function takes two arguments. The first argument is a pointer to an array of struct items. The second argument is the size of the array.
2. The function initializes a variable named totalValue to 0.0. This variable will hold the total value of the items that will be chosen.
3. The function initializes a variable named totalWeight to 0.0. This variable will hold the total weight of the items that will be chosen.
4. The function sorts the array of items based on the value per weight. The qsort() function is used to sort the array. The qsort() function takes three arguments. The first argument is a pointer to the array to be sorted. The second argument is the size of the array. The third argument is the size of each element of the array. The last argument is a pointer to a function that will be used to compare two elements. The function that is used to compare two elements is defined as an anonymous function in line 37. The anonymous function is a comparison function that is used by the qsort() function to compare two elements of the array. The comparison function returns a negative value if the first argument is less than the second argument. The comparison function returns a positive value if the first argument is greater than the second argument. The comparison function returns 0 if the first argument is equal to the second argument. The comparison function returns a negative value if the value per weight of the first argument is less than the value per weight of the second argument. The comparison function returns a positive value if the value per weight of the first argument is greater than the value per weight of the second argument. The comparison function returns 0 if the value per weight of the first argument is equal to the value per weight of the second argument.
5. The function loops through the array of items. The loop starts at the last element of the array and ends at the first element of the array. The loop decrements the index by 1 each time.
6. The function checks if the total weight of the items that will be chosen is less than or equal to the maximum weight. The loop continues until the total weight of the items that will be chosen is greater than the maximum weight.
7. The function adds the value of the item at the current index to the total value of the items that will be chosen.
8. The function adds the weight of the item at the current index to the total weight of the items that will be chosen.
9. The function returns the total value of the items that will be chosen. */
