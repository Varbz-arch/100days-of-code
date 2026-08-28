// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

// Output: [[2,2,2],[2,2,0],[2,0,1]]

#include <stdio.h>
#include <stdlib.h>

void dfs(int** image, int m, int n, int r, int c, int original, int color)
{
    // Out of bounds
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    // Not the original color
    if (image[r][c] != original)
        return;

    // Change color
    image[r][c] = color;

    // Visit 4 directions
    dfs(image, m, n, r - 1, c, original, color); // Up
    dfs(image, m, n, r + 1, c, original, color); // Down
    dfs(image, m, n, r, c - 1, original, color); // Left
    dfs(image, m, n, r, c + 1, original, color); // Right
}

int main()
{
    int m, n;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int** image = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++)
        image[i] = malloc(n * sizeof(int));

    printf("Enter image:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &image[i][j]);
    }

    int sr, sc, color;

    printf("Enter starting row and column: ");
    scanf("%d %d", &sr, &sc);

    printf("Enter new color: ");
    scanf("%d", &color);

    int original = image[sr][sc];

    // Important case
    if (original != color)
        dfs(image, m, n, sr, sc, original, color);

    printf("Flood filled image:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", image[i][j]);

        printf("\n");
    }

    for (int i = 0; i < m; i++)
        free(image[i]);

    free(image);

    return 0;
}
