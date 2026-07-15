// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3

// #include <stdio.h>

// int main() {
//     int n, k;

//     scanf("%d", &n);

//     int arr[n];

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     scanf("%d", &k);

//     k = k % n;   // Handle k greater than n

//     int temp[k];

//     // Store last k elements
//     for (int i = 0; i < k; i++) {
//         temp[i] = arr[n - k + i];
//     }

//     // Shift remaining elements to the right
//     for (int i = n - k - 1; i >= 0; i--) {
//         arr[i + k] = arr[i];
//     }

//     // Copy temp elements to the beginning
//     for (int i = 0; i < k; i++) {
//         arr[i] = temp[i];
//     }

//     // Print rotated array
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }


// Rotate array right by k positions using reversal:

// 1. Normalize k: k = k % n
// 2. Reverse entire array
// 3. Reverse first k elements
// 4. Reverse remaining n-k elements

// Key Points:
// - In-place rotation
// - Handle k > n
// - Three reverses achieve rotation
// 💻 Code Solution

#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    int arr[100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    
    k = k % n;
    
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
// ⏱️ Complexity Analysis
// Time Complexity: O(n)
// Space Complexity: O(1)