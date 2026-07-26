// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)
// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50
// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0
// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50
// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node **head, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Print polynomial
void printPolynomial(struct Node *head) {
    while (head != NULL) {
        if (head->exp == 0)
            printf("%d", head->coeff);
        else if (head->exp == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }
}

int main() {
    int n, coeff, exp;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}