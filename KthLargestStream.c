// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

// Implement the KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
// int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

// Example 1:

// Input:
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

// Output: [null, 4, 5, 5, 8, 8]

// Explanation:

// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3); // return 4
// kthLargest.add(5); // return 5
// kthLargest.add(10); // return 5
// kthLargest.add(9); // return 8
// kthLargest.add(4); // return 8

#include <stdio.h>

#define MAX 10000

int heap[MAX];
int size = 0;
int k;

// Heapify Up
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

// Heapify Down
void heapifyDown(int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

// Insert into Min Heap
void insert(int value) {
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
}

// Remove Minimum
void removeMin() {
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Add a new score and return kth largest
int add(int value) {
    insert(value);

    if (size > k)
        removeMin();

    return heap[0];
}

int main() {
    int n;

    scanf("%d", &k);   // kth largest
    scanf("%d", &n);   // initial number of elements

    // Read initial scores
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(x);

        if (size > k)
            removeMin();
    }

    int q;
    scanf("%d", &q);   // number of new scores

    while (q--) {
        int val;
        scanf("%d", &val);

        printf("%d\n", add(val));
    }

    return 0;
}