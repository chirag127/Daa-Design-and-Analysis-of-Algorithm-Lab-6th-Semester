write the c code for practical for my daa assignement 

Subset Sum Problem: Implement an algorithm to find a subset of a given set of positive integers whose sum is equal to a given positive integer.
 
```
#include <stdio.h>
#define MAX_NUMBERS 100

int numbers[MAX_NUMBERS];
int n, target_sum;

int subset_sum(int current_index, int current_sum) {
  if (current_sum == target_sum) {
    return 1;
  }
  if (current_index == n) {
    return 0;
  }
  if (current_sum > target_sum) {
    return 0;
  }
  return subset_sum(current_index + 1, current_sum + numbers[current_index]) ||
         subset_sum(current_index + 1, current_sum);
}

int main() {
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &numbers[i]);
  }
  printf("Enter the target sum: ");
  scanf("%d", &target_sum);
  if (subset_sum(0, 0)) {
    printf("A subset with the target sum exists.\n");
  } else {
    printf("No subset with the target sum exists.\n");
  }
  return 0;
}
```
