// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add two numbers represented by linked lists
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node *dummy = createNode(0);
    struct Node *current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;

        current->next = createNode(sum % 10);
        current = current->next;
    }

    struct Node *result = dummy->next;
    free(dummy);

    return result;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, x;

    // First linked list
    scanf("%d", &n1);
    struct Node *l1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        struct Node *newNode = createNode(x);

        if (l1 == NULL) {
            l1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    // Second linked list
    scanf("%d", &n2);
    struct Node *l2 = NULL, *tail2 = NULL;

    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        struct Node *newNode = createNode(x);

        if (l2 == NULL) {
            l2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node *result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}