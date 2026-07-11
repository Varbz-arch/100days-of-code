// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int rows[m];
    int cols[n];

    // Initialize
    for (int i = 0; i < m; i++)
        rows[i] = 0;

    for (int j = 0; j < n; j++)
        cols[j] = 0;

    // Mark rows and columns
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }

        }
    }

    // Set zeroes
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (rows[i] == 1 || cols[j] == 1)
                matrix[i][j] = 0;

        }
    }

    // Print
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}