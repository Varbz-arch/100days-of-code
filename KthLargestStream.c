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

// #include <stdio.h>

// #define MAX 10000

// int heap[MAX];
// int size = 0;
// int k;

// // Heapify Up
// void heapifyUp(int index) {
//     while (index > 0) {
//         int parent = (index - 1) / 2;

//         if (heap[parent] <= heap[index])
//             break;

//         int temp = heap[parent];
//         heap[parent] = heap[index];
//         heap[index] = temp;

//         index = parent;
//     }
// }

// // Heapify Down
// void heapifyDown(int index) {
//     while (1) {
//         int smallest = index;
//         int left = 2 * index + 1;
//         int right = 2 * index + 2;

//         if (left < size && heap[left] < heap[smallest])
//             smallest = left;

//         if (right < size && heap[right] < heap[smallest])
//             smallest = right;

//         if (smallest == index)
//             break;

//         int temp = heap[index];
//         heap[index] = heap[smallest];
//         heap[smallest] = temp;

//         index = smallest;
//     }
// }

// // Insert into Min Heap
// void insert(int value) {
//     heap[size] = value;
//     size++;
//     heapifyUp(size - 1);
// }

// // Remove Minimum
// void removeMin() {
//     heap[0] = heap[size - 1];
//     size--;
//     heapifyDown(0);
// }

// // Add a new score and return kth largest
// int add(int value) {
//     insert(value);

//     if (size > k)
//         removeMin();

//     return heap[0];
// }

// int main() {
//     int n;

//     scanf("%d", &k);   // kth largest
//     scanf("%d", &n);   // initial number of elements

//     // Read initial scores
//     for (int i = 0; i < n; i++) {
//         int x;
//         scanf("%d", &x);
//         insert(x);

//         if (size > k)
//             removeMin();
//     }

//     int q;
//     scanf("%d", &q);   // number of new scores

//     while (q--) {
//         int val;
//         scanf("%d", &val);

//         printf("%d\n", add(val));
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
} MinHeap;


// Swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Create Min Heap
MinHeap* createMinHeap(int capacity) {

    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));

    h->heap = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;

    return h;
}


// Move element upward after insertion
void heapifyUp(MinHeap* h, int index) {

    while (index > 0) {

        int parent = (index - 1) / 2;

        if (h->heap[parent] <= h->heap[index])
            break;

        swap(&h->heap[parent], &h->heap[index]);

        index = parent;
    }
}


// Move element downward after replacement
void heapifyDown(MinHeap* h, int index) {

    while (1) {

        int smallest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;


        if (left < h->size &&
            h->heap[left] < h->heap[smallest])
        {
            smallest = left;
        }


        if (right < h->size &&
            h->heap[right] < h->heap[smallest])
        {
            smallest = right;
        }


        if (smallest == index)
            break;


        swap(&h->heap[index], &h->heap[smallest]);

        index = smallest;
    }
}


// Insert into Min Heap
void insertHeap(MinHeap* h, int val) {


    // Heap is not full
    if (h->size < h->capacity) {

        h->heap[h->size] = val;
        h->size++;

        heapifyUp(h, h->size - 1);
    }


    // Heap is full
    else if (val > h->heap[0]) {

        // Replace smallest element
        h->heap[0] = val;

        heapifyDown(h, 0);
    }
}


// Return kth largest
int getMin(MinHeap* h) {

    return h->heap[0];
}



// KthLargest structure
typedef struct {

    MinHeap* heap;

} KthLargest;



// Constructor
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {


    KthLargest* obj =
        (KthLargest*)malloc(sizeof(KthLargest));


    // Heap size is only k
    obj->heap = createMinHeap(k);



    // Add initial numbers
    for(int i = 0; i < numsSize; i++) {

        insertHeap(obj->heap, nums[i]);

    }


    return obj;
}



// Add new value
int kthLargestAdd(KthLargest* obj, int val) {


    insertHeap(obj->heap, val);


    // Root contains kth largest
    return getMin(obj->heap);
}



// Free memory
void kthLargestFree(KthLargest* obj) {

    free(obj->heap->heap);

    free(obj->heap);

    free(obj);
}




// Driver Code
int main() {


    int nums[] = {4, 5, 8, 2};

    int k = 3;


    int numsSize = sizeof(nums) / sizeof(nums[0]);


    KthLargest* obj =
        kthLargestCreate(k, nums, numsSize);



    printf("%d\n", kthLargestAdd(obj, 3));

    printf("%d\n", kthLargestAdd(obj, 5));

    printf("%d\n", kthLargestAdd(obj, 10));

    printf("%d\n", kthLargestAdd(obj, 9));

    printf("%d\n", kthLargestAdd(obj, 4));



    kthLargestFree(obj);


    return 0;
}