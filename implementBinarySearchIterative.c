// Problem: Implement Binary Search Iterative - Implement the algorithm.

// Input:

// 5
// 12 22 25 34 64
// 34

// Output:

// Element found at index 3

#include <stdio.h>

int main() {
    int n, target;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    scanf("%d", &target);

    int low = 0;
    int high = n - 1;
    int found = -1;

    // Iterative Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            found = mid;
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found != -1)
        printf("Element found at index %d\n", found);
    else
        printf("Element not found\n");

    return 0;
}