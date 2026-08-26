// There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, 
// and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

// A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, 
// and `isConnected[i][j] = 0` otherwise.

// Return *the total number of ****provinces***.

// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

#include <stdio.h>
#include <stdlib.h>

void dfs(int city, int n, int** isConnected, int* visited) {
    visited[city] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[city][j] == 1 && visited[j] == 0) {
            dfs(j, n, isConnected, visited);
        }
    }
}

int findCircleNum(int** isConnected, int n) {
    int* visited = calloc(n, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            provinces++;
            dfs(i, n, isConnected, visited);
        }
    }

    free(visited);
    return provinces;
}

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Create matrix
    int** isConnected = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        isConnected[i] = malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int answer = findCircleNum(isConnected, n);

    printf("Number of provinces = %d\n", answer);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(isConnected[i]);
    }

    free(isConnected);

    return 0;
}