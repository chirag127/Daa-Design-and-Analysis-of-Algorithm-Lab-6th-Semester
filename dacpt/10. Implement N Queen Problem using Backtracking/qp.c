#include <stdio.h>
#include <stdbool.h>

#define N 8

int row[N];

bool check(int r, int c)
{
    for (int i = 0; i < c; i++)
        if (row[i] == r || (abs(row[i] - r) == abs(i - c)))
            return false;
    return true;
}

void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (row[j] == i)
                printf("Q ");
            else
                printf("_ ");
        }
        printf("\n");
    }
    printf("\n");
}

bool solveNQueen(int c)
{
    if (c == N)
    {
        printSolution();
        return true;
    }

    for (int r = 0; r < N; r++)
    {
        if (check(r, c))
        {
            row[c] = r;
            if (solveNQueen(c + 1))
                return true;
            row[c] = 0;
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < N; i++)
        row[i] = 0;

    if (!solveNQueen(0))
        printf("Solution does not exist");
    return 0;
}
/* Here is the explanation for the code above:
1. The n-queens problem is to place n queens on an n x n chessboard so that no two queens can attack each other.
2. In this problem, we have to place eight queens on an eight by eight chessboard.
3. The row array is used to store the position of the queens in each column.
4. The check() function checks the position of the queens in each column.
5. If the position of the queens in the current column is correct, the next column is checked.
6. The solveNQueen() function is used to solve the problem.
7. It checks if the current column is equal to the number of queens to be placed.
8. If it is equal, the solution is printed.
9. If it is not equal, the current column is checked for all the rows.
10. If the current row is correct, it is placed in the current column.
11. The next column is checked for all the rows.
12. If there is no solution, false is returned.
13. If there is a solution, true is returned.
14. In the main() function, the row array is initialized to zero.
15. The solveNQueen() function is called.
16. If there is no solution, “Solution does not exist” is printed.
17. If there is a solution, the solution is printed. */


