// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

#include <stdio.h>

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array
int partition(int nums[], int left, int right) {
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] >= pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }

    swap(&nums[i], &nums[right]);

    return i;
}

// Find kth largest
int findKthLargest(int nums[], int n, int k) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int pivotIndex = partition(nums, left, right);

        // Position of kth largest element
        if (pivotIndex == k - 1) {
            return nums[pivotIndex];
        }
        else if (pivotIndex > k - 1) {
            right = pivotIndex - 1;
        }
        else {
            left = pivotIndex + 1;
        }
    }

    return -1;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = findKthLargest(nums, n, k);

    printf("The %dth largest element is: %d\n", k, result);

    return 0;
}