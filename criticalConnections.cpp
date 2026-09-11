// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

 

// Example 1:


// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.
// Example 2:

// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]]


#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> bridges;

vector<int> disc, low;
int timer = 0;

void dfs(int u, int parent) {
    disc[u] = low[u] = timer++;

    for (int v : graph[u]) {

        // Ignore the edge going back to parent
        if (v == parent)
            continue;

        // If v is not visited
        if (disc[v] == -1) {

            dfs(v, u);

            // Update low value
            low[u] = min(low[u], low[v]);

            // Bridge condition
            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        }
        else {
            // Back edge
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    graph.resize(n);
    disc.assign(n, -1);
    low.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Run DFS from every unvisited node
    // (works even if the graph is disconnected)
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1);
        }
    }

    // Print critical connections
    for (auto edge : bridges) {
        cout << "[" << edge[0] << ", " << edge[1] << "]" << endl;
    }

    return 0;
}