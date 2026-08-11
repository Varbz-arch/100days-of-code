// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

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

// Level Order Traversal
void levelOrder(struct TreeNode* root) {

    if (root == NULL) {
        return;
    }

    // Queue
    struct TreeNode* queue[1000];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {

        // Number of nodes in current level
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {

            struct TreeNode* current = queue[front++];

            printf("%d ", current->val);

            // Add left child
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }

            // Add right child
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }

        printf("\n");
    }
}

int main() {

    /*
             3
            / \
           9   20
              /  \
             15   7
    */

    struct TreeNode* root = createNode(3);

    root->left = createNode(9);
    root->right = createNode(20);

    root->right->left = createNode(15);
    root->right->right = createNode(7);

    levelOrder(root);

    return 0;
}