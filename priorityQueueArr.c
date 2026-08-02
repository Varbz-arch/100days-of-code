// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.
// Supported Operations:
// - insert x
// - delete
// - peek
// Input Format:
// - First line contains integer N
// - Next N lines contain operations
// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty
// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek
// Output:
// 10
// 20

#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int value)
{
    if(size == MAX)
    {
        printf("Queue Full\n");
        return;
    }

    pq[size++] = value;
}

// Delete highest priority element (smallest value)
void deleteElement()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    printf("%d\n", pq[minIndex]);

    // Shift elements
    for(int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Peek highest priority element
void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    printf("%d\n", pq[minIndex]);
}

int main()
{
    int N;
    scanf("%d", &N);

    char operation[20];
    int value;

    for(int i = 0; i < N; i++)
    {
        scanf("%s", operation);

        if(strcmp(operation, "insert") == 0)
        {
            scanf("%d", &value);
            insert(value);
        }
        else if(strcmp(operation, "delete") == 0)
        {
            deleteElement();
        }
        else if(strcmp(operation, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}