# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.
# Example 1:
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
# Example 2:
# Input: nums = [3,2,4], target = 6
# Output: [1,2]
# Example 3:
# Input: nums = [3,3], target = 6
#  Output: [0,1]

def twoSum(nums, target):
    seen = {}

    for i, num in enumerate(nums):
        complement = target - num

        if complement in seen:
            return [seen[complement], i]

        seen[num] = i

print(twoSum([2,7,11,15], 9))

# #include <stdio.h>
# #include <stdlib.h>

# int compare(const void *a, const void *b)
# {
#     return (*(int *)a - *(int *)b);
# }


# int main()
# {
#     int nums[] = {-1, 0, 1, 2, -1, -4};
#     int n = 6;

#     int target = 1;


#     // Step 1: Sort array
#     qsort(nums, n, sizeof(int), compare);


#     // Step 2: Two pointers
#     int left = 0;
#     int right = n - 1;


#     while(left < right)
#     {
#         int sum = nums[left] + nums[right];


#         if(sum == target)
#         {
#             printf("%d %d\n", nums[left], nums[right]);
#             break;
#         }


#         else if(sum < target)
#         {
#             // Need a bigger number
#             left++;
#         }


#         else
#         {
#             // Need a smaller number
#             right--;
#         }
#     }


#     return 0;
# }
