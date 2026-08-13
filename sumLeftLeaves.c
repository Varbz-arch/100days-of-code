// Given the root of a binary tree, return the sum of all left leaves.
// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

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

// Calculate sum of all left leaves
int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check if left child exists and is a leaf
    if (root->left != NULL &&
        root->left->left == NULL &&
        root->left->right == NULL) {

        sum += root->left->val;
    }

    // Check remaining subtrees
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    /*
             3
            / \
           9   20
              /  \
             15   7

        Left leaves = 9, 15
        Sum = 24
    */

    struct TreeNode* root = createNode(3);

    root->left = createNode(9);
    root->right = createNode(20);

    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("%d\n", sumOfLeftLeaves(root));

    return 0;
}