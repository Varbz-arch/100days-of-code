// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int *ans = malloc((numsSize-k+1)*sizeof(int));

    int *deque = malloc(numsSize*sizeof(int));

    int front = 0;
    int rear = 0;

    int index = 0;


    for(int i=0;i<numsSize;i++)
    {

        // Remove elements outside window
        if(front < rear && deque[front] <= i-k)
        {
            front++;
        }


        // Remove smaller elements
        while(front < rear &&
              nums[deque[rear-1]] <= nums[i])
        {
            rear--;
        }


        // Add current index
        deque[rear++] = i;


        // Window formed
        if(i >= k-1)
        {
            ans[index++] = nums[deque[front]];
        }
    }


    *returnSize = index;

    free(deque);

    return ans;
}


int main()
{
    int nums[] = {1,3,-1,-3,5,3,6,7};

    int k = 3;

    int size;

    int *result = maxSlidingWindow(nums,8,k,&size);


    for(int i=0;i<size;i++)
    {
        printf("%d ",result[i]);
    }


    free(result);

    return 0;
}