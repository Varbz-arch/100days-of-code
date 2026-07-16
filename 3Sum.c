// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. 
// Notice that the solution set must not contain duplicate triplets. 
// Example 1: Input: nums = [-1,0,1,2,-1,-4]
//  Output: [[-1,-1,2],[-1,0,1]] 
//  Explanation: nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0. 
//  nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0. 
//  nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0. 
//  The distinct triplets are [-1,0,1] and [-1,-1,2]. 
//  Notice that the order of the output and the order of the triplets does not matter.


#include <stdio.h>

int main() {
    int arr[] = {-1, 0, 1, 2, -1, -4};
    int n = 6;

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {

                if(arr[i] + arr[j] + arr[k] == 0) {
                    printf("%d %d %d\n", arr[i], arr[j], arr[k]);
                }

            }
        }
    }

    return 0;
}