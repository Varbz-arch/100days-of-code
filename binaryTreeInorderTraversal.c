// Given the root of a binary tree, return the inorder traversal of its nodes' values.
// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,3,2]

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = malloc(sizeof(struct TreeNode));

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inorder: LEFT -> ROOT -> RIGHT
void inorder(struct TreeNode* root) {

    if (root == NULL)
        return;

    // 1. Visit left subtree
    inorder(root->left);

    // 2. Visit root
    printf("%d ", root->val);

    // 3. Visit right subtree
    inorder(root->right);
}

int main() {

    // Creating the tree:
    //
    //       1
    //        \
    //         2
    //        /
    //       3

    struct TreeNode* root = createNode(1);

    root->right = createNode(2);
    root->right->left = createNode(3);

    printf("Inorder traversal: ");

    inorder(root);

    return 0;
}