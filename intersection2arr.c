// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as 
// it shows in both arrays and you may return the result in any order.
// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

#include <stdio.h>

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int nums1[n1];

    for (int i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &n2);
    int nums2[n2];

    for (int i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    int result[n1];
    int k = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (nums1[i] == nums2[j]) {
                result[k++] = nums1[i];
                nums2[j] = -1;   // Mark as used
                break;
            }
        }
    }

    printf("Intersection: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}