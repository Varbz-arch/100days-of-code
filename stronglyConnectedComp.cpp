// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], 
// where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in 
// the graph.

// Examples:

// Input: V = 6, E = 7, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3], [3, 4], [4, 3], [4, 5]]
// Output: 3
// Explanation: The strongly connected components are: {0, 1, 2},{3, 4} and {5}. Therefore, the total number of SCCs is 3.
 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// First DFS
void dfs1(int node, vector<vector<int>>& adj,
          vector<bool>& visited, vector<int>& order) {

    visited[node] = true;

    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs1(next, adj, visited, order);
        }
    }

    // Store after all neighbours are visited
    order.push_back(node);
}

// Second DFS on transpose graph
void dfs2(int node, vector<vector<int>>& transpose,
          vector<bool>& visited) {

    visited[node] = true;

    for (int next : transpose[node]) {
        if (!visited[next]) {
            dfs2(next, transpose, visited);
        }
    }
}

int main() {

    int V, E;

    // Input
    cin >> V >> E;

    vector<vector<int>> adj(V);
    vector<vector<int>> transpose(V);

    // Read edges
    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        // Original graph
        adj[u].push_back(v);

        // Reverse the edge for transpose graph
        transpose[v].push_back(u);
    }

    // --------------------------------
    // Step 1: First DFS
    // --------------------------------

    vector<bool> visited(V, false);
    vector<int> order;

    for (int i = 0; i < V; i++) {

        if (!visited[i]) {
            dfs1(i, adj, visited, order);
        }
    }

    // --------------------------------
    // Step 2: Reset visited
    // --------------------------------

    fill(visited.begin(), visited.end(), false);

    // --------------------------------
    // Step 3: DFS on transpose graph
    // --------------------------------

    reverse(order.begin(), order.end());

    int sccCount = 0;

    for (int node : order) {

        if (!visited[node]) {

            dfs2(node, transpose, visited);

            // One DFS = one SCC
            sccCount++;
        }
    }

    // Output
    cout << sccCount << endl;

    return 0;
}