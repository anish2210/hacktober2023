#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
int n;
void printSolution(int board[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[n][n], int row, int col) {
    int i, j;

    // check row
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}
bool solveNQueen(int board[n][n], int col) {
    if (col >= n) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueen(board, col + 1)) {
                return true;
            }
            board[i][col] = 0; // backtrack
        }
    }

    return false;
}
void main()
{
    printf("Enter the value of N for a N X N chessboard: ");
    scanf("%d",&n);
    if(n==2)
    {
        printf("not possible.");
        exit(1);
    }
    int board[n][n];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    if (solveNQueen(board, 0) == false) {
        printf("Solution does not exist");
    }
    else {
        printf("Solution:\n");
        printSolution(board);
        printf("The number 1 decipts the placement of the Queens.");
    }
}