// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int nums[], int numsSize)
{
    int *answer = (int *)malloc(numsSize * sizeof(int));

    int prefix = 1;

    // Prefix products
    for(int i = 0; i < numsSize; i++)
    {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;

    // Suffix products
    for(int i = numsSize - 1; i >= 0; i--)
    {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int *ans = productExceptSelf(nums, n);

    printf("Output: ");
    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    free(ans);

    return 0;
}