// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that 
// the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

#include <stdio.h>

int splitArray(int* nums, int numsSize, int k) {
    int low = 0;
    int high = 0;

    // Find largest element and total sum
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low) {
            low = nums[i];
        }

        high += nums[i];
    }

    // Binary search
    while (low < high) {
        int mid = low + (high - low) / 2;

        int subarrays = 1;
        int currentSum = 0;

        // Check how many subarrays are needed
        for (int i = 0; i < numsSize; i++) {

            if (currentSum + nums[i] <= mid) {
                currentSum += nums[i];
            }
            else {
                // Start a new subarray
                subarrays++;
                currentSum = nums[i];
            }
        }

        // Too many subarrays
        if (subarrays > k) {
            low = mid + 1;
        }
        else {
            // mid is possible, try smaller
            high = mid;
        }
    }

    return low;
}

int main() {
    int nums[] = {7, 2, 5, 10, 8};
    int numsSize = 5;
    int k = 2;

    int answer = splitArray(nums, numsSize, k);

    printf("Minimum largest sum = %d\n", answer);

    return 0;
}