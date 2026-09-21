// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
// The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4

#include <stdio.h>

int minEatingSpeed(int piles[], int n, int h) {
    int low = 1;
    int high = piles[0];

    // Find the maximum pile
    for (int i = 1; i < n; i++) {
        if (piles[i] > high) {
            high = piles[i];
        }
    }

    int answer = high;

    while (low <= high) {
        int k = low + (high - low) / 2;

        long long hours = 0;

        // Calculate hours needed at speed k
        for (int i = 0; i < n; i++) {
            hours += (piles[i] + k - 1) / k;
        }

        if (hours <= h) {
            // k is possible, try smaller
            answer = k;
            high = k - 1;
        } else {
            // k is too slow
            low = k + 1;
        }
    }

    return answer;
}

int main() {
    int n, h;

    // Input number of piles
    scanf("%d", &n);

    int piles[n];

    // Input piles
    for (int i = 0; i < n; i++) {
        scanf("%d", &piles[i]);
    }

    // Input number of hours
    scanf("%d", &h);

    // Find minimum eating speed
    int result = minEatingSpeed(piles, n, h);

    printf("%d\n", result);

    return 0;
}