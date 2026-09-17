// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Target found
        if (nums[mid] == target) {
            return mid;
        }

        // Left half is sorted
        if (nums[low] <= nums[mid]) {

            // Target is in the sorted left half
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        // Right half is sorted
        else {

            // Target is in the sorted right half
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int nums[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int target;
    scanf("%d", &target);

    // Search and print result
    int result = search(nums, n, target);

    printf("%d\n", result);

    return 0;
}