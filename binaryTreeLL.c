// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// Example 1:
// image

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]


// Example 2:

// Input: root = []
// Output: []

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

// Build binary tree from level-order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode** queue =
        (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    int front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct TreeNode* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Flatten binary tree into linked list
void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    // Flatten left subtree
    flatten(root->left);

    // Flatten right subtree
    flatten(root->right);

    // Store original right subtree
    struct TreeNode* temp = root->right;

    // Move left subtree to right
    root->right = root->left;
    root->left = NULL;

    // Find the end of the flattened left subtree
    struct TreeNode* curr = root;

    while (curr->right != NULL)
        curr = curr->right;

    // Attach original right subtree
    curr->right = temp;
}

// Print flattened tree
void printFlattened(struct TreeNode* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
}

// Free memory
void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* next = root->right;

    free(root);

    freeTree(next);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter level-order traversal (-1 for NULL):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build tree
    struct TreeNode* root = buildTree(arr, n);

    // Flatten tree
    flatten(root);

    // Print flattened tree
    printf("Flattened tree: ");
    printFlattened(root);

    // Free memory
    freeTree(root);
    free(arr);

    return 0;
}