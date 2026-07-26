// You are given two non-empty linked lists representing two non-negative integers. 
// The most significant digit comes first and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example 1:
// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Add two numbers
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {

    int stack1[100], stack2[100];
    int top1 = -1, top2 = -1;

    while (l1 != NULL) {
        stack1[++top1] = l1->data;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        stack2[++top2] = l2->data;
        l2 = l2->next;
    }

    int carry = 0;
    struct Node* head = NULL;

    while (top1 >= 0 || top2 >= 0 || carry) {

        int sum = carry;

        if (top1 >= 0)
            sum += stack1[top1--];

        if (top2 >= 0)
            sum += stack2[top2--];

        struct Node* newNode = createNode(sum % 10);

        // Insert at front
        newNode->next = head;
        head = newNode;

        carry = sum / 10;
    }

    return head;
}

int main() {

    struct Node *l1 = NULL, *l2 = NULL;

    int n1, n2, x;

    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        insertEnd(&l1, x);
    }

    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        insertEnd(&l2, x);
    }

    struct Node* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}