// Problem: Count Nodes in Linked List
// Input:
// - First line: integer n
// - Second line: n space-separated integers
// Output:
// - Print the result
// Example:
// Input:
// 5
// 10 20 30 40 50
// Output:
// 10 20 30 40 50

// #include <stdio.h>
// #include <stdlib.h>

// // Structure for a node
// struct Node
// {
//     int data;
//     struct Node *next;
// };

// int main()
// {
//     int n;

//     scanf("%d", &n);

//     struct Node *head = NULL;
//     struct Node *temp = NULL;
//     struct Node *newNode = NULL;

//     // Create the linked list
//     for (int i = 0; i < n; i++)
//     {
//         newNode = (struct Node *)malloc(sizeof(struct Node));

//         scanf("%d", &newNode->data);
//         newNode->next = NULL;

//         if (head == NULL)
//         {
//             head = newNode;
//             temp = head;
//         }
//         else
//         {
//             temp->next = newNode;
//             temp = newNode;
//         }
//     }

//     // Traverse and count and print the linked list
//     int count = 0;
//     temp = head;

//     while (temp != NULL)
//     {
//         count++;
//         printf("%d \n", temp->data);
//         temp = temp->next;
//     }
//     printf("%d \n", count);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, value;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    printf("%d\n", countNodes(head));
    return 0;
}