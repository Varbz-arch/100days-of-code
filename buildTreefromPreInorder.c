// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3

// Output:
// 4 5 2 3 1

// Explanation:
// Preorder identifies root, inorder splits left and right subtrees.

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
    int preorder[],
    int inorder[],
    int inStart,
    int inEnd,
    int *preIndex
) {
    // No elements
    if (inStart > inEnd)
        return NULL;

    // First preorder element is root
    int rootValue = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = newNode(rootValue);

    // Find root in inorder
    int rootIndex = findIndex(
        inorder,
        inStart,
        inEnd,
        rootValue
    );

    // Build left subtree
    root->left = buildTree(
        preorder,
        inorder,
        inStart,
        rootIndex - 1,
        preIndex
    );

    // Build right subtree
    root->right = buildTree(
        preorder,
        inorder,
        rootIndex + 1,
        inEnd,
        preIndex
    );

    return root;
}

void postorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;

    scanf("%d", &n);

    int preorder[n];
    int inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct TreeNode* root = buildTree(
        preorder,
        inorder,
        0,
        n - 1,
        &preIndex
    );

    postorder(root);

    return 0;
}


// struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    
//     if (preorderSize == 0 || inorderSize == 0)
//         return NULL;

//     // First element of preorder is the root
//     int rootValue = preorder[0];

//     struct TreeNode* root = malloc(sizeof(struct TreeNode));
//     root->val = rootValue;
//     root->left = NULL;
//     root->right = NULL;

//     // Find root in inorder
//     int rootIndex = 0;

//     while (inorder[rootIndex] != rootValue) {
//         rootIndex++;
//     }

//     // Number of nodes in left subtree
//     int leftSize = rootIndex;

//     // Build left subtree
//     root->left = buildTree(
//         preorder + 1,
//         leftSize,
//         inorder,
//         leftSize
//     );

//     // Build right subtree
//     root->right = buildTree(
//         preorder + 1 + leftSize,
//         preorderSize - leftSize - 1,
//         inorder + rootIndex + 1,
//         inorderSize - rootIndex - 1
//     );

//     return root;
// }