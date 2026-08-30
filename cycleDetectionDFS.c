// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <stdio.h>
#include <stdlib.h>

int **adj;
int *visited;
int n, m;

int dfs(int node, int parent)
{
    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1)
        {
            // If neighbour is not visited, visit it
            if (!visited[i])
            {
                if (dfs(i, node))
                    return 1;
            }
            // If neighbour is visited and is not the parent,
            // then a cycle exists
            else if (i != parent)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Create adjacency matrix
    adj = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        adj[i] = (int *)calloc(n, sizeof(int));

    visited = (int *)calloc(n, sizeof(int));

    printf("Enter %d edges (u v):\n", m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected graph
    }

    int cycle = 0;

    // Needed because the graph may be disconnected
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
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
    for (int i = 0; i < n; i++)
        free(adj[i]);

    free(adj);
    free(visited);

    return 0;
}