// Given an array of integers nums which is sorted in ascending order, and an integer target, 
// write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.
// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

#include <iostream>
using namespace std;

// Binary Search function
int binarySearch(int nums[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        // Find middle index
        int mid = left + (right - left) / 2;

        // Target found
        if (nums[mid] == target) {
            return mid;
        }

        // Target is greater, search right half
        else if (nums[mid] < target) {
            left = mid + 1;
        }

        // Target is smaller, search left half
        else {
            right = mid - 1;
        }
    }

    // Target not found
    return -1;
}

int main() {
    int n;

    // Input size
    cin >> n;

    int nums[n];

    // Input sorted array
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    // Perform binary search
    int result = binarySearch(nums, n, target);

    // Output result
    cout << result << endl;

    return 0;
}