// Problem Statement
// Using DFS or BFS, count number of connected components.

// Input Format
// n m
// edges

// Output Format
// Number of connected components.

// Sample Input
// 6 3
// 1 2
// 2 3
// 5 6

// Sample Output
// 3

// Explanation
// Components: {1,2,3}, {4}, {5,6}

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n, m;

// DFS function
void dfs(int node)
{
    visited[node] = 1;

    // Visit all neighbours
    for (int i = 1; i <= n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    // Input: number of nodes and edges
    scanf("%d %d", &n, &m);

    // Read edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        // Undirected graph
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int components = 0;

    // Check every node
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            // New connected component found
            components++;

            // Visit entire component
            dfs(i);
        }
    }

    printf("%d\n", components);

    return 0;
}