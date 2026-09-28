// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
//  Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

// Example 1:

// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// Output: [2,2,2,1,4,3,3,9,6,7,19]
// Example 2:

// Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
// Output: [22,28,8,6,17,44]


#include <stdio.h>

int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    int arr2[] = {2, 1, 4, 3, 9, 6};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int freq[100] = {0};

    // Step 1: Count frequency of elements in arr1
    for (int i = 0; i < n1; i++) {
        freq[arr1[i]]++;
    }

    printf("Output: [");

    int first = 1;

    // Step 2: Follow the ordering of arr2
    for (int i = 0; i < n2; i++) {
        int value = arr2[i];

        while (freq[value] > 0) {
            if (!first)
                printf(",");

            printf("%d", value);
            first = 0;

            freq[value]--;
        }
    }

    // Step 3: Remaining elements in ascending order
    for (int value = 0; value < 100; value++) {
        while (freq[value] > 0) {
            if (!first)
                printf(",");

            printf("%d", value);
            first = 0;

            freq[value]--;
        }
    }

    printf("]\n");

    return 0;
}