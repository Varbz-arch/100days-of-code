// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>

void dfs(int node, int V, int adj[V][V], int visited[], int stack[], int *top) {
    visited[node] = 1;

    for (int neighbour = 0; neighbour < V; neighbour++) {
        if (adj[node][neighbour] == 1 && !visited[neighbour]) {
            dfs(neighbour, V, adj, visited, stack, top);
        }
    }

    // Push after visiting all neighbours
    stack[++(*top)] = node;
}

void topologicalSort(int V, int adj[V][V]) {
    int visited[V];
    int stack[V];
    int top = -1;

    // Initialize visited array
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // DFS from every unvisited vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V, adj, visited, stack, &top);
        }
    }

    // Print in reverse finishing order
    printf("Topological Order: ");

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    printf("\n");
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[V][V];

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter directed edges (u v):\n");

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
    }

    topologicalSort(V, adj);

    return 0;
}