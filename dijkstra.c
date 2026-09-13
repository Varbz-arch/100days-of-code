// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

#include <stdio.h>
#include <limits.h>

#define MAX 100

// Find the vertex with the minimum distance
int findMinVertex(int dist[], int visited[], int n) {
    int min = INT_MAX;
    int minVertex = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minVertex = i;
        }
    }

    return minVertex;
}

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX];
    int visited[MAX];

    // Initially, all distances are infinity
    // and no vertex is visited
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance from source to itself is 0
    dist[source] = 0;

    for (int count = 1; count <= n; count++) {

        // Pick the unvisited vertex with smallest distance
        int u = findMinVertex(dist, visited, n);

        if (u == -1)
            break;

        visited[u] = 1;

        // Relax all neighbouring vertices
        for (int v = 1; v <= n; v++) {

            if (graph[u][v] != 0 && !visited[v]) {

                if (dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Print shortest distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");
}

int main() {
    int n, m;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        // Undirected graph
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("Shortest distances: ");
    dijkstra(graph, n, source);

    return 0;
}