// Problem: BST Search

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
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

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Value not found
    if (root == NULL) {
        return NULL;
    }

    // Value found
    if (root->val == val) {
        return root;
    }

    // Search left
    if (val < root->val) {
        return searchBST(root->left, val);
    }

    // Search right
    return searchBST(root->right, val);
}

int main() {
    struct TreeNode* root = NULL;

    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter BST values: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter value to search: ");
    scanf("%d", &val);

    struct TreeNode* result = searchBST(root, val);

    if (result != NULL) {
        printf("Value %d found in BST\n", val);
    } else {
        printf("Value %d not found in BST\n", val);
    }

    return 0;
}