#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];  // board[i] = column position of queen in row i
int n;           // size of board (n x n)

// Function to print one solution
void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if placing a queen at row r and column c is safe
int isSafe(int r, int c) {
    for (int i = 0; i < r; i++) {
        if (board[i] == c || abs(board[i] - c) == abs(i - r))
            return 0;  // same column or diagonal
    }
    return 1;
}

// Backtracking function to solve N-Queens
void solveNQueens(int row) {
    if (row == n) {
        printSolution();
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1);  // Recurse to next row
        }
    }
}

// Main function
int main() {
    printf("Enter the value of N (size of board): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid board size. Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Solutions for %d-Queens problem:\n\n", n);
    solveNQueens(0);

    return 0;
}
