// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

// Example 1:


// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation: 

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of points: ");
    scanf("%d", &n);

    int points[n][2];

    printf("Enter coordinates:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int minCost[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        minCost[i] = INT_MAX;
        visited[i] = 0;
    }

    minCost[0] = 0;

    int totalCost = 0;

    for (int count = 0; count < n; count++) {

        int u = -1;

        // Find minimum-cost unvisited point
        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || minCost[i] < minCost[u])) {
                u = i;
            }
        }

        visited[u] = 1;
        totalCost += minCost[u];

        // Update neighboring points
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {

                int distance =
                    abs(points[u][0] - points[v][0]) +
                    abs(points[u][1] - points[v][1]);

                if (distance < minCost[v]) {
                    minCost[v] = distance;
                }
            }
        }
    }

    printf("Minimum Cost = %d\n", totalCost);

    return 0;
}