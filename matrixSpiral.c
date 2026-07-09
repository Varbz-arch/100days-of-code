// Given an m x n matrix, return all elements of the matrix in spiral order.
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    *returnSize = rows * cols;

    int *ans = (int*)malloc(rows * cols * sizeof(int));

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int index = 0;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++)
            ans[index++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            ans[index++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                ans[index++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans[index++] = matrix[i][left];
            left++;
        }
    }

    return ans;
}

int main() {
    int r = 3, c = 3;

    int data[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int *matrix[3];
    for (int i = 0; i < r; i++)
        matrix[i] = data[i];

    int colSize[3] = {3,3,3};
    int returnSize;

    int *ans = spiralOrder(matrix, r, colSize, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);

    free(ans);

    return 0;
}