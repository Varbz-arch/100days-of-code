// You are given an array nums with n objects colored red, white, or blue, sort them in-place so that 
// objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]

// Output: [0,0,1,1,2,2]

// Explanation:

// The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.

#include <stdio.h>

// Function to sort colors
void sortColors(int nums[], int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {

        if (nums[mid] == 0) {
            // Swap nums[low] and nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;

            low++;
            mid++;
        }

        else if (nums[mid] == 1) {
            // 1 is already in the correct position
            mid++;
        }

        else {  // nums[mid] == 2
            // Swap nums[mid] and nums[high]
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;

            high--;
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements (0, 1, 2): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Sort the array
    sortColors(nums, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}