// Problem Statement
// Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

// Determine the minimum time required to paint all boards.

// Input Format
// n k
// n space-separated integers representing board lengths

// Output Format
// Print the minimum time required to paint all boards.

// Sample Input
// 4 2
// 10 20 30 40

// Sample Output
// 60

// Explanation
// One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.


#include <stdio.h>

int canPaint(int boards[], int n, int k, long long maxTime) {
    int painters = 1;
    long long currentTime = 0;

    for (int i = 0; i < n; i++) {

        // If adding this board does not exceed maxTime
        if (currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        }
        else {
            // Give this board to a new painter
            painters++;
            currentTime = boards[i];

            // More painters than available
            if (painters > k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];

    long long sum = 0;
    int maxBoard = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);

        sum += boards[i];

        if (boards[i] > maxBoard) {
            maxBoard = boards[i];
        }
    }

    // Minimum possible answer = largest board
    long long low = maxBoard;

    // Maximum possible answer = total length
    long long high = sum;

    long long answer = high;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            // This time is possible.
            // Try to find an even smaller time.
            answer = mid;
            high = mid - 1;
        }
        else {
            // This time is not possible.
            // Need more time.
            low = mid + 1;
        }
    }

    printf("%lld\n", answer);

    return 0;
}