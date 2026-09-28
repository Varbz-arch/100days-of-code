// Problem: Sort array of non-negative integers using counting sort.
// Find max, build freq array, compute prefix sums, build output.

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d non-negative integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 1. Find maximum element
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // 2. Create frequency array
    int freq[max + 1];

    for (int i = 0; i <= max; i++) {
        freq[i] = 0;
    }

    // Count frequency of each number
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // 3. Compute prefix sums
    for (int i = 1; i <= max; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }

    // 4. Build output array
    int output[n];

    // Traverse from right to left to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    // 5. Copy output back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Print sorted array
    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}