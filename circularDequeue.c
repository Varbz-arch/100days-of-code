
// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
// int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty, or false otherwise.
// boolean isFull() Returns true if the deque is full, or false otherwise.
 

// Example 1:

// Input
// ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
// [[3], [1], [2], [3], [4], [], [], [], [4], []]
// Output
// [null, true, true, true, false, 2, true, true, true, 4]

// Explanation
// MyCircularDeque myCircularDeque = new MyCircularDeque(3);
// myCircularDeque.insertLast(1);  // return True
// myCircularDeque.insertLast(2);  // return True
// myCircularDeque.insertFront(3); // return True
// myCircularDeque.insertFront(4); // return False, the queue is full.
// myCircularDeque.getRear();      // return 2
// myCircularDeque.isFull();       // return True
// myCircularDeque.deleteLast();   // return True
// myCircularDeque.insertFront(4); // return True
// myCircularDeque.getFront();     // return 4
 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} CircularDeque;

// Create Deque
CircularDeque* createDeque(int k) {
    CircularDeque *dq = (CircularDeque *)malloc(sizeof(CircularDeque));

    dq->arr = (int *)malloc(k * sizeof(int));
    dq->capacity = k;
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;

    return dq;
}

// Check Empty
int isEmpty(CircularDeque *dq) {
    return dq->size == 0;
}

// Check Full
int isFull(CircularDeque *dq) {
    return dq->size == dq->capacity;
}

// Insert at Front
void insertFront(CircularDeque *dq, int value) {

    if (isFull(dq)) {
        printf("Deque is Full\n");
        return;
    }

    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->arr[dq->front] = value;

    if (dq->size == 0)
        dq->rear = dq->front;

    dq->size++;

    printf("%d inserted at Front\n", value);
}

// Insert at Rear
void insertRear(CircularDeque *dq, int value) {

    if (isFull(dq)) {
        printf("Deque is Full\n");
        return;
    }

    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->arr[dq->rear] = value;

    if (dq->size == 0)
        dq->front = dq->rear;

    dq->size++;

    printf("%d inserted at Rear\n", value);
}

// Delete Front
void deleteFront(CircularDeque *dq) {

    if (isEmpty(dq)) {
        printf("Deque is Empty\n");
        return;
    }

    printf("%d deleted from Front\n", dq->arr[dq->front]);

    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;

    if (dq->size == 0) {
        dq->front = 0;
        dq->rear = -1;
    }
}

// Delete Rear
void deleteRear(CircularDeque *dq) {

    if (isEmpty(dq)) {
        printf("Deque is Empty\n");
        return;
    }

    printf("%d deleted from Rear\n", dq->arr[dq->rear]);

    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->size--;

    if (dq->size == 0) {
        dq->front = 0;
        dq->rear = -1;
    }
}

// Get Front
void getFront(CircularDeque *dq) {

    if (isEmpty(dq))
        printf("Deque is Empty\n");
    else
        printf("Front = %d\n", dq->arr[dq->front]);
}

// Get Rear
void getRear(CircularDeque *dq) {

    if (isEmpty(dq))
        printf("Deque is Empty\n");
    else
        printf("Rear = %d\n", dq->arr[dq->rear]);
}

// Display Deque
void display(CircularDeque *dq) {

    if (isEmpty(dq)) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque: ");

    int i = dq->front;

    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % dq->capacity;
    }

    printf("\n");
}

// Free Memory
void freeDeque(CircularDeque *dq) {
    free(dq->arr);
    free(dq);
}

int main() {

    int k;

    printf("Enter capacity: ");
    scanf("%d", &k);

    CircularDeque *dq = createDeque(k);

    int choice, value;

    while (1) {

        printf("\n1.Insert Front");
        printf("\n2.Insert Rear");
        printf("\n3.Delete Front");
        printf("\n4.Delete Rear");
        printf("\n5.Get Front");
        printf("\n6.Get Rear");
        printf("\n7.Display");
        printf("\n8.Is Empty");
        printf("\n9.Is Full");
        printf("\n10.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(dq, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(dq, value);
                break;

            case 3:
                deleteFront(dq);
                break;

            case 4:
                deleteRear(dq);
                break;

            case 5:
                getFront(dq);
                break;

            case 6:
                getRear(dq);
                break;

            case 7:
                display(dq);
                break;

            case 8:
                if (isEmpty(dq))
                    printf("Deque is Empty\n");
                else
                    printf("Deque is Not Empty\n");
                break;

            case 9:
                if (isFull(dq))
                    printf("Deque is Full\n");
                else
                    printf("Deque is Not Full\n");
                break;

            case 10:
                freeDeque(dq);
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
