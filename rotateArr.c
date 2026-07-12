// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

#include <stdio.h>

int main()
{
    int n, k;

    scanf("%d", &n);

    int nums[n];
    int temp[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    k = k % n;

    for(int i = 0; i < n; i++)
    {
        int newIndex = (i + k) % n;
        temp[newIndex] = nums[i];
    }

    for(int i = 0; i < n; i++)
        nums[i] = temp[i];

    printf("Rotated Array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}