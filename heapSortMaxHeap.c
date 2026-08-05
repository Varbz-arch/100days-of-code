// Implement Heap Sort using a Max Heap to sort an array in ascending order. 
// First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include <stdio.h>

// Swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Heapify affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}