// Problem: Count Leaf Nodes

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Count leaf nodes
int countLeaves(struct TreeNode* root) {
    // Empty tree
    if (root == NULL)
        return 0;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Count leaves in left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

// Build tree from level-order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode** queue =
        (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    int front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct TreeNode* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    printf("%d\n", countLeaves(root));

    return 0;
}