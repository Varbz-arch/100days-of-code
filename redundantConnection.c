// In this problem, a tree is an undirected graph that is connected and has no cycles.
// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

// Example 1:
// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

#include <stdio.h>
#include <stdlib.h>

int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);

    return parent[x];
}

void unionSet(int parent[], int rank[], int a, int b) {
    int rootA = find(parent, a);
    int rootB = find(parent, b);

    if (rootA == rootB)
        return;

    if (rank[rootA] < rank[rootB]) {
        parent[rootA] = rootB;
    }
    else if (rank[rootA] > rank[rootB]) {
        parent[rootB] = rootA;
    }
    else {
        parent[rootB] = rootA;
        rank[rootA]++;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int edges[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int parent[n + 1];
    int rank[n + 1];

    // Initially every node is its own parent
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int answer[2];

    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If already connected, this edge creates a cycle
        if (find(parent, u) == find(parent, v)) {
            answer[0] = u;
            answer[1] = v;
        }
        else {
            unionSet(parent, rank, u, v);
        }
    }

    printf("[%d, %d]\n", answer[0], answer[1]);

    return 0;
}