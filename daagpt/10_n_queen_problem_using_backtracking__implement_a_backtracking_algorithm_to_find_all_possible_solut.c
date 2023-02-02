write the codes in c following practical for my daa assignement 

N Queen Problem using Backtracking: Implement a backtracking algorithm to find all possible solutions to the n-queens problem, which is to place n queens on an nxn chessboard such that no two queens attack each other.
 Here is a sample code in C to solve the N Queen problem using backtracking:

```
#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N];

bool is_attack(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return true;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return true;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return true;
    return false;
}

bool solve_n_queen(int col) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (!is_attack(i, col)) {
            board[i][col] = 1;
            if (solve_n_queen(col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void print_solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    if (solve_n_queen(0) == false) {
        printf("Solution does not exist");
        return 0;
    }
    print_solution();
    return 0;
}
```
/*
explain the following code 

 Here is a sample code in C to solve the N Queen problem using backtracking:

```
#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N];

bool is_attack(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return true;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return true;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return true;
    return false;
}

bool solve_n_queen(int col) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (!is_attack(i, col)) {
            board[i][col] = 1;
            if (solve_n_queen(col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void print_solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    if (solve_n_queen(0) == false) {
        printf("Solution does not exist");
        return 0;
    }
    print_solution();
    return 0;
}
```
 The code is a solution to the N-Queens problem using backtracking in C. It uses a 2D array `board[N][N]` to represent the chessboard where `N` is defined as 8. The `is_attack` function checks if a queen placed at row `row` and column `col` is under attack from any of the existing queens on the board. The `solve_n_queen` function uses backtracking to place all `N` queens on the board such that no two queens attack each other. The function returns `true` if a solution is found, otherwise `false`. The `print_solution` function prints the board with all queens placed. The `main` function initializes the board to all zeros, calls `solve_n_queen` and if a solution is found, it prints the solution. If a solution is not found, it prints "Solution does not exist".
*/
