// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <limits.h>

#define MAX 100

// Structure for an edge
typedef struct {
    int vertex;
    int weight;
} Edge;

// Structure for priority queue node
typedef struct {
    int vertex;
    int distance;
} Node;

// Priority Queue
Node pq[MAX * MAX];
int size = 0;

// Insert into min-priority queue
void push(int vertex, int distance) {
    int i = size++;

    pq[i].vertex = vertex;
    pq[i].distance = distance;

    // Move upward
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (pq[parent].distance <= pq[i].distance)
            break;

        Node temp = pq[parent];
        pq[parent] = pq[i];
        pq[i] = temp;

        i = parent;
    }
}

// Remove minimum element
Node pop() {
    Node result = pq[0];

    pq[0] = pq[--size];

    // Move downward
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size &&
            pq[left].distance < pq[smallest].distance)
            smallest = left;

        if (right < size &&
            pq[right].distance < pq[smallest].distance)
            smallest = right;

        if (smallest == i)
            break;

        Node temp = pq[i];
        pq[i] = pq[smallest];
        pq[smallest] = temp;

        i = smallest;
    }

    return result;
}

void dijkstra(int graph[MAX][MAX], int V, int src) {

    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    // Insert source
    push(src, 0);

    while (size > 0) {

        Node current = pop();

        int u = current.vertex;
        int d = current.distance;

        // Ignore outdated entry
        if (d > dist[u])
            continue;

        // Check all neighbors
        for (int v = 0; v < V; v++) {

            if (graph[u][v] != 0) {

                int weight = graph[u][v];

                // Relaxation
                if (dist[u] + weight < dist[v]) {

                    dist[v] = dist[u] + weight;

                    push(v, dist[v]);
                }
            }
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);

    for (int i = 0; i < V; i++) {

        if (dist[i] == INT_MAX)
            printf("Vertex %d : INF\n", i);
        else
            printf("Vertex %d : %d\n", i, dist[i]);
    }
}

int main() {

    int V = 5;

    int graph[MAX][MAX] = {0};

    // graph[u][v] = weight

    graph[0][1] = 4;
    graph[0][2] = 1;

    graph[2][1] = 2;
    graph[1][3] = 1;
    graph[2][3] = 5;
    graph[3][4] = 3;

    int source = 0;

    dijkstra(graph, V, source);

    return 0;
}