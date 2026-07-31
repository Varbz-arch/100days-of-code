// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
// Implement the MyQueue class:
// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:
// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
// Example 1:
// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]
// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue using two stacks
typedef struct {
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} MyQueue;

// Initialize Queue
void initialize(MyQueue *q) {
    q->top1 = -1;
    q->top2 = -1;
}

// Push into queue
void push(MyQueue *q, int x) {
    if (q->top1 == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->stack1[++q->top1] = x;
}

// Transfer elements from stack1 to stack2
void transfer(MyQueue *q) {
    if (q->top2 == -1) {
        while (q->top1 != -1) {
            q->stack2[++q->top2] = q->stack1[q->top1--];
        }
    }
}

// Pop front element
int pop(MyQueue *q) {
    transfer(q);

    if (q->top2 == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    return q->stack2[q->top2--];
}

// Peek front element
int peek(MyQueue *q) {
    transfer(q);

    if (q->top2 == -1) {
        printf("Queue is Empty\n");
        return -1;
    }

    return q->stack2[q->top2];
}

// Check if queue is empty
int empty(MyQueue *q) {
    return (q->top1 == -1 && q->top2 == -1);
}

int main() {
    MyQueue q;
    initialize(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);

    printf("Front element: %d\n", peek(&q));

    printf("Deleted: %d\n", pop(&q));

    printf("Front element: %d\n", peek(&q));

    if (empty(&q))
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");

    return 0;
}