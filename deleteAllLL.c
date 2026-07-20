// Given the head of a linked list and an integer val, 
// remove all the nodes of the linked list that has Node.val == val, 
// and return the new head. 
// Example 1: Input: head = [1,2,6,3,4,5,6], val = 6 
// Output: [1,2,3,4,5]

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}


// Remove all nodes having value = val
struct Node* removeElements(struct Node* head, int val) {

    // Remove nodes from beginning
    while (head != NULL && head->data == val) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    struct Node *temp = head;
    struct Node *prev = NULL;


    while (temp != NULL) {

        if (temp->data == val) {

            prev->next = temp->next;
            free(temp);

            temp = prev->next;
        }

        else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}


// Print linked list
void printList(struct Node *head) {

    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}


int main() {

    int n;
    int value;
    int val;


    // number of nodes
    scanf("%d", &n);


    struct Node *head = NULL;
    struct Node *tail = NULL;


    // Creating linked list
    for(int i = 0; i < n; i++) {

        scanf("%d", &value);

        struct Node *newNode = createNode(value);


        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }

        else {
            tail->next = newNode;
            tail = newNode;
        }
    }


    // value to remove
    scanf("%d", &val);


    head = removeElements(head, val);


    printList(head);


    return 0;
}