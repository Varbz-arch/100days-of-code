// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

// Return true if and only if it is bipartite.

 

// Example 1:


// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

#include <stdio.h>

#define MAX 100

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    int degree[MAX];

    // Input graph
    for (int i = 0; i < n; i++) {
        printf("Enter number of neighbors of vertex %d: ", i);
        scanf("%d", &degree[i]);

        printf("Enter neighbors: ");
        for (int j = 0; j < degree[i]; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // -1 = uncolored
    //  0 = color 0
    //  1 = color 1
    int color[MAX];

    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    int queue[MAX];

    // Check every connected component
    for (int start = 0; start < n; start++) {

        // Already visited
        if (color[start] != -1)
            continue;

        int front = 0;
        int rear = 0;

        // Give starting vertex color 0
        color[start] = 0;
        queue[rear++] = start;

        // BFS
        while (front < rear) {

            int u = queue[front++];

            // Visit all neighbors of u
            for (int j = 0; j < degree[u]; j++) {

                int v = graph[u][j];

                // v is not colored
                if (color[v] == -1) {

                    // Give opposite color
                    color[v] = 1 - color[u];

                    queue[rear++] = v;
                }

                // Same color => not bipartite
                else if (color[v] == color[u]) {

                    printf("false\n");
                    return 0;
                }
            }
        }
    }

    printf("true\n");

    return 0;
}