write the c code for practical for my daa assignement 

0/1 Knapsack Problem: Implement the 0/1 knapsack problem using either dynamic programming or greedy method.
 

```
#include<bits/stdc++.h> 
using namespace std; 

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
   
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
   
   return K[n][W]; 
} 

int main() 
{ 
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    cout << knapSack(W, wt, val, n); 
    return 0; 
} 
```
/*


1. `#include<bits/stdc++.h>`: This line is a preprocessor directive that includes the standard library header `bits/stdc++.h`. This header file contains a collection of functions and macros that are commonly used in C++ programming.

2. `using namespace std;`: This line specifies that the standard namespace `std` is being used in the program. All the standard library functions and objects will be accessible without the `std::` prefix.

3. `int knapSack(int W, int wt[], int val[], int n)`: This line declares a function `knapSack` that takes four arguments: `W` (knapsack capacity), `wt` (an array of weights), `val` (an array of values), and `n` (number of items). The function returns an integer.

4. `int i, w;`: These lines declare two integer variables `i` and `w` that will be used in the loops.

5. `int K[n+1][W+1];`: This line declares a two-dimensional integer array `K` with `n+1` rows and `W+1` columns. This array will be used to store the intermediate results of the dynamic programming algorithm.

6. `for (i = 0; i <= n; i++)`: This line starts a for loop that will run `n+1` times. The variable `i` is used as the row index of the `K` array.

7. `for (w = 0; w <= W; w++)`: This line starts a nested for loop that will run `W+1` times. The variable `w` is used as the column index of the `K` array.

8. `if (i==0 || w==0)`: This line checks if either `i` or `w` is equal to 0. If either condition is true, then the value of `K[i][w]` is set to 0.

9. `else if (wt[i-1] <= w)`: This line checks if the weight of item `i-1` is less than or equal to the current value of `w`. If this condition is true, then the value of `K[i][w]` is set to the maximum of `val[i-1] + K[i-1][w-wt[i-1]]` and `K[i-1][w]`.

10. `else`: If the condition in line 9 is false, then the value of `K[i][w]` is set to `K[i-1][w]`.

11. `return K[n][W];`: This line returns the value stored in `K[n][W]`, which represents the maximum value that can be put in the knapsack of capacity `W`.

12. `int main()`: This line declares the main function of the program.

13. `int val[] = {60, 100, 120};`: This line declares an integer array `val` with three values: 60, 100, and 120. These values represent the values of the items in the knapsack problem.

14. `int wt[] = {10, 20, 30};`: This line declares an integer array `wt` with three values: 10, 20, and 30. These values represent the weights of the items in the knapsack problem.

15. `int W = 50;`: This line declares an integer variable `W` with a value of 50. This value represents the capacity of the knapsack.

16. `int n = sizeof(val)/sizeof(val[0]);`: This line declares an integer variable `n` with a value equal to the number of items in the knapsack problem. This value is calculated by dividing the size of the `val` array by the size of a single element of the `val` array.

17. `cout << knapSack(W, wt, val, n);`: This line calls the `knapSack` function and prints the result to the standard output stream (the screen).

18. `return 0;`: This line returns 0 to indicate that the program has executed successfully.
*/
/*
 

1. `#include<bits/stdc++.h>`: This line is like opening a big toy box with lots of toys inside. We can use any toy we want from the box.

2. `using namespace std;`: This line is like saying "I want to play with the toys from the `std` box".

3. `int knapSack(int W, int wt[], int val[], int n)`: This line is like making a new toy. The toy has 4 parts: `W` (a big bag), `wt` (a bunch of candies with different weights), `val` (a bunch of candies with different values), and `n` (the number of candies). The toy will tell us the most valuable candies we can put in the big bag.

4. `int i, w;`: These lines are like making two small toys, `i` and `w`, that we will use to play with the big toy.

5. `int K[n+1][W+1];`: This line is like making a big toy box with `n+1` rows and `W+1` columns. We will use this toy box to store our results while playing with the big toy.

6. `for (i = 0; i <= n; i++)`: This line is like playing with the big toy `n+1` times. We use the small toy `i` to pick the row in the big toy box.

7. `for (w = 0; w <= W; w++)`: This line is like playing with the big toy `W+1` times. We use the small toy `w` to pick the column in the big toy box.

8. `if (i==0 || w==0)`: This line is like checking if either `i` or `w` is equal to 0. If either condition is true, then the value of `K[i][w]` is set to 0.

9. `else if (wt[i-1] <= w)`: This line is like checking if the weight of candy `i-1` is less than or equal to the current value of `w`. If this condition is true, then the value of `K[i][w]` is set to the maximum of `val[i-1] + K[i-1][w-wt[i-1]]` and `K[i-1][w]`.

10. `else`: If the condition in line 9 is false, then the value of `K[i][w]` is set to `K[i-1][w]`.

11. `return K[n][W];`: This line is like giving the value stored in `K[n][W]` back to us. This value represents the maximum value of candies we can put in the big bag.

12. `int main()`: This line is like saying "I want to play with the big toy".

13. `int val[] = {60, 100, 120};`: This line is like making a new toy box with three candies inside. These candies represent the values of the candies in the knapsack problem.

14. `int wt[] = {10, 20, 30};`: This line is like making a new toy box with three candies inside. These candies represent the weights of the candies in the knapsack problem.

15. `int W = 50;`: This line is like making a new toy with a value of 50. This value represents the capacity of the big bag.

16. `int n = sizeof(val)/sizeof(val[0]);`: This line is like making a new toy with a value equal to the number of candies in the knapsack problem. This value is calculated by dividing the size of the `val` toy box by the size of a single candy in the `val` toy box.

17. `cout << knapSack(W, wt, val, n);`: This line is like playing with the big toy and printing the result to the screen.

18. `return 0;`: This line is like saying "I finished playing with the big toy and everything is good".
*/
