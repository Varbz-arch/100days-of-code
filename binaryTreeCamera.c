// You are given the root of a binary tree. We install cameras on the tree nodes
//  where each camera at a node can monitor its parent, itself, and its immediate children.
// Return the minimum number of cameras needed to monitor all nodes of the tree.
// Example 1:

// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cameras = 0;

// Create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Returns:
// 0 -> NOT COVERED
// 1 -> HAS CAMERA
// 2 -> COVERED
int dfs(struct TreeNode* root) {

    if (root == NULL)
        return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child is not covered
    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    // If any child has a camera
    if (left == 1 || right == 1)
        return 2;

    // Otherwise, this node is not covered
    return 0;
}

int minCameraCover(struct TreeNode* root) {

    cameras = 0;

    // If root is not covered
    if (dfs(root) == 0)
        cameras++;

    return cameras;
}

// Build tree from level-order input
struct TreeNode* buildTree(int arr[], int n) {

    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode** queue =
        (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    struct TreeNode* root = newNode(arr[0]);

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {

        struct TreeNode* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);

    return root;
}

int main() {

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level-order traversal (-1 for NULL):\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    int result = minCameraCover(root);

    printf("Minimum cameras = %d\n", result);

    return 0;
}