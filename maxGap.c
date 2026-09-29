// Given an integer array nums, return the maximum difference between two successive elements in its sorted form.
//  If the array contains less than two elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra space.

 

// Example 1:

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int nums[], int numsSize) {

    if (numsSize < 2)
        return 0;

    if (numsSize == 2)
        return abs(nums[1] - nums[0]);

    int minVal = nums[0];
    int maxVal = nums[0];

    // Find minimum and maximum
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minVal)
            minVal = nums[i];

        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    // All elements are same
    if (minVal == maxVal)
        return 0;

    // Calculate bucket gap
    long long range = (long long)maxVal - minVal;

    long long gap =
        (range + numsSize - 2) / (numsSize - 1);

    int bucketCount = numsSize - 1;

    int *bucketMin = malloc(bucketCount * sizeof(int));
    int *bucketMax = malloc(bucketCount * sizeof(int));
    int *used = calloc(bucketCount, sizeof(int));

    // Initialize buckets
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Put elements into buckets
    for (int i = 0; i < numsSize; i++) {

        int index =
            (int)(((long long)nums[i] - minVal) / gap);

        if (index >= bucketCount)
            index = bucketCount - 1;

        if (!used[index]) {
            bucketMin[index] = nums[i];
            bucketMax[index] = nums[i];
            used[index] = 1;
        }
        else {
            if (nums[i] < bucketMin[index])
                bucketMin[index] = nums[i];

            if (nums[i] > bucketMax[index])
                bucketMax[index] = nums[i];
        }
    }

    // Find maximum gap
    int maxGap = 0;
    int previousMax = minVal;

    for (int i = 0; i < bucketCount; i++) {

        if (!used[i])
            continue;

        int currentGap = bucketMin[i] - previousMax;

        if (currentGap > maxGap)
            maxGap = currentGap;

        previousMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(used);

    return maxGap;
}

int main() {

    int nums[] = {3, 6, 9, 1};

    int n = sizeof(nums) / sizeof(nums[0]);

    int result = maximumGap(nums, n);

    printf("Maximum gap = %d\n", result);

    return 0;
}