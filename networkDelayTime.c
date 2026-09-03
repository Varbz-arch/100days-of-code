// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
// Example 1:
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

#include <stdio.h>

#define INF 999999

int networkDelayTime(int times[][3], int timesSize, int n, int k) {

    int graph[n + 1][n + 1];

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    // Add edges
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        graph[u][v] = w;
    }

    // Distance array
    int dist[n + 1];
    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[k] = 0;

    // Dijkstra
    for (int count = 1; count <= n; count++) {

        int u = -1;
        int minDist = INF;

        // Find minimum distance unvisited node
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Relax neighbours
        for (int v = 1; v <= n; v++) {

            if (graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Find maximum distance
    int answer = 0;

    for (int i = 1; i <= n; i++) {

        if (dist[i] == INF)
            return -1;

        if (dist[i] > answer)
            answer = dist[i];
    }

    return answer;
}

int main() {

    int times[][3] = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int timesSize = 3;
    int n = 4;
    int k = 2;

    int result = networkDelayTime(times, timesSize, n, k);

    printf("Minimum time: %d\n", result);

    return 0;
}