// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k
// Output:
// - Print the linked list elements after rotation, space-separated
// Example:
// Input:
// 5
// 10 20 30 40 50
// 2
// Output:
// 40 50 10 20 30
// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Rotate linked list to the right by k places
struct Node* rotateRight(struct Node *head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length and last node
    struct Node *last = head;
    int n = 1;

    while (last->next != NULL) {
        last = last->next;
        n++;
    }

    // If k is greater than length
    k = k % n;
    if (k == 0)
        return head;

    // Make circular linked list
    last->next = head;

    // Move to (n-k)th node
    struct Node *temp = head;
    for (int i = 1; i < n - k; i++) {
        temp = temp->next;
    }

    // New head
    head = temp->next;

    // Break the circle
    temp->next = NULL;

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
    int n, k, x;

    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        struct Node *newNode = createNode(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}