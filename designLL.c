// Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
// A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
// If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
// Implement the MyLinkedList class:
// MyLinkedList() Initializes the MyLinkedList object.
// int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
// void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
// void addAtTail(int val) Append a node of value val as the last element of the linked list.
// void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
// void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
// Example 1:
// Input
// ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
// [[], [1], [3], [1, 2], [1], [1], [1]]
// Output
// [null, null, null, null, 2, null, 3]

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;


typedef struct {
    Node *head;
    int size;
} MyLinkedList;


// Create Linked List
MyLinkedList* myLinkedListCreate() {

    MyLinkedList *obj = malloc(sizeof(MyLinkedList));

    obj->head = NULL;
    obj->size = 0;

    return obj;
}


// Get value at index
int myLinkedListGet(MyLinkedList* obj, int index) {

    if(index < 0 || index >= obj->size)
        return -1;

    Node *temp = obj->head;

    for(int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}


// Add at head
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

    Node *newNode = malloc(sizeof(Node));

    newNode->val = val;
    newNode->next = obj->head;

    obj->head = newNode;
    obj->size++;
}


// Add at tail
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

    Node *newNode = malloc(sizeof(Node));

    newNode->val = val;
    newNode->next = NULL;


    if(obj->head == NULL) {
        obj->head = newNode;
    }

    else {

        Node *temp = obj->head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    obj->size++;
}


// Add at index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if(index < 0 || index > obj->size)
        return;


    Node *newNode = malloc(sizeof(Node));

    newNode->val = val;


    if(index == 0) {

        newNode->next = obj->head;
        obj->head = newNode;
    }

    else {

        Node *temp = obj->head;

        for(int i = 0; i < index - 1; i++)
            temp = temp->next;


        newNode->next = temp->next;
        temp->next = newNode;
    }

    obj->size++;
}


// Delete at index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

    if(index < 0 || index >= obj->size)
        return;


    Node *temp;


    if(index == 0) {

        temp = obj->head;

        obj->head = obj->head->next;

        free(temp);
    }

    else {

        Node *prev = obj->head;


        for(int i = 0; i < index - 1; i++)
            prev = prev->next;


        temp = prev->next;

        prev->next = temp->next;

        free(temp);
    }


    obj->size--;
}


// Free memory
void myLinkedListFree(MyLinkedList* obj) {

    Node *temp = obj->head;


    while(temp != NULL) {

        Node *next = temp->next;

        free(temp);

        temp = next;
    }


    free(obj);
}


// Display Linked List (Extra for VS Code)
void display(MyLinkedList *obj) {

    Node *temp = obj->head;

    while(temp != NULL) {

        printf("%d ", temp->val);
        temp = temp->next;
    }

    printf("\n");
}


// Driver Code
int main() {

    MyLinkedList *obj = myLinkedListCreate();


    // Example:
    // []
    myLinkedListAddAtHead(obj, 1);

    // 1->3
    myLinkedListAddAtTail(obj, 3);

    // 1->2->3
    myLinkedListAddAtIndex(obj, 1, 2);


    printf("Linked List: ");
    display(obj);


    printf("Value at index 1: ");
    printf("%d\n", myLinkedListGet(obj, 1));


    // Delete index 1
    myLinkedListDeleteAtIndex(obj, 1);


    printf("After deletion: ");
    display(obj);


    myLinkedListFree(obj);


    return 0;
}