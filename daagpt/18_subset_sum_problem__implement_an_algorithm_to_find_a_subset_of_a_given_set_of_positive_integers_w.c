write the codes in c following practical for my daa assignement 

Subset Sum Problem: Implement an algorithm to find a subset of a given set of positive integers whose sum is equal to a given positive integer.
 
```
#include <stdio.h>

int isSubsetSum(int set[], int n, int sum) {
  if (sum == 0) return 1;
  if (n == 0 && sum != 0) return 0;
  if (set[n - 1] > sum) return isSubsetSum(set, n - 1, sum);
  return isSubsetSum(set, n - 1, sum) ||
         isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
  int n, sum;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int set[n];
  printf("Enter elements: ");
  for (int i = 0; i < n; i++) scanf("%d", &set[i]);
  printf("Enter sum: ");
  scanf("%d", &sum);

  if (isSubsetSum(set, n, sum) == 1)
    printf("Found a subset with given sum\n");
  else
    printf("No subset with given sum\n");

  return 0;
}
```
This code implements a recursive algorithm to solve the Subset Sum problem. The `isSubsetSum()` function returns 1 if there exists a subset of the given set with sum equal to the given sum, and 0 otherwise. The function takes in the set, the number of elements in the set, and the sum to be found as arguments. The function first checks if the sum is 0, in which case it returns 1 as the empty subset has sum 0. If the number of elements is 0 and the sum is not 0, it returns 0 as no subset can be found. If the last element of the set is greater than the sum, it ignores this element and calls the function with the rest of the set and the same sum. Otherwise, it calls the function with the rest of the set and the sum minus the last element, as well as with the rest of the set and the same sum. If either of these calls returns 1, the function returns 1, otherwise it returns 0. The `main()` function prompts the user to enter the number of elements in the set and the elements themselves, as well as the sum to be found. It then calls the `isSubsetSum()` function and prints the result.
/*
explain the following code 

 
```
#include <stdio.h>

int isSubsetSum(int set[], int n, int sum) {
  if (sum == 0) return 1;
  if (n == 0 && sum != 0) return 0;
  if (set[n - 1] > sum) return isSubsetSum(set, n - 1, sum);
  return isSubsetSum(set, n - 1, sum) ||
         isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
  int n, sum;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int set[n];
  printf("Enter elements: ");
  for (int i = 0; i < n; i++) scanf("%d", &set[i]);
  printf("Enter sum: ");
  scanf("%d", &sum);

  if (isSubsetSum(set, n, sum) == 1)
    printf("Found a subset with given sum\n");
  else
    printf("No subset with given sum\n");

  return 0;
}
```
This code implements a recursive algorithm to solve the Subset Sum problem. The `isSubsetSum()` function returns 1 if there exists a subset of the given set with sum equal to the given sum, and 0 otherwise. The function takes in the set, the number of elements in the set, and the sum to be found as arguments. The function first checks if the sum is 0, in which case it returns 1 as the empty subset has sum 0. If the number of elements is 0 and the sum is not 0, it returns 0 as no subset can be found. If the last element of the set is greater than the sum, it ignores this element and calls the function with the rest of the set and the same sum. Otherwise, it calls the function with the rest of the set and the sum minus the last element, as well as with the rest of the set and the same sum. If either of these calls returns 1, the function returns 1, otherwise it returns 0. The `main()` function prompts the user to enter the number of elements in the set and the elements themselves, as well as the sum to be found. It then calls the `isSubsetSum()` function and prints the result.
 
The code is an implementation of a recursive algorithm to solve the Subset Sum problem. The Subset Sum problem is to determine if there exists a subset of a given set of positive integers whose sum is equal to a given positive integer. The `isSubsetSum()` function returns 1 if there exists a subset of the given set with sum equal to the given sum, and 0 otherwise. The function takes in the set, the number of elements in the set, and the sum to be found as arguments. The function first checks if the sum is 0, in which case it returns 1 as the empty subset has sum 0. If the number of elements is 0 and the sum is not 0, it returns 0 as no subset can be found. If the last element of the set is greater than the sum, it ignores this element and calls the function with the rest of the set and the same sum. Otherwise, it calls the function with the rest of the set and the sum minus the last element, as well as with the rest of the set and the same sum. If either of these calls returns 1, the function returns 1, otherwise it returns 0. The `main()` function prompts the user to enter the number of elements in the set and the elements themselves, as well as the sum to be found. It then calls the `isSubsetSum()` function and prints the result.
*/
