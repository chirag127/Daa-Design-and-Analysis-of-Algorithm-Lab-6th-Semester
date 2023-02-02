write the c code for practical for my daa assignement 

N Queen Problem using Backtracking: Implement a backtracking algorithm to find all possible solutions to the n-queens problem, which is to place n queens on an nxn chessboard such that no two queens attack each other.

```
#include<stdio.h>
#define N 8

int board[N][N];

int is_attack(int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
            return 1;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return 1;
    }
    for(i=row,j=col;j>=0 && i<N;i++,j--)
    {
        if(board[i][j])
            return 1;
    }
    return 0;
}

int n_queen(int col)
{
    int i;
    if(col==N)
    {
        return 1;
    }
    for(i=0;i<N;i++)
    {
        if(!is_attack(i,col))
        {
            board[i][col]=1;
            if(n_queen(col+1))
                return 1;
            board[i][col]=0;
        }
    }
    return 0;
}

int main()
{
    int i,j;
    n_queen(0);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d\t",board[i][j]);
        printf("\n");
    }
    return 0;
}
```
/*


```
#include<stdio.h>
```
This line includes the standard input/output library in the code.

```
#define N 8
```
This line defines the constant `N` with a value of `8`. This is used as the size of the chessboard in the n-queens problem.

```
int board[N][N];
```
This line declares a 2D array `board` with `N` rows and `N` columns, which represents the chessboard.

```
int is_attack(int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
            return 1;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return 1;
    }
    for(i=row,j=col;j>=0 && i<N;i++,j--)
    {
        if(board[i][j])
            return 1;
    }
    return 0;
}
```
This function `is_attack` checks if a queen placed at the given `row` and `col` on the chessboard is under attack by any other queen. It returns `1` if the queen is under attack, and `0` otherwise. The first `for` loop checks the same row to the left of the given column. The second `for` loop checks the left-diagonal above the given position. The third `for` loop checks the left-diagonal below the given position.

```
int n_queen(int col)
{
    int i;
    if(col==N)
    {
        return 1;
    }
    for(i=0;i<N;i++)
    {
        if(!is_attack(i,col))
        {
            board[i][col]=1;
            if(n_queen(col+1))
                return 1;
            board[i][col]=0;
        }
    }
    return 0;
}
```
This function `n_queen` implements the backtracking algorithm to find all possible solutions to the n-queens problem. It takes a single argument, the current column number. If all `N` columns have been filled with a queen, the function returns `1`. Otherwise, the function tries to place a queen in each row of the current column. If a queen can be placed without being under attack, the function calls itself recursively with the next column. If the function returns `1` for the next column, it means a solution has been found and the function returns `1`. If the function returns `0` for all rows in the current column, it means the current placement is not a solution and the function backtracks by resetting the board and returning `0`.

```
int main()
{
    int i,j;
    n_queen(0);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d\t",board[i][j]);
        printf("\n");
    }
    return 0;
}
```
This is the main function of the program. It calls the `n_queen` function with the first column `0`. After the function returns, the program prints the final state of the board, where `1` represents a queen and `0` represents an empty square. The program returns `0` to indicate successful execution.
*/
/*


```
#include<stdio.h>
```
This line is like asking for help from a big library to print things on the screen.

```
#define N 8
```
This line makes a rule that whenever we use `N` in the code, it should mean `8`.

```
int board[N][N];
```
This line makes a big square with `N` rows and `N` columns that we will use to play a game called n-queens.

```
int is_attack(int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
            return 1;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return 1;
    }
    for(i=row,j=col;j>=0 && i<N;i++,j--)
    {
        if(board[i][j])
            return 1;
    }
    return 0;
}
```
This function `is_attack` checks if a queen placed at the given `row` and `col` on the chessboard is under attack by any other queen. It returns `1` if the queen is under attack, and `0` otherwise. The first `for` loop checks the same row to the left of the given column. The second `for` loop checks the left-diagonal above the given position. The third `for` loop checks the left-diagonal below the given position.

```
int n_queen(int col)
{
    int i;
    if(col==N)
    {
        return 1;
    }
    for(i=0;i<N;i++)
    {
        if(!is_attack(i,col))
        {
            board[i][col]=1;
            if(n_queen(col+1))
                return 1;
            board[i][col]=0;
        }
    }
    return 0;
}
```
This function `n_queen` is like a big helper that finds all the ways to play the n-queens game. It takes a single argument, the current column number. If all `N` columns have been filled with a queen, the function returns `1`. Otherwise, the function tries to place a queen in each row of the current column. If a queen can be placed without being under attack, the function calls itself recursively with the next column. If the function returns `1` for the next column, it means a solution has been found and the function returns `1`. If the function returns `0` for all rows in the current column, it means the current placement is not a solution and the function backtracks by resetting the board and returning `0`.

```
int main()
{
    int i,j;
    n_queen(0);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d\t",board[i][j]);
        printf("\n");
    }
    return 0;
}
```
This is the main function of the program. It calls the `n_queen` function with the first column `0`. After the function returns, the program prints the final state of the board, where `1` represents a queen and `0` represents an empty square. The program returns `0` to indicate successful execution.
*/
