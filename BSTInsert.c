// Problem: BST Insert

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

// Insert a value into the BST
struct TreeNode* insert(struct TreeNode* root, int val) {

    // If tree is empty, create a new node
    if (root == NULL) {
        return createNode(val);
    }

    // Insert into left subtree
    if (val < root->val) {
        root->left = insert(root->left, val);
    }

    // Insert into right subtree
    else if (val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int n, value;
    struct TreeNode* root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}