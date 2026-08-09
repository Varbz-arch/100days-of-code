// Given the root of a binary tree, return the preorder traversal of its nodes' values.
// Example 1:

// Input: root = [1,null,2,3]

// Output: [1,2,3]

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Preorder: Root -> Left -> Right
void preorder(struct TreeNode* root) {

    if (root == NULL)
        return;

    printf("%d ", root->val);       // Root

    preorder(root->left);           // Left

    preorder(root->right);          // Right
}

int main() {

    /*
          1
           \
            2
           /
          3
    */

    struct TreeNode* root = createNode(1);
    root->left = NULL;
    root->right = createNode(2);
    root->right->left = createNode(3);

    printf("Preorder Traversal: ");

    preorder(root);

    return 0;
}