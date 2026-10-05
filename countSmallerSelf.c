// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements 
// to the right of nums[i].

 

// Example 1:

// Input: nums = [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.

#include <stdio.h>
#include <stdlib.h>

void merge(int nums[], int index[], int tempIndex[],
           int counts[], int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = left;
    int smallerRight = 0;

    while (i <= mid && j <= right) {

        if (nums[index[j]] < nums[index[i]]) {
            // Right element is smaller
            tempIndex[k++] = index[j++];
            smallerRight++;
        }
        else {
            // All previously taken right elements
            // are smaller than nums[index[i]]
            counts[index[i]] += smallerRight;

            tempIndex[k++] = index[i++];
        }
    }

    // Remaining left elements
    while (i <= mid) {
        counts[index[i]] += smallerRight;
        tempIndex[k++] = index[i++];
    }

    // Remaining right elements
    while (j <= right) {
        tempIndex[k++] = index[j++];
    }

    // Copy back
    for (i = left; i <= right; i++) {
        index[i] = tempIndex[i];
    }
}

void mergeSort(int nums[], int index[], int tempIndex[],
               int counts[], int left, int right) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, index, tempIndex, counts, left, mid);
    mergeSort(nums, index, tempIndex, counts, mid + 1, right);

    merge(nums, index, tempIndex, counts, left, mid, right);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {

    int* counts = calloc(numsSize, sizeof(int));
    int* index = malloc(numsSize * sizeof(int));
    int* tempIndex = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        index[i] = i;
    }

    mergeSort(nums, index, tempIndex, counts, 0, numsSize - 1);

    free(index);
    free(tempIndex);

    *returnSize = numsSize;
    return counts;
}

int main() {

    int nums[] = {5, 2, 6, 1};
    int n = 4;

    int returnSize;

    int* counts = countSmaller(nums, n, &returnSize);

    printf("[");

    for (int i = 0; i < returnSize; i++) {
        printf("%d", counts[i]);

        if (i < returnSize - 1)
            printf(", ");
    }

    printf("]\n");

    free(counts);

    return 0;
}