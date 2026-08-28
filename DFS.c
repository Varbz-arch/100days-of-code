// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order

#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int m, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;   // Remove this line for directed graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}