// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls 
// if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], 
// Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls 
// is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

 

// Example 1:


// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. 
// The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

#include <stdio.h>
#include <stdlib.h>

// Function used by qsort() to sort positions
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Check if we can place m balls
// with at least 'distance' between them
int canPlace(int position[], int n, int m, int distance) {

    int count = 1;              // Place first ball
    int lastPosition = position[0];

    for (int i = 1; i < n; i++) {

        // If distance is enough, place another ball
        if (position[i] - lastPosition >= distance) {
            count++;
            lastPosition = position[i];

            // Successfully placed all balls
            if (count == m) {
                return 1;
            }
        }
    }

    return 0;
}

// Find maximum possible minimum distance
int maxDistance(int position[], int n, int m) {

    // Sort the positions
    qsort(position, n, sizeof(int), compare);

    int low = 1;
    int high = position[n - 1] - position[0];

    int answer = 0;

    // Binary Search
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (canPlace(position, n, m, mid)) {

            // mid is possible
            answer = mid;

            // Try for a bigger distance
            low = mid + 1;
        }
        else {

            // mid is not possible
            high = mid - 1;
        }
    }

    return answer;
}

int main() {

    int n, m;

    // Input n and m
    scanf("%d %d", &n, &m);

    int position[n];

    // Input positions
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    // Find maximum minimum force
    int result = maxDistance(position, n, m);

    // Print answer
    printf("%d\n", result);

    return 0;
}