// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)
// Output:
// - Print value of intersection node or 'No Intersection'
// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50
// Output:
// 30
// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Length of linked list
int length(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Check whether remaining lists are identical
int sameList(struct Node *a, struct Node *b) {
    while (a != NULL && b != NULL) {
        if (a->data != b->data)
            return 0;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

// Find intersection
void findIntersection(struct Node *head1, struct Node *head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    int diff;

    if (len1 > len2) {
        diff = len1 - len2;
        while (diff--)
            head1 = head1->next;
    } else {
        diff = len2 - len1;
        while (diff--)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data && sameList(head1, head2)) {
            printf("%d\n", head1->data);
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        insertEnd(&head2, x);
    }

    findIntersection(head1, head2);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// int getLength(struct Node* head) {
//     int len = 0;
//     while (head != NULL) {
//         len++;
//         head = head->next;
//     }
//     return len;
// }

// struct Node* findIntersection(struct Node* head1, struct Node* head2) {
//     int len1 = getLength(head1);
//     int len2 = getLength(head2);
    
//     struct Node* ptr1 = head1;
//     struct Node* ptr2 = head2;
    
//     // Advance longer list
//     if (len1 > len2) {
//         for (int i = 0; i < len1 - len2; i++) {
//             ptr1 = ptr1->next;
//         }
//     } else {
//         for (int i = 0; i < len2 - len1; i++) {
//             ptr2 = ptr2->next;
//         }
//     }
    
//     // Find intersection
//     while (ptr1 != NULL && ptr2 != NULL) {
//         if (ptr1->data == ptr2->data) {
//             return ptr1;
//         }
//         ptr1 = ptr1->next;
//         ptr2 = ptr2->next;
//     }
    
//     return NULL;
// }