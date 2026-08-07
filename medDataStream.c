// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0


#include <stdio.h>

#define MAX 100000

// Max Heap (left half)
int maxHeap[MAX];
int maxSize = 0;

// Min Heap (right half)
int minHeap[MAX];
int minSize = 0;

// ---------- Max Heap ----------

void maxInsert(int val)
{
    int i = maxSize++;
    maxHeap[i] = val;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (maxHeap[parent] >= maxHeap[i])
            break;

        int temp = maxHeap[parent];
        maxHeap[parent] = maxHeap[i];
        maxHeap[i] = temp;

        i = parent;
    }
}

int maxPop()
{
    int ans = maxHeap[0];

    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;

        if (right < maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest == i)
            break;

        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;

        i = largest;
    }

    return ans;
}

// ---------- Min Heap ----------

void minInsert(int val)
{
    int i = minSize++;
    minHeap[i] = val;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (minHeap[parent] <= minHeap[i])
            break;

        int temp = minHeap[parent];
        minHeap[parent] = minHeap[i];
        minHeap[i] = temp;

        i = parent;
    }
}

int minPop()
{
    int ans = minHeap[0];

    minHeap[0] = minHeap[--minSize];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minSize && minHeap[left] < minHeap[smallest])
            smallest = left;

        if (right < minSize && minHeap[right] < minHeap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        int temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;

        i = smallest;
    }

    return ans;
}

// ---------- Add Number ----------

void addNum(int num)
{
    if (maxSize == 0 || num <= maxHeap[0])
        maxInsert(num);
    else
        minInsert(num);

    // Balance heaps
    if (maxSize > minSize + 1)
    {
        int x = maxPop();
        minInsert(x);
    }

    if (minSize > maxSize)
    {
        int x = minPop();
        maxInsert(x);
    }
}

// ---------- Find Median ----------

double findMedian()
{
    if (maxSize > minSize)
        return maxHeap[0];

    return (maxHeap[0] + minHeap[0]) / 2.0;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        addNum(x);

        printf("Median after inserting %d = %.1lf\n", x, findMedian());
    }

    return 0;
}