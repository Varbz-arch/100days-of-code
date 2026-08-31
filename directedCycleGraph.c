// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

// DFS function
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1) {

            // If neighbour is in current recursion stack
            if (recStack[i] == 1)
                return 1;

            // If not visited, perform DFS
            if (!visited[i]) {
                if (dfs(i))
                    return 1;
            }
        }
    }

    // Remove node from current recursion path
    recStack[node] = 0;

    return 0;
}

int main() {
    int E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter directed edges (u v):\n");

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
    }

    // Check every vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}