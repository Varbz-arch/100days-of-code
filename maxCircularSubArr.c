// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums. 
// A circular array means the end of the array connects to the beginning of the array. 
// Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n]. 
// A subarray may only include each element of the fixed buffer nums at most once. Formally, 
// for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n. 
// Example 1: Input: nums = [1,-2,3,-2] 
// Output: 3 
// Explanation: Subarray [3] has maximum sum 3.

#include <stdio.h>

int maxSubarraySumCircular(int nums[], int n)
{
    int totalSum = 0;

    int currentMax = nums[0];
    int maxSum = nums[0];

    int currentMin = nums[0];
    int minSum = nums[0];


    for(int i = 0; i < n; i++)
    {
        totalSum += nums[i];


        // Finding maximum subarray sum (Kadane)
        if(i != 0)
        {
            if(currentMax + nums[i] > nums[i])
                currentMax = currentMax + nums[i];
            else
                currentMax = nums[i];


            if(currentMax > maxSum)
                maxSum = currentMax;
        }



        // Finding minimum subarray sum
        if(i != 0)
        {
            if(currentMin + nums[i] < nums[i])
                currentMin = currentMin + nums[i];
            else
                currentMin = nums[i];


            if(currentMin < minSum)
                minSum = currentMin;
        }
    }


    // If all numbers are negative
    if(maxSum < 0)
        return maxSum;


    int circularSum = totalSum - minSum;


    if(maxSum > circularSum)
        return maxSum;
    else
        return circularSum;
}



int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d",&n);


    int nums[n];

    printf("Enter elements: ");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }


    int answer = maxSubarraySumCircular(nums,n);


    printf("Maximum circular subarray sum = %d",answer);


    return 0;
}