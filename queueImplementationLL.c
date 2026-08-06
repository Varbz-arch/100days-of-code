// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL;
Node *rear = NULL;

// Enqueue operation
void enqueue(int x) {

    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = x;
    newNode->next = NULL;

    // If queue is empty
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {

    if (front == NULL) {
        printf("-1\n");
        return;
    }

    Node *temp = front;

    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {

    int N;
    scanf("%d", &N);

    while (N--) {

        char op[20];

        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {

            int x;
            scanf("%d", &x);

            enqueue(x);
        }
        else if (strcmp(op, "dequeue") == 0) {
            dequeue();
        }
    }

    return 0;
}