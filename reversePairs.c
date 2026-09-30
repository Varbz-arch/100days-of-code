// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
 

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

#include <stdio.h>
#include <stdlib.h>

long long mergeSort(int nums[], int left, int right, int temp[]) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;
    long long count = 0;

    // Sort left half
    count += mergeSort(nums, left, mid, temp);

    // Sort right half
    count += mergeSort(nums, mid + 1, right, temp);

    // Count reverse pairs
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right &&
               (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }

        count += j - (mid + 1);
    }

    // Merge two sorted halves
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k] = nums[i];
            i++;
        } else {
            temp[k] = nums[j];
            j++;
        }
        k++;
    }

    // Copy remaining left elements
    while (i <= mid) {
        temp[k] = nums[i];
        i++;
        k++;
    }

    // Copy remaining right elements
    while (j <= right) {
        temp[k] = nums[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return count;
}

int reversePairs(int nums[], int numsSize) {
    if (numsSize < 2)
        return 0;

    int* temp = (int*)malloc(numsSize * sizeof(int));

    long long count = mergeSort(nums, 0, numsSize - 1, temp);

    free(temp);

    return (int)count;
}

int main() {
    int nums[] = {1, 3, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = reversePairs(nums, n);

    printf("Number of reverse pairs = %d\n", result);

    return 0;
}