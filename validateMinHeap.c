// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Check Min-Heap property
    for (int i = 0; i < N; i++) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < N && arr[i] > arr[left]) {
            printf("NO\n");
            return 0;
        }

        // Check right child
        if (right < N && arr[i] > arr[right]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}