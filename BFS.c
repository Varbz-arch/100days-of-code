// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = 0;

// Visited array
int visited[MAX];

// BFS function
void bfs(int adj[MAX][MAX], int n, int s) {

    // Put source in queue
    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {

        // Remove vertex from queue
        int u = queue[front++];

        printf("%d ", u);

        // Check all adjacent vertices
        for (int v = 0; v < n; v++) {

            if (adj[u][v] == 1 && visited[v] == 0) {

                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
}

int main() {

    int n, m;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");

    for (int i = 0; i < m; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        // Undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int s;

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");

    bfs(adj, n, s);

    return 0;
}