// You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the 
// insertion. It is guaranteed that the new value does not exist in the original BST.

// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion.
// You can return any of them.

 

// Example 1:


// Input: root = [4,2,7,1,3], val = 5
// Output: [4,2,7,1,3,5]
// Explanation: Another accepted tree is:

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

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {

    // If empty position is found, create a new node
    if (root == NULL) {
        return createNode(val);
    }

    // Insert into left subtree
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }

    // Insert into right subtree
    else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {

    struct TreeNode* root = NULL;
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertIntoBST(root, val);
    }

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}
