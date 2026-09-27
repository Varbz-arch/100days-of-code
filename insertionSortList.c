// Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

// The steps of the insertion sort algorithm:

// Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
// At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
// It repeats until no input elements remain.
// The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


 

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

// Insert a node at the end
void insertEnd(struct ListNode** head, int value) {
    struct ListNode* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct ListNode* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insertion Sort
struct ListNode* insertionSortList(struct ListNode* head) {

    // Dummy node for the sorted list
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* current = head;

    while (current != NULL) {

        // Save next node before changing links
        struct ListNode* nextNode = current->next;

        // Find correct position
        struct ListNode* prev = &dummy;

        while (prev->next != NULL &&
               prev->next->val < current->val) {
            prev = prev->next;
        }

        // Insert current node
        current->next = prev->next;
        prev->next = current;

        // Move to next original node
        current = nextNode;
    }

    return dummy.next;
}

// Print linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;

    while (temp != NULL) {
        printf("%d", temp->val);

        if (temp->next != NULL) {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {

    struct ListNode* head = NULL;

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        insertEnd(&head, value);
    }

    printf("\nOriginal list: ");
    printList(head);

    // Sort the linked list
    head = insertionSortList(head);

    printf("Sorted list:   ");
    printList(head);

    return 0;
}