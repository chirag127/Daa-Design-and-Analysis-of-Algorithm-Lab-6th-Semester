write the codes in c following practical for my daa assignement 

Subset Sum Problem: Implement an algorithm to find a subset of a given set of positive integers whose sum is equal to a given positive integer.
 Here's a code in C for the Subset Sum problem:

```
#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int sum)
{
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
```
/*


```
#include <stdio.h>
#include <stdbool.h>
```
- The first two lines include the standard input/output library and the boolean library in C.

```
bool isSubsetSum(int set[], int n, int sum)
{
   if (sum == 0)
     return true;
```
- `isSubsetSum` is a function that takes in an array of integers `set`, an integer `n` representing the size of the array, and an integer `sum`.
- If `sum` is equal to 0, the function returns `true`.

```
   if (n == 0 && sum != 0)
     return false;
```
- If `n` is equal to 0 and `sum` is not equal to 0, the function returns `false`.

```
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
```
- If the last element of the `set` array is greater than `sum`, the function returns the result of a recursive call to `isSubsetSum` with the same `set` array but with the size `n-1` and the same `sum`.

```
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}
```
- The function returns the result of two recursive calls to `isSubsetSum`. The first call has the same `set` array and `n`, but with `sum` unchanged. The second call has the same `set` array and `sum`, but with `n` decremented by 1.

```
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
```
- `main` is the main function of the program. It initializes an array of integers `set` with the values `{3, 34, 4, 12, 5, 2}`, an integer `sum` with the value `9`, and an integer `n` with the size of the `set` array.

```
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
```
- The program calls the `isSubsetSum` function with the `set` array, `n`, and `sum` as arguments. If the result is `true`, the program prints "Found a subset with given sum". If the result is `false`, the program prints "No subset with given sum".

```
  return 0;
}
```
- The `main` function returns 0, indicating a successful execution of the program.
*/
