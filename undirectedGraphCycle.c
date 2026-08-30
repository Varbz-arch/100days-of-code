// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

// Note: The graph can have multiple component.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation: 
 
// 1 -> 2 -> 0 -> 1 is a cycle.

#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int parent, int **adj, int *adjSize, int *visited)
{
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++)
    {
        int neighbor = adj[node][i];

        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, adj, adjSize, visited))
                return 1;
        }
        else if (neighbor != parent)
        {
            // Visited neighbor which is not the parent
            return 1;
        }
    }

    return 0;
}

int main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int **adj = (int **)malloc(V * sizeof(int *));
    int *adjSize = (int *)calloc(V, sizeof(int));
    int *capacity = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
    {
        adj[i] = NULL;
        capacity[i] = 0;
    }

    printf("Enter edges (u v):\n");

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add v to u's list
        if (adjSize[u] == capacity[u])
        {
            capacity[u] = capacity[u] == 0 ? 2 : capacity[u] * 2;
            adj[u] = realloc(adj[u], capacity[u] * sizeof(int));
        }
        adj[u][adjSize[u]++] = v;

        // Add u to v's list (undirected graph)
        if (adjSize[v] == capacity[v])
        {
            capacity[v] = capacity[v] == 0 ? 2 : capacity[v] * 2;
            adj[v] = realloc(adj[v], capacity[v] * sizeof(int));
        }
        adj[v][adjSize[v]++] = u;
    }

    int *visited = (int *)calloc(V, sizeof(int));

    int cycle = 0;

    // Check every component
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, adjSize, visited))
            {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    // Free memory
    for (int i = 0; i < V; i++)
        free(adj[i]);

    free(adj);
    free(adjSize);
    free(capacity);
    free(visited);

    return 0;
}