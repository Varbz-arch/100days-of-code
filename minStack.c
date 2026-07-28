// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// Implement the MinStack class:
// MinStack() initializes the stack object.
// void push(int value) pushes the element value onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// Example 1:
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
// Output
// [null,null,null,null,-3,null,0,-2]
// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// MinStack structure
typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;

// Initialize stack
void init(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}

// Push operation
void push(MinStack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    s->stack[++s->top] = value;

    if (s->minTop == -1 || value <= s->minStack[s->minTop]) {
        s->minStack[++s->minTop] = value;
    }
}

// Pop operation
void pop(MinStack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    if (s->stack[s->top] == s->minStack[s->minTop]) {
        s->minTop--;
    }

    s->top--;
}

// Top element
int top(MinStack *s) {
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->stack[s->top];
}

// Minimum element
int getMin(MinStack *s) {
    if (s->minTop == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->minStack[s->minTop];
}

// Display stack
void display(MinStack *s) {
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

int main() {
    MinStack s;
    init(&s);

    push(&s, -2);
    push(&s, 0);
    push(&s, -3);

    display(&s);

    printf("Minimum = %d\n", getMin(&s));

    pop(&s);

    printf("Top = %d\n", top(&s));
    printf("Minimum = %d\n", getMin(&s));

    return 0;
}