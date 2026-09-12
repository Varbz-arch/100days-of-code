// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    int graph[MAX][MAX];

    // Initialize graph
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }

    // Input
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        // Convert 1-based vertices to 0-based
        u--;
        v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX];
    int visited[MAX];

    // Initially, all vertices are unvisited
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start Prim's algorithm from vertex 0
    key[0] = 0;

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {

        // Find unvisited vertex with minimum edge weight
        int u = -1;
        int min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        // Mark vertex as visited
        visited[u] = 1;

        // Add its edge weight to MST
        totalWeight += key[u];

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}