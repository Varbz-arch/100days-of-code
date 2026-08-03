// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations

#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;


// Check empty
int isEmpty()
{
    return (front == -1);
}


// Check full
int isFull()
{
    return ((front == 0 && rear == MAX-1) || 
            (front == rear + 1));
}


// Insert at front
void push_front(int value)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)   // first element
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = MAX-1;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}


// Insert at rear
void push_back(int value)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}


// Delete from front
void pop_front()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}


// Delete from rear
void pop_back()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = MAX-1;
    }
    else
    {
        rear--;
    }
}


// Return front element
void getFront()
{
    if(isEmpty())
        printf("Deque Empty\n");
    else
        printf("Front: %d\n", deque[front]);
}


// Return rear element
void getBack()
{
    if(isEmpty())
        printf("Deque Empty\n");
    else
        printf("Back: %d\n", deque[rear]);
}


// Size of deque
int size()
{
    if(isEmpty())
        return 0;

    if(rear >= front)
        return rear-front+1;

    return MAX-front+rear+1;
}


// Display deque
void display()
{
    if(isEmpty())
    {
        printf("Deque Empty\n");
        return;
    }

    int i = front;

    while(1)
    {
        printf("%d ",deque[i]);

        if(i == rear)
            break;

        i = (i+1)%MAX;
    }

    printf("\n");
}



int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    getFront();
    getBack();

    printf("Size: %d\n",size());

    pop_front();
    pop_back();

    display();

    return 0;
}