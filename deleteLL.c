// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key
// Output:
// - Print the linked list elements after deletion, space-separated
// Example:
// Input:
// 5
// 10 20 30 40 50
// 30
// Output:
// 10 20 40 50
// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Delete first occurrence of key
struct Node* deleteNode(struct Node *head, int key) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    // If head itself contains the key
    if (head != NULL && head->data == key) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Key not found
    if (temp == NULL)
        return head;

    // Remove the node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Print linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, value, key;

    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct Node *newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &key);

    head = deleteNode(head, key);

    printList(head);

    return 0;
}