// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

struct TreeNode* lowestCommonAncestor(
    struct TreeNode* root, int p, int q) {

    // If tree is empty
    if (root == NULL)
        return NULL;

    // If current node is one of p or q
    if (root->val == p || root->val == q)
        return root;

    // Search in left subtree
    struct TreeNode* left =
        lowestCommonAncestor(root->left, p, q);

    // Search in right subtree
    struct TreeNode* right =
        lowestCommonAncestor(root->right, p, q);

    // One node found on each side
    if (left != NULL && right != NULL)
        return root;

    // Return whichever side found a node
    if (left != NULL)
        return left;

    return right;
}
int main() {

    // Creating the tree
    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int p, q;

    scanf("%d %d", &p, &q);

    struct TreeNode* result =
        lowestCommonAncestor(root, p, q);

    printf("%d\n", result->val);

    return 0;
}