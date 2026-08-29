// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

#include <stdio.h>
#include <stdlib.h>

int orangesRotting(int grid[100][100], int m, int n)
{
    int queue[10000][2];
    int front = 0, rear = 0;
    int fresh = 0;
    int minutes = 0;

    // Put all rotten oranges into queue
    // Count fresh oranges
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    // Four directions
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // BFS
    while (front < rear && fresh > 0)
    {
        int size = rear - front;

        // Process all rotten oranges of current minute
        for (int i = 0; i < size; i++)
        {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Check boundaries
                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1)
                {
                    // Fresh -> Rotten
                    grid[nr][nc] = 2;
                    fresh--;

                    // Add to queue
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                }
            }
        }

        minutes++;
    }

    // Fresh oranges still remaining
    if (fresh > 0)
        return -1;

    return minutes;
}

int main()
{
    int m, n;
    int grid[100][100];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the grid:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, m, n);

    printf("Minimum minutes: %d\n", result);

    return 0;
}