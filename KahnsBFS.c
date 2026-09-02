// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int topo[MAX];
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) where u -> v:\n");

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        indegree[v]++;
    }

    // Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Kahn's Algorithm
    while (front < rear) {
        int u = queue[front++];

        topo[count++] = u;

        // Remove u and decrease indegree of its neighbors
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // If not all vertices are processed, graph has a cycle
    if (count != n) {
        printf("Topological sorting is not possible.\n");
        printf("Graph contains a cycle.\n");
    } else {
        printf("Topological Order: ");

        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }

        printf("\n");
    }

    return 0;
}