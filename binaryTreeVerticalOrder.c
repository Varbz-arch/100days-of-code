// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode {
    struct TreeNode *node;
    int hd;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Build tree from level-order input */
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);

    struct TreeNode** queue =
        (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct TreeNode* current = queue[front++];

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);

    return root;
}

void verticalOrder(struct TreeNode* root, int n) {
    if (root == NULL)
        return;

    /*
       Minimum possible HD = -(n-1)
       Maximum possible HD = +(n-1)
    */
    int offset = n - 1;
    int size = 2 * n - 1;

    /*
       Each index represents one vertical line.
       Example:
       HD -2 -> index 0
       HD -1 -> index 1
       HD  0 -> index 2
    */
    int **columns = (int**)malloc(size * sizeof(int*));
    int *count = (int*)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        columns[i] = (int*)malloc(n * sizeof(int));
    }

    /*
       Queue stores:
       - node
       - horizontal distance
    */
    struct QueueNode* queue =
        (struct QueueNode*)malloc(n * sizeof(struct QueueNode));

    int front = 0, rear = 0;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    while (front < rear) {

        struct TreeNode* current = queue[front].node;
        int hd = queue[front].hd;
        front++;

        int index = hd + offset;

        columns[index][count[index]] = current->val;
        count[index]++;

        if (current->left != NULL) {
            queue[rear].node = current->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if (current->right != NULL) {
            queue[rear].node = current->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    /* Print from leftmost vertical line to rightmost */
    for (int i = 0; i < size; i++) {

        if (count[i] > 0) {

            for (int j = 0; j < count[i]; j++) {
                printf("%d", columns[i][j]);

                if (j < count[i] - 1)
                    printf(" ");
            }

            printf("\n");
        }
    }

    for (int i = 0; i < size; i++)
        free(columns[i]);

    free(columns);
    free(count);
    free(queue);
}

int main() {
    int n;

    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root, n);

    free(arr);

    return 0;
}