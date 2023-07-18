#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void solveNQueens(int n);
void placeQueens(int n, int row, int columns[]);
bool isValid(int row, int col, int columns[]);
void printSolution(int n, int columns[]);

int main() {
    int n;

    printf("Enter the number of queens (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for the number of queens. Exiting.\n");
        return 1;
    }

    solveNQueens(n);

    return 0;
}

// Solve N-Queens problem
void solveNQueens(int n) {
    int columns[n];
    placeQueens(n, 0, columns);
}

// Place queens on the chessboard recursively
void placeQueens(int n, int row, int columns[]) {
    if (row == n) {
        printSolution(n, columns);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isValid(row, col, columns)) {
            columns[row] = col;
            placeQueens(n, row + 1, columns);
        }
    }
}

// Check if a queen can be placed at the given position
bool isValid(int row, int col, int columns[]) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = columns[prevRow];

        if (prevCol == col || prevCol - col == prevRow - row || prevCol - col == row - prevRow) {
            return false;
        }
    }

    return true;
}

// Print the chessboard with queens placed
void printSolution(int n, int columns[]) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (columns[row] == col) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
