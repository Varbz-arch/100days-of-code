// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int currentSum = nums[0];
    int maxSum = nums[0];

    int start = 0;
    int end = 0;
    int tempStart = 0;

    for(int i = 1; i < n; i++) {

        if(currentSum + nums[i] > nums[i]) {
            currentSum = currentSum + nums[i];
        }
        else {
            currentSum = nums[i];
            tempStart = i;   // new subarray starts here
        }

        if(currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    printf("Maximum subarray sum: %d\n", maxSum);

    printf("Subarray: ");
    for(int i = start; i <= end; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}