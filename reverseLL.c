// Given the head of a singly linked list, reverse the list, and return the reversed list.
// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


// Reverse linked list function
struct Node* reverseList(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* curr = head;

    while(curr != NULL)
    {
        struct Node* next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}


// Print linked list
void printList(struct Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}


int main()
{
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;


    // Create linked list
    for(int i = 0; i < n; i++)
    {
        struct Node* newNode = malloc(sizeof(struct Node));

        scanf("%d", &newNode->data);
        newNode->next = NULL;


        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }


    // Reverse
    head = reverseList(head);


    // Print reversed list
    printList(head);


    return 0;
}