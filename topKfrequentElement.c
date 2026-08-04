// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2

// Output: [1,2]

// Example 2:

// Input: nums = [1], k = 1

// Output: [1]

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

// Comparator for qsort (descending frequency)
int cmp(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return p2->freq - p1->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    int freq[20001] = {0};

    // Count frequencies
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 10000]++;
    }

    // Store unique numbers and their frequencies
    Pair *arr = (Pair *)malloc(sizeof(Pair) * numsSize);
    int count = 0;

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            arr[count].num = i - 10000;
            arr[count].freq = freq[i];
            count++;
        }
    }

    // Sort by frequency
    qsort(arr, count, sizeof(Pair), cmp);

    // Store answer
    int *ans = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++) {
        ans[i] = arr[i].num;
    }

    *returnSize = k;

    free(arr);

    return ans;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int returnSize;

    int *result = topKFrequent(nums, n, k, &returnSize);

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(result);

    return 0;
}