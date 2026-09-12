// Given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], 
// where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v. Return all the articulation points 
// (or cut vertices) in the graph. An articulation point is a vertex whose removal, along with all its connected edges, 
// increases the number of connected components in the graph. 

// The given graph may be disconnected, i.e., it may consist of more than one connected component. 
// If no such point exists, return {-1}.
// Examples :

// Input: V = 5, edges[][] = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]

// Output: [1, 4]
// Explanation: Removing the vertex 1 or 4 will disconnects the graph as-
   
// Input: V = 4, edges[][] = [[0, 1], [0, 2]]
// Output: [0]
// Explanation: Removing the vertex 0 will increase the number of disconnected components to 3.  


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS function to find articulation points
void dfs(int u, int parent,
         vector<vector<int>>& adj,
         vector<int>& disc,
         vector<int>& low,
         vector<int>& visited,
         vector<int>& isAP,
         int& timer) {

    // Mark current vertex as visited
    visited[u] = 1;

    // Discovery time and lowest reachable time
    disc[u] = low[u] = timer++;

    // Number of DFS children
    int children = 0;

    // Visit all adjacent vertices
    for (int v : adj[u]) {

        // Do not go back to parent
        if (v == parent)
            continue;

        // If v is not visited
        if (!visited[v]) {

            children++;

            // DFS on child
            dfs(v, u, adj, disc, low, visited, isAP, timer);

            // Update low value
            low[u] = min(low[u], low[v]);

            // Case 1:
            // u is not root and removing u disconnects v's subtree
            if (parent != -1 && low[v] >= disc[u]) {
                isAP[u] = 1;
            }
        }

        // v is already visited -> back edge
        else {
            low[u] = min(low[u], disc[v]);
        }
    }

    // Case 2:
    // u is root and has more than one DFS child
    if (parent == -1 && children > 1) {
        isAP[u] = 1;
    }
}


int main() {

    int V, E;

    // Input number of vertices and edges
    cin >> V >> E;

    // Adjacency list
    vector<vector<int>> adj(V);

    // Input edges
    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Discovery time
    vector<int> disc(V, -1);

    // Lowest reachable discovery time
    vector<int> low(V, -1);

    // Visited array
    vector<int> visited(V, 0);

    // isAP[i] = 1 if i is an articulation point
    vector<int> isAP(V, 0);

    int timer = 0;

    // Important:
    // Graph can be disconnected,
    // so start DFS from every unvisited vertex.
    for (int i = 0; i < V; i++) {

        if (!visited[i]) {
            dfs(i, -1, adj, disc, low, visited, isAP, timer);
        }
    }

    // Print articulation points
    bool found = false;

    for (int i = 0; i < V; i++) {

        if (isAP[i]) {
            cout << i << " ";
            found = true;
        }
    }

    // If no articulation point exists
    if (!found) {
        cout << -1;
    }

    cout << endl;

    return 0;
}