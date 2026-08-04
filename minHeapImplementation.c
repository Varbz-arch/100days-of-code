// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30


#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);

        index = parent;
    }
}

// Heapify Down
void heapifyDown(int index)
{
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);

        index = smallest;
    }
}

// Insert
void insert(int value)
{
    if (size == MAX)
        return;

    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Peek
int peek()
{
    if (size == 0)
        return -1;

    return heap[0];
}

// Extract Minimum
int extractMin()
{
    if (size == 0)
        return -1;

    int min = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'i')
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'p')
        {
            printf("%d\n", peek());
        }
        else
        {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}