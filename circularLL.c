// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n
// - Second line: n space-separated integers
// Output:
// - Print the circular linked list elements starting from head, space-separated
// Example:
// Input:
// 5
// 10 20 30 40 50
// Output:
// 10 20 30 40 50
// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n;

    scanf("%d", &n);

    if (n == 0)
        return 0;

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create first node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    head = newNode;
    temp = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    // Make the list circular
    temp->next = head;

    // Traverse and print
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// void printCircular(struct Node* head, int n) {
//     if (head == NULL) return;
    
//     struct Node* current = head;
//     for (int i = 0; i < n; i++) {
//         printf("%d", current->data);
//         if (i < n - 1) printf(" ");
//         current = current->next;
//     }
//     printf("\n");
// }

// int main() {
//     int n, value;
//     struct Node* head = NULL;
//     struct Node* tail = NULL;
    
//     scanf("%d", &n);
    
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &value);
//         struct Node* newNode = createNode(value);
        
//         if (head == NULL) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }
    
//     // Make it circular
//     if (tail != NULL) {
//         tail->next = head;
//     }
    
//     printCircular(head, n);
//     return 0;
// }
