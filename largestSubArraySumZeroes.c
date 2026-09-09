// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int sum;
    int index;
};

int longestZeroSumSubarray(int arr[], int n) {
    struct Pair map[n + 1];

    int sum = 0;
    int maxLen = 0;
    int size = 0;

    // Store prefix sum 0 at index -1
    map[size].sum = 0;
    map[size].index = -1;
    size++;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int found = -1;

        // Check if prefix sum already exists
        for (int j = 0; j < size; j++) {
            if (map[j].sum == sum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int len = i - map[found].index;

            if (len > maxLen)
                maxLen = len;
        } else {
            // Store only the FIRST occurrence
            map[size].sum = sum;
            map[size].index = i;
            size++;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {-2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", longestZeroSumSubarray(arr, n));

    return 0;
}