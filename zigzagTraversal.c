// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.

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
}

void zigzagTraversal(struct TreeNode* root) {

    if (root == NULL)
        return;

    struct TreeNode* queue[1000];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {

        int levelSize = rear - front;

        // Store current level's nodes
        int level[1000];

        for (int i = 0; i < levelSize; i++) {

            struct TreeNode* current = queue[front++];

            level[i] = current->val;

            // Add children to queue
            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        // Print according to direction
        if (leftToRight) {
            for (int i = 0; i < levelSize; i++)
                printf("%d ", level[i]);
        }
        else {
            for (int i = levelSize - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        // Change direction
        leftToRight = !leftToRight;
    }
}

int main() {

    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Create nodes
    struct TreeNode* nodes[N];

    for (int i = 0; i < N; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Connect children
    for (int i = 0; i < N; i++) {

        if (nodes[i] == NULL)
            continue;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N)
            nodes[i]->left = nodes[left];

        if (right < N)
            nodes[i]->right = nodes[right];
    }

    struct TreeNode* root = nodes[0];

    zigzagTraversal(root);

    return 0;
}