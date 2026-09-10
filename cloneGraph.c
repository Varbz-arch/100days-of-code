// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
 

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

// Example 1:


// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// Example 2:


// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
// Example 3:

// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 101

// Node structure
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Array to store cloned nodes
// clone[i] = clone of original node i
struct Node* clone[MAX_NODES];


// Create a new node
struct Node* createNode(int val, int numNeighbors) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->val = val;
    newNode->numNeighbors = numNeighbors;

    if (numNeighbors > 0) {
        newNode->neighbors =
            (struct Node**)malloc(
                numNeighbors * sizeof(struct Node*)
            );
    } else {
        newNode->neighbors = NULL;
    }

    return newNode;
}


// DFS function to clone graph
struct Node* dfs(struct Node* node) {

    // If node is already cloned
    if (clone[node->val] != NULL) {
        return clone[node->val];
    }

    // Create clone
    struct Node* newNode =
        createNode(node->val, node->numNeighbors);

    // Store clone BEFORE visiting neighbors
    clone[node->val] = newNode;

    // Clone all neighbors
    for (int i = 0; i < node->numNeighbors; i++) {

        newNode->neighbors[i] =
            dfs(node->neighbors[i]);
    }

    return newNode;
}


// Print graph using DFS
void printGraph(struct Node* node, int visited[]) {

    if (node == NULL || visited[node->val]) {
        return;
    }

    visited[node->val] = 1;

    printf("Node %d -> ", node->val);

    for (int i = 0; i < node->numNeighbors; i++) {
        printf("%d ", node->neighbors[i]->val);
    }

    printf("\n");

    for (int i = 0; i < node->numNeighbors; i++) {
        printGraph(node->neighbors[i], visited);
    }
}


int main() {

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Original graph
    struct Node* nodes[MAX_NODES];

    // Create nodes
    for (int i = 1; i <= n; i++) {
        nodes[i] = createNode(i, 0);
    }

    // Build graph
    for (int i = 1; i <= n; i++) {

        int count;

        printf("Enter number of neighbors of node %d: ", i);
        scanf("%d", &count);

        nodes[i]->numNeighbors = count;

        if (count > 0) {
            nodes[i]->neighbors =
                (struct Node**)malloc(
                    count * sizeof(struct Node*)
                );
        }

        printf("Enter neighbors: ");

        for (int j = 0; j < count; j++) {

            int neighbor;
            scanf("%d", &neighbor);

            nodes[i]->neighbors[j] = nodes[neighbor];
        }
    }

    // Initialize clone array
    for (int i = 0; i < MAX_NODES; i++) {
        clone[i] = NULL;
    }

    // Clone graph
    struct Node* clonedGraph = dfs(nodes[1]);

    // Print original graph
    printf("\nOriginal Graph:\n");

    int visitedOriginal[MAX_NODES] = {0};

    printGraph(nodes[1], visitedOriginal);

    // Print cloned graph
    printf("\nCloned Graph:\n");

    int visitedClone[MAX_NODES] = {0};

    printGraph(clonedGraph, visitedClone);

    return 0;
}