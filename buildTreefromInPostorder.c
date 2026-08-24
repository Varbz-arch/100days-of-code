// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

// Example:
// Input:
// 5
// 4 2 5 1 3
// 4 5 2 3 1

// Output:
// 1 2 4 5 3

// Explanation:
// Postorder gives root at end, inorder divides left and right subtrees.


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }

    return -1;
}

struct TreeNode* buildTree(
    int inorder[],
    int postorder[],
    int inStart,
    int inEnd,
    int* postIndex
) {
    // No elements
    if (inStart > inEnd)
        return NULL;

    // Last element of postorder = root
    int rootValue = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootValue);

    // Find root in inorder
    int rootIndex = findIndex(
        inorder,
        inStart,
        inEnd,
        rootValue
    );

    // IMPORTANT:
    // Build right subtree first
    root->right = buildTree(
        inorder,
        postorder,
        rootIndex + 1,
        inEnd,
        postIndex
    );

    // Then build left subtree
    root->left = buildTree(
        inorder,
        postorder,
        inStart,
        rootIndex - 1,
        postIndex
    );

    return root;
}

void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);

    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    scanf("%d", &n);

    int inorder[n];
    int postorderArray[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorderArray[i]);

    int postIndex = n - 1;

    struct TreeNode* root = buildTree(
        inorder,
        postorderArray,
        0,
        n - 1,
        &postIndex
    );

    preorder(root);

    return 0;
}